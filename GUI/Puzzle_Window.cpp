//
// Created by camanem on 12/5/21.
//

#include "Puzzle_Window.h"
#include <filesystem>
#include <iostream>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

Puzzle_Window::Puzzle_Window() {

}


void Puzzle_Window::Run(sf::RenderWindow *_window) {

    //Prints directory content - Need at least C++ 17
    // getpwuid(getuid())->pw_dir  this returns home directory
    std::string path = "../Assets/Pictures";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
    }

    bool back_button = false;
    sf::Texture texture;
    texture.loadFromFile("../Assets/Pictures/image.jpg");
    sf::Sprite sprite(texture);
    sprite.setPosition(100.0f, 100.0f);
    sf::Event event;


    while (!back_button && _window->isOpen()) {
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
        _window->draw(sprite);
        _window->display();
    }
}


void Puzzle_Window::resizeImage(const sf::Image &originalImage, sf::Image &resizedImage) {

    const sf::Vector2u originalImageSize{ originalImage.getSize() };
    const sf::Vector2u resizedImageSize{ resizedImage.getSize() };
    for (unsigned int y{ 0u }; y < resizedImageSize.y; ++y)
    {
        for (unsigned int x{ 0u }; x < resizedImageSize.x; ++x)
        {
            unsigned int origX{ static_cast<unsigned int>(static_cast<double>(x) / resizedImageSize.x * originalImageSize.x) };
            unsigned int origY{ static_cast<unsigned int>(static_cast<double>(y) / resizedImageSize.y * originalImageSize.y) };
            resizedImage.setPixel(x, y, originalImage.getPixel(origX, origY));
        }
    }
}

/**
 * Codigo para dividir en cuadrados
 */
//    sf::Texture texture;
//    // Con esto puede bastar para dividir la figura en cuadrados
//    texture.loadFromFile("../pictures/image.jpg", sf::IntRect(100, 100, 100, 100)); //texture.loadFromFile("../pictures/image.jpg");
//    sf::Sprite sprite(texture);
//    sprite.setPosition(100.0f,100.0f);



/**
 * Codigo para redimensionar
 */
//    // Load an image file from a file
//    sf::Image background;
//    if (!background.loadFromFile("../pictures/image.jpg")) {
//        std::cout << "no se cargo la imagen" << std::endl;
//    }
// Create a 20x20 image filled with white color
//    sf::Image image;
//    image.create(100, 200);
//    image.create(200, 200, sf::Color::White);
// Copy image1 on image2 at position (10, 10)
//    image.copy(background, 10, 10);
//    resizeImage(background, image);
//
//    sf::Texture texture;
//    texture.loadFromImage(image);
//    sf::Sprite sprite(texture);
//    sprite.setPosition(100.0f,100.0f);