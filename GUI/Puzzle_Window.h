//
// Created by camanem on 12/5/21.
//

#ifndef LETSPLAY_PUZZLE_WINDOW_H
#define LETSPLAY_PUZZLE_WINDOW_H
#include <SFML/Graphics.hpp>
#include "Main_Window.h"
#include "../GeneticPuzzle/GeneticPuzzle.h"

class Puzzle_Window: public Main_Window{

private:

    GeneticPuzzle* geneticPuzzle;
    bool prueba = false;
    bool nextEvol = false;
    std::vector<int> pieces_order;

    sf::Texture texture;
    sf::Sprite sprite;



    bool back_button = false;
    bool file_explorer_open = false;
    bool game_started = false;
    bool fragmentedImage = false;

    std::vector<sf::Vector2f> pieces_positions;
    std::vector<sf::Sprite> puzzle_pieces;

    std::vector<sf::Text> files_directions;
    std::string path_selected;

    sf::RenderWindow* mywindow;
    sf::Text backbtn;
    sf::Text playbtn;

    sf::RectangleShape rbackground;
    sf::RectangleShape rshow_all;
    sf::RectangleShape rgeneral;
    sf::RectangleShape ropen;
    sf::RectangleShape rprev;

    sf::Text show_all;
    sf::Font font_f;
    sf::Text prev;
    sf::Text open;

    sf::Text number;
    sf::Text down;
    sf::Text up;


    /**
     * @brief It fragments the image in the number of pieces indicated
     * @param pieces is the number to fragment image
     */
    void fragmentImage(int pieces);

    // ______________________________________________________________________________

    /**
     * Code of Hapax, taken from https://en.sfml-dev.org/forums/index.php?topic=24954.0
     * @brief Resizes an image of any size to an especific size
     * @param originalImage originalImage This is the image that you want to convert
     * @param resizedImage resizedImage This is an image with the size that you want for the originalImage
     */
    void resizeImage(const sf::Image& originalImage, sf::Image& resizedImage);

    /**
     * @brief opens the file explorer for image selection
     */
    void playClicked();

    /**
     * Draws the items of the file explorer on the screen
     */
    void file_explorer_drawing();

    /**
     * @brief Handles extra button animation when file explorer is open
     * @param mouse Is the actual mouse position
     */
    void fileExplorerMouseAnimation(sf::Vector2f mouse);

    /**
     * Handles and extra comparisons when file explorer is open
     * @param mouse Is the mouse position when clicked
     */
    void fileExplorerClick(sf::Vector2f mouse);

    /**
     * Loads the selected image
     */
    void loadImage();

public:

    /**
     * It is an empty constructor
     */
    Puzzle_Window();


    /**
     * @brief Run the window for the Genetic Puzzle
     * @param _window this is a reference of the window created in Main_Window
     * @override
     */
    void Run(sf::RenderWindow* _window);

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
     * @override
     */
    void clickButton(sf::Vector2i mouse_pos);
};


#endif //LETSPLAY_PUZZLE_WINDOW_H