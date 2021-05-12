//
// Created by camanem on 12/5/21.
//

#ifndef LETSPLAY_PUZZLE_WINDOW_H
#define LETSPLAY_PUZZLE_WINDOW_H
#include <SFML/Graphics.hpp>


class Puzzle_Window {

private:

    /**
     * Code of Hapax, taken from https://en.sfml-dev.org/forums/index.php?topic=24954.0
     * @brief Resizes an image of any size to an especific size
     * @param originalImage originalImage This is the image that you want to convert
     * @param resizedImage resizedImage This is an image with the size that you want for the originalImage
     */
    void resizeImage(const sf::Image& originalImage, sf::Image& resizedImage);


public:

    /**
     * It is an empty constructor
     */
    Puzzle_Window();


    /**
     * @brief Run the window for the Genetic Puzzle
     * @param _window this is a reference of the window created in Main_Window
     */
    void Run(sf::RenderWindow* _window);
};


#endif //LETSPLAY_PUZZLE_WINDOW_H
