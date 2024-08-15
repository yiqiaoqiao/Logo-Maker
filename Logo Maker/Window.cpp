#include "Window.h"

Window::Window() {
    window.setFramerateLimit(60);
    //File Tree
    fileTree.push("files", "Logo1", true);
    fileTree.push("files", "Logo2", true);
    sf::Color c(192,192,192);
    open.setBoxColor(c);
    cancel.setBoxColor(c);
    open.setTextColor(sf::Color::White);
    cancel.setTextColor(sf::Color::White);
    open.setBoxPosition(700, 650);
    cancel.setBoxPosition(950, 650);
    open.setBoxSize(200, 100);
    cancel.setBoxSize(200, 100);
    open.setText("Open");
    cancel.setText("Cancel");
    open.setTextPosition(730, 660);
}

void Window::runWindow(){
    //std::cout << "run Window" << std::endl;
    fileTree.reset();
    window.create({1200,800}, "Open");
    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            addEventHandler(window, event);
        }
        window.clear(sf::Color::Black);
        window.draw(fileTree);
        window.draw(open);
        window.draw(cancel);
        window.display();
    }
}

void Window::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    fileTree.addEventHandler(window, event);
    if(MouseEvents::mouseClicked(window, event)){
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        sf::FloatRect openB = open.getGlobalBounds();
        sf::FloatRect cancelB = cancel.getGlobalBounds();
        if(openB.contains(mousePos)){
            filePath = fileTree.clickedItem();
            //std::cout << "Open: " << s << std::endl;
            window.close();
        }
        else if(cancelB.contains(mousePos)){
            //std::cout << "Close" << std::endl;
            filePath = "";
            window.close();
        }
    }
}

std::string Window::getFilePath() {
    return filePath;
}

void Window::addFilePath(std::string s) {
    fileTree.push("files", s, true);
}
