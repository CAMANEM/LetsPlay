//
// Created by camanem on 12/5/21.
//

#ifndef LETSPLAY_BPGAME_WINDOW_H
#define LETSPLAY_BPGAME_WINDOW_H

#include <SFML/Graphics.hpp>
#include "../Futbolin/Game.h"


class BPGame_Window {

private:
    bool play = false;
    Game* game;


public:
    BPGame_Window();

    /**
     * @brief Run the window for the BP Game
     * @param _window this is a reference of the window created in Main_Window
     */
    void Run(sf::RenderWindow* _window);

    /**
     * @brief It is called if the mouse is left clicked, and changes the
     * window if the click was over a button
     * @param mouse_pos Is the mouse position when clicked
     * @override
     */
    void clickButton(sf::Vector2i mouse_pos);
};


#endif //LETSPLAY_BPGAME_WINDOW_H
