//
// Created by camanem on 12/5/21.
//

#include "BPGame_Window.h"
#include "../Futbolin/Game.h"

BPGame_Window::BPGame_Window() {

}

void BPGame_Window::Run(sf::RenderWindow *_window) {

    bool back_button = false;


    sf::Event event;
//    Game game = Game(17,2);

    sf::Text goals;
    sf::Text players;

    sf::Text playbtn;
    sf::Text number;
    sf::Text down;
    sf::Text up;
    sf::Font font;

    sf::Text number2;
    sf::Text down2;
    sf::Text up2;

    font.loadFromFile("../Assets/Fonts/Arial.ttf");

    players.setFont(font);
    players.setString("Players");
    players.setCharacterSize(20);
    players.setPosition(40.0f, 330.0f);

    up.setFont(font);
    up.setString("+");
    up.setCharacterSize(30);
    up.setPosition(130.0f, 300.0f);

    number.setFont(font);
    number.setString("2");
    number.setCharacterSize(20);
    number.setPosition(133.0f, 330.0f);

    down.setFont(font);
    down.setString("-");
    down.setCharacterSize(30);
    down.setPosition(134.0f, 340.0f);

    goals.setFont(font);
    goals.setString("Goals");
    goals.setCharacterSize(20);
    goals.setPosition(40.0f, 430.0f);

    up2.setFont(font);
    up2.setString("+");
    up2.setCharacterSize(30);
    up2.setPosition(130.0f, 400.0f);

    number2.setFont(font);
    number2.setString("1");
    number2.setCharacterSize(20);
    number2.setPosition(133.0f, 430.0f);

    down2.setFont(font);
    down2.setString("-");
    down2.setCharacterSize(30);
    down2.setPosition(134.0f, 440.0f);

    playbtn.setFont(font);
    playbtn.setString("PLAY");
    playbtn.setCharacterSize(80);
    playbtn.setPosition((1100-playbtn.getGlobalBounds().width)/2, 350.0f);

    Game game = Game(17,2);
    while (!back_button && _window->isOpen()) {

//        game.update();
//        game.render();

        while (_window->pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    _window->close();

                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                        sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(*_window));

                        if (up.getGlobalBounds().contains(mouse) && std::stoi((std::string) number.getString()) < 17){
                            number.setString(std::to_string(std::stoi((std::string) number.getString())+1));
                        }
                        else if (down.getGlobalBounds().contains(mouse) && 2 < std::stoi((std::string) number.getString())){
                            number.setString(std::to_string(std::stoi((std::string) number.getString())-1));
                        }
                        else if (up2.getGlobalBounds().contains(mouse)){
                            number2.setString(std::to_string(std::stoi((std::string) number2.getString())+1));
                        }
                        else if (down2.getGlobalBounds().contains(mouse) && 1 < std::stoi((std::string) number2.getString())){
                            number2.setString(std::to_string(std::stoi((std::string) number2.getString())-1));
                        }
                        else if (playbtn.getGlobalBounds().contains(mouse)){
                            play = true;
                        }
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                        back_button = true;
                    }
            }

        }
        _window->clear();

        if (!play){
            _window->draw(players);
            _window->draw(up);
            _window->draw(number);
            _window->draw(down);
            _window->draw(goals);
            _window->draw(up2);
            _window->draw(number2);
            _window->draw(down2);
            _window->draw(playbtn);
        }
        else if (play){
            game.update();
            game.render();
        }

        _window->display();
    }

}
