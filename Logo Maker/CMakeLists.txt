cmake_minimum_required(VERSION 3.20)
project(LogoMaker)

set(CMAKE_CXX_STANDARD 14)

add_executable(LogoMaker main.cpp ObjectStates.h States.cpp States.h MouseEvents.cpp MouseEvents.h
        EventHandler.h GUIComponents.h Snapshot.cpp Snapshot.h TextInput.cpp TextInput.h TextInputInfo.h Letter.h
        Letter.cpp LinkedList.cpp LinkedList.h LinkedList.cpp MultiText.cpp MultiText.h Node_iterator.cpp
        Node_iterator.h node.h History.cpp History.h HistoryNode.h KeyShortcuts.cpp KeyShortcuts.h SnapshotInterface.h
        Font.h Font.cpp Box.cpp Box.h Text.h Text.cpp LogoMaker.cpp LogoMaker.h InputBox.cpp InputBox.h Item.cpp Item.h
        ItemList.cpp ItemList.h Menu.cpp Menu.h MenuBar.cpp MenuBar.h Panel.cpp Panel.h Slider.cpp Slider.h
        SliderList.cpp SliderList.h ColorSquare.cpp ColorSquare.h ColorList.cpp ColorList.h ColorPicker.cpp
        ColorPicker.h FontList.cpp FontList.h ColorGradient.cpp ColorGradient.h Texture.cpp Texture.h Image.cpp Image.h
        Icon.cpp Icon.h FileTree.cpp FileTree.h FileNode.cpp FileNode.h FileItem.cpp FileItem.h Window.cpp Window.h)

target_link_libraries(LogoMaker sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)