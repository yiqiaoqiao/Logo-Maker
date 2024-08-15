#include "LogoMaker.h"

LogoMaker::LogoMaker() {
    //isChanging = false;
    //Text input box
    textInput.setLabel("Logo Text");
    textInput.setLabelSize(30);
    textInput.setSize(1000,100);
    textInput.setLetterSize(80);
    textInput.setPosition(30,800);

    //Panel
    panel.setSize(2500, 700);
    panel.setPosition(0, menuBar.getGlobalBounds().height);
    panel.setTextMiddle();
    panel.setBackgroundColor(sf::Color::Black);
    panel.setFontSize(100);

    //Font Picker
    fontPicker.setText("Font Settings");
    fontPicker.setTextPosition(1100, 800);
    fontPicker.setPosition(1100, 850);
    fontPicker.setTextColor(true);

    //Background Picker
    //backgroundPicker.setSquareColor(sf::Color::Black);
    backgroundPicker.setText("Background Color");
    backgroundPicker.setTextPosition(2000, 870);
    backgroundPicker.setPosition(1850, 850);
    backgroundPicker.setTextColor(false);

    //Font List
    fontList.setPosition(1300, 850);

    //Rect
    botRect.setColor(sf::Color::Black);
    botRect.setSize(2500, 720);
    botRect.setPosition(0, panel.getGlobalBound().top+panel.getGlobalBound().height);
    topRect.setColor(sf::Color::Black);
    topRect.setSize(2500, menuBar.getGlobalBounds().height);
    topRect.setPosition(0,0);

    updatePanel();
    menuBar.resetMenu();
    filePath = "files/output.txt";
    texture.create(2500, 700);

    //Snapshot
    snapshot.setText(textInput.getString());
    snapshot.setTextColor(fontPicker.getColor());
    snapshot.setTextListColor(fontPicker.getListColor());
    snapshot.setBackgroundColor(backgroundPicker.getColor());
    snapshot.setBackgroundListColor(backgroundPicker.getListColor());
    snapshot.setFontName(fontList.getText());
    snapshot.setTextPosition(sliderList.getTextPosition());
    snapshot.setShadowPosition(sliderList.getShadowPosition());
    snapshot.setFontSize(sliderList.getFontSize());
    snapshot.setTextOpacity(sliderList.getTextOpacity());
    snapshot.setShadowOpacity(sliderList.getShadowOpacity());
    snapshot.setBackgroundOpacity(sliderList.getBackgroundOpacity());
    snapshot.setSkew(sliderList.getSkew());
    snapshot.setValue(0);
    History::pushHistory({snapshot, this});
    //std::cout << "History size: " << History::size() << std::endl;

}

void LogoMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(panel);
    window.draw(sprite);
    window.draw(topRect);
    window.draw(menuBar);
    window.draw(botRect);
    window.draw(textInput);
    window.draw(sliderList);
    window.draw(fontPicker);
    window.draw(backgroundPicker);
    window.draw(fontList);
}

void LogoMaker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    snapshot.setText(textInput.getString());
    snapshot.setTextColor(fontPicker.getColor());
    snapshot.setTextListColor(fontPicker.getListColor());
    snapshot.setBackgroundColor(backgroundPicker.getColor());
    snapshot.setBackgroundListColor(backgroundPicker.getListColor());
    snapshot.setFontName(fontList.getText());
    snapshot.setTextPosition(sliderList.getTextPosition());
    snapshot.setShadowPosition(sliderList.getShadowPosition());
    snapshot.setFontSize(sliderList.getFontSize());
    snapshot.setTextOpacity(sliderList.getTextOpacity());
    snapshot.setShadowOpacity(sliderList.getShadowOpacity());
    snapshot.setBackgroundOpacity(sliderList.getBackgroundOpacity());
    snapshot.setSkew(sliderList.getSkew());

    textInput.addEventHandler(window, event);
    menuBar.addEventHandler(window, event);
    sliderList.addEventHandler(window, event);
    fontPicker.addEventHandler(window, event);
    backgroundPicker.addEventHandler(window, event);
    fontList.addEventHandler(window, event);
    menuBarChoice(window);
    History::addEventHandler(window, event);
}

