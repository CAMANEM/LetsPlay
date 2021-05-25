//
// Created by camanem on 12/5/21.
//

#include <iostream>
#include "Main_Window.h"
#include "spdlog/spdlog.h"
#include "Puzzle_Window.h"
#include "BPGame_Window.h"

Main_Window::Main_Window() {

}

void Main_Window::Run() {

    sf::RenderWindow window(sf::VideoMode(1100, 900), "Let's Play", sf::Style::Titlebar | sf::Style::Close  );
    my_window = &window;
    auto desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2i center(desktop.width / 4, -desktop.height / 2);
    window.setPosition(center);

    sf::Font font_t;
    sf::Font font_p;
    sf::Font font_b;
    sf::Text tittle;

    if (!font_t.loadFromFile("../Assets/Fonts/THINK_ME_WICKED_DEMO.ttf")){
        spdlog::error("Main_Window: loading tittle font");
    }
    if (!font_p.loadFromFile("../Assets/Fonts/Last Years Youth_DEMO.ttf")){
        spdlog::error("Main_Window: loading puzzle font");
    }
    if (!font_b.loadFromFile("../Assets/Fonts/Last Years Youth_DEMO.ttf")){
        spdlog::error("Main_Window: loading bpgame font");
    }

    tittle.setFont(font_t);
    tittle.setString("LETS PLAY");
    tittle.setCharacterSize(80);
    tittle.setPosition(420.0f, 150.0f);

    bpgame.setFont(font_b);
    bpgame.setString("BP GAME");
    bpgame.setCharacterSize(50);
    bpgame.setPosition(470.0f, 300.0f);

    puzzle.setFont(font_p);
    puzzle.setString("Gennetic Puzzle");
    puzzle.setCharacterSize(50);
    puzzle.setPosition(370.0f, 400.0f);


    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    window.close();

                case sf::Event::MouseMoved:
                    button_animation(sf::Mouse::getPosition(*my_window));

                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        clickButton(sf::Mouse::getPosition(*my_window));
                    }
            }
        }
        window.clear();
        window.draw(tittle);
        window.draw(bpgame);
        window.draw(puzzle);
        window.display();
    }
}

void Main_Window::button_animation(sf::Vector2i mouse_pos) {

    int x = mouse_pos.x;
    int y = mouse_pos.y;

    if (370 < x && x < 796 && 411 < y && y < 450){
        puzzle.setColor(sf::Color::Red);
        bpgame.setColor(sf::Color::White);

    }
    else if (470 < x && x < 667 && 300 < y && y < 360){
        bpgame.setColor(sf::Color::Cyan);
        puzzle.setColor(sf::Color::White);
    }
    else{
        puzzle.setColor(sf::Color::White);
        bpgame.setColor(sf::Color::White);
    }
}

void Main_Window::clickButton(sf::Vector2i mouse_pos) {

    int x = mouse_pos.x;
    int y = mouse_pos.y;

    if (370 < x && x < 796 && 411 < y && y < 450){
        Puzzle_Window* puzzleWindow = new Puzzle_Window();
        puzzleWindow->Run(my_window);
        free(puzzleWindow);
    }
    else if (470 < x && x < 667 && 300 < y && y < 360){
        BPGame_Window* bpGameWindow = new BPGame_Window();
        bpGameWindow->Run(my_window);
        free(bpGameWindow);
    }
}


