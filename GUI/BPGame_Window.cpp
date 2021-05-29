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
    Game game = Game(17,2);


    while (!back_button && _window->isOpen()) {

        game.update();
        game.render();

        while (_window->pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    _window->close();

                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        back_button = true;
                    }
            }

        }
        _window->clear();
        _window->display();
    }

}