void LogoMaker::update() {
    textInput.update();
    menuBar.update();
    sliderList.update();
    fontPicker.update();
    backgroundPicker.update();
    fontList.update();
    updatePanel();
    updateTexture();
    //applySnapshot(History::topHistory().snapshot);
}

Snapshot &LogoMaker::getSnapshot() {
    return snapshot;
}

void LogoMaker::applySnapshot(const Snapshot &snapshot) {
    this->snapshot = snapshot;
    textInput.setText(snapshot.getText());
    fontPicker.setColor(snapshot.getTextListColor(), snapshot.getTextColor());
    backgroundPicker.setColor(snapshot.getBackgroundListColor(), snapshot.getBackgroundColor());
    fontList.setChoseText(snapshot.getFontName());
    sliderList.setTextPosition(snapshot.getTextPosition());
    sliderList.setFontSize(snapshot.getFontSize());
    sliderList.setTextOpacity(snapshot.getTextOpacity());
    sliderList.setBackgroundOpacity(snapshot.getBackgroundOpacity());
    sliderList.setShadowOpacity(snapshot.getShadowOpacity());
    sliderList.setSkew(snapshot.getSkew());
    sliderList.setShadowPosition(snapshot.getShadowPosition());
}

void LogoMaker::updatePanel() {
    panel.setText(textInput.getString());
    panel.setTextColor(fontPicker.getColor());
    panel.setBackgroundColor(backgroundPicker.getColor());
    panel.setFont(fontList.getText());
    //std::cout << fontList.getText() << std::endl;
    panel.setTextPosition(sliderList.getTextPosition().x, sliderList.getTextPosition().y);
    panel.setFontSize(sliderList.getFontSize());
    panel.setOpacity(sliderList.getTextOpacity(), sliderList.getShadowOpacity(),
                     sliderList.getBackgroundOpacity());
    panel.setSkew(sliderList.getSkew());
    panel.setShadowPosition(sliderList.getShadowPosition().x, sliderList.getShadowPosition().y);
    //snapshot = getSnapshot();
}

void LogoMaker::menuBarChoice(sf::RenderWindow &window) {
    //if(menuBar.isClicked())
        //std::cout << menuBar.getChosenMenu() << std::endl;
    std::string str = menuBar.getChosenMenu();
    if(str == "Quit")
        window.close();
    else if(str == "Export Image") {
        menuBar.setAllListHidden();
        exportImage();
    }
    else if(str == "New Project" || str == "Close Project") {
        filePath = "files/output.txt";
        menuBar.setAllListHidden();
        reset();
        History::pushHistory({snapshot, this});
    }
    else if(str == "Save Project") {
        menuBar.setAllListHidden();
        if(filePath == "files/output.txt")
            this->window.addFilePath("output");
        //std::cout << "Save Project: " << filePath << std::endl;
        History::pushHistory({snapshot, this});
        writeOutput();
    }
    else if(str == "Undo") {
        //std::cout << "Undo" << std::endl;
        History::undo();
    }
    else if(str == "Open Project") {
        //std::cout << "Open project" << std::endl;
        menuBar.setAllListHidden();
        this->window.runWindow();
        //std::cout << "Open Project: " << this->window.getFilePath() << std::endl;
        if(this->window.getFilePath() != "") {
            filePath = "files/" + this->window.getFilePath() + ".txt";
            setLogoMaker(filePath);
            History::pushHistory({snapshot, this});
        }
    }
    menuBar.resetMenu();
}

void LogoMaker::exportImage() {
    //std::cout << "Exporting Image" << std::endl;

    image = texture.getTexture().copyToImage();
    image.saveToFile("myImage.png");
}

