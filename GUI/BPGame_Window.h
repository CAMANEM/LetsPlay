//
// Created by camanem on 12/5/21.
//

#ifndef LETSPLAY_BPGAME_WINDOW_H
#define LETSPLAY_BPGAME_WINDOW_H

#include <SFML/Graphics.hpp>


class BPGame_Window {

public:
    BPGame_Window();

    /**
     * @brief Run the window for the BP Game
     * @param _window this is a reference of the window created in Main_Window
     */
    void Run(sf::RenderWindow* _window);
};


#endif //LETSPLAY_BPGAME_WINDOW_H
