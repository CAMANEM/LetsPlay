//
// Created by camanem on 12/5/21.
//

#ifndef LETSPLAY_MAIN_WINDOW_H
#define LETSPLAY_MAIN_WINDOW_H

#include <SFML/Graphics.hpp>


class Main_Window {

private:
    sf::Text puzzle;
    sf::Text bpgame;
    sf::RenderWindow* my_window;

public:

    /**
     * This is an empty constructor
     */
    Main_Window();

    /**
     * @brief Initializes the menu window
     */
    void Run();

    /**
     * @brief It is called if the mouse is moving, and changes the color
     * of the a button if the cursor is over the button
     * @param mouse_pos Is the actual mouse position
     */
    void button_animation(sf::Vector2i mouse_pos);

    /**
     * @brief It is called if the mouse is left clicked, and changes the
     * window if the click was over a button
     * @param mouse_pos Is the mouse position when clicked
     */
    void clickButton(sf::Vector2i mouse_pos);
};


#endif //LETSPLAY_MAIN_WINDOW_H