void LogoMaker::reset() {
    //std::cout << "Reset" << std::endl;
    filePath = "files/output.txt";
    textInput.reset();
    sliderList.reset();
    fontPicker.reset();
    backgroundPicker.reset();
    fontList.reset();
}

void LogoMaker::writeOutput() {
    //std::cout << "write output" << std::endl;
    std::ofstream fout;
    sf::Color c;
    sf::Vector2f pos;
    fout.open(filePath);
    fout << panel.getString() << std::endl;
    c = panel.getTextColor();
    fout << (int)c.r << " " << (int)c.g  << " " << (int)c.b << std::endl;
    c = fontPicker.getListColor();
    fout << (int)c.r << " " << (int)c.g  << " " << (int)c.b << std::endl;
    //std::cout << c.r << " " << c.g  << " " << c.b << std::endl;
    c = panel.getBackgroundColor();
    fout << (int)c.r << " " << (int)c.g  << " " << (int)c.b << std::endl;
    c = backgroundPicker.getListColor();
    fout << (int)c.r << " " << (int)c.g  << " " << (int)c.b << std::endl;
    //std::cout << c.r << " " << c.g  << " " << c.b << std::endl;
    fout << panel.getFontName() << std::endl;
    pos = panel.getTextPosition();
    fout << pos.x << " " << pos.y << std::endl;
    //std::cout << "Pos: " << pos.x << ", " << pos.y << std::endl;
    fout << panel.getFontSize() << std::endl;
    fout << panel.getTextOpacity() << std::endl;
    fout << panel.getBackgroundOpacity() << std::endl;
    fout << panel.getShadowOpacity() << std::endl;
    fout << panel.getSkew() << std::endl;
    pos = panel.getShadowPosition();
    fout << pos.x << " " << pos.y << std::endl;
    fout.close();
}

void LogoMaker::updateTexture() {
    texture.clear(sf::Color::Transparent);
    texture.draw(panel.getPanel());
    texture.draw(panel.getText());
    texture.draw(panel.getShadow());
    texture.display();
    sprite.setTexture(texture.getTexture());
}

void LogoMaker::setLogoMaker(std::string filePath) {
    std::ifstream fin;
    fin.open(filePath);
    std::string line;
    int r, g, b;
    sf::Color c1;
    sf::Color c2;
    sf::Vector2f pos;
    float i;
    //Get text
    std::getline(fin, line);
    //std::cout << line << std::endl;
    textInput.setText(line);
    //Get Text Color
    fin >> r >> g >> b;
    //std::cout << r << " " << g << " " << b << std::endl;
    c1.r = r;
    c1.g = g;
    c1.b = b;
    fin >> r >> g >> b;
    c2.r = r;
    c2.g = g;
    c2.b = b;
    fontPicker.setColor(c2,c1);
    //Get Background color
    fin >> r >> g >> b;
    c1.r = r;
    c1.g = g;
    c1.b = b;
    fin >> r >> g >> b;
    c2.r = r;
    c2.g = g;
    c2.b = b;
    backgroundPicker.setColor(c2,c1);
    //Get font name
    std::getline(fin, line);
    std::getline(fin, line);
    fontList.setChoseText(line);
    //Get Text Position
    fin >> pos.x;
    fin >> pos.y;
    //pos.y += 50;
    //std::cout << "Get Pos: " << pos.x << ", " << pos.y << std::endl;
    sliderList.setTextPosition(pos);
    //Get Font Size
    fin >> r;
    //std::cout << "Font Size: " << r << std::endl;
    sliderList.setFontSize(r);
    //Get Text Opacity
    fin >> r;
    sliderList.setTextOpacity(r);
    //Get Background Opacity
    fin >> r;
    sliderList.setBackgroundOpacity(r);
    //Get Shadow Opacity
    fin >> r;
    sliderList.setShadowOpacity(r);
    //Get Skew
    fin >> i;
    sliderList.setSkew(i);
    //Get Shadow Position
    fin >> pos.x;
    fin >> pos.y;
    //pos.y += 50;
    sliderList.setShadowPosition(pos);
    fin.close();
}
