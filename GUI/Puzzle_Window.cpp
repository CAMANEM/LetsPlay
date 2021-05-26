//
// Created by camanem on 12/5/21.
//

#include "Puzzle_Window.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include "spdlog/spdlog.h"
#include <string>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <fstream>

Puzzle_Window::Puzzle_Window() {

}


void Puzzle_Window::Run(sf::RenderWindow *_window) {

    mywindow = _window;

    sf::Font font_b;
    font_b.loadFromFile("../Assets/Fonts/PuzzlePieces-ld8y.ttf");

    backbtn.setFont(font_b);
    backbtn.setString("Back");
    backbtn.setCharacterSize(50);
    backbtn.setPosition(40.0f, 20.0f);

    playbtn.setFont(font_b);
    playbtn.setString("PLAY");
    playbtn.setCharacterSize(80);
    playbtn.setPosition((1100-playbtn.getGlobalBounds().width)/2, 350.0f);

    sf::Event event;


    while (!back_button && _window->isOpen()) {
        while (_window->pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    _window->close();

                case sf::Event::MouseMoved:
                    button_animation(sf::Mouse::getPosition(*_window));

                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        clickButton(sf::Mouse::getPosition(*_window));
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && game_started && !fragmentedImage){
                        fragmentImage(std::stoi((std::string) number.getString()));
                        fragmentedImage = true;
                    }

            }
        }
        _window->clear();
        _window->draw(backbtn);
        _window->draw(playbtn);
        if (file_explorer_open){
            file_explorer_drawing();
        }
        else if (game_started){
            if (!fragmentedImage){
                _window->draw(up);
                _window->draw(number);
                _window->draw(down);
                _window->draw(sprite);
            }
            else if (fragmentedImage){
            for (int i = 0; i < puzzle_pieces.size(); ++i) {
                _window->draw(puzzle_pieces.at(i));
            }
            }
        }
        _window->display();
    }
}



void Puzzle_Window::fragmentImage(int pieces) {

    // Calcular si se puede generar en una matriz nxn
    int i_sqrt = sqrt(pieces);
    float f_sqrt = sqrt(pieces);
    int limit_i;

    int fragments_width;
    int fragments_height;

    if (i_sqrt == f_sqrt){
        fragments_width = sprite.getGlobalBounds().width / i_sqrt;
        fragments_height = sprite.getGlobalBounds().height / i_sqrt;
        limit_i = i_sqrt;
    }
    // Solo se divide en 2
    else if (pieces == 2){
        fragments_width = sprite.getGlobalBounds().width;
        fragments_height = sprite.getGlobalBounds().height/2;
        limit_i = 1;
    }
    // Numero a dividir es par
    else if (pieces%2 == 0){
        fragments_width = sprite.getGlobalBounds().width / 2;
        limit_i = 2;
        for (int i = 2; i < pieces; ++i) {
            if (2*i == pieces){
                fragments_height = sprite.getGlobalBounds().height/i;
                break;
            }
        }
    }
    // Numero a fragmentar es impar
    else{
        fragments_width = sprite.getGlobalBounds().width;
        fragments_height = sprite.getGlobalBounds().height/pieces;
        limit_i = 1;
    }

    sf::Vector2f position = sprite.getPosition();
    sf::Vector2f sector = sf::Vector2f(0.0f, 0.0f);

    int i = 1;

    while (puzzle_pieces.size() < pieces){
        sf::Sprite piece;
        piece.setPosition(position);
        piece.setTexture(texture);
        piece.setTextureRect(sf::IntRect(sector.x, sector.y, fragments_width, fragments_height));
        pieces_positions.push_back(position);
        puzzle_pieces.push_back(piece);

        if (i < limit_i){
            i++;
            position.x = position.x + fragments_width +1;
            sector.x = sector.x + fragments_width;
        }
        else{
            i = 1;
            position = sf::Vector2(sprite.getPosition().x, position.y + fragments_height+1);
            sector = sf::Vector2f(0.0f, sector.y + fragments_height);
        }
    }
}

void Puzzle_Window::button_animation(sf::Vector2i mouse_pos) {

    sf::Vector2f mouse = sf::Vector2f(mouse_pos);

    if (backbtn.getGlobalBounds().contains(mouse)){
        backbtn.setColor(sf::Color::Green);
        playbtn.setColor(sf::Color::White);
    }
    else if (playbtn.getGlobalBounds().contains(mouse)){
        playbtn.setColor(sf::Color::Green);
        backbtn.setColor(sf::Color::White);
    }
    else if (file_explorer_open){
        fileExplorerMouseAnimation(mouse);
    }
    else{
        backbtn.setColor(sf::Color::White);
        playbtn.setColor(sf::Color::White);
    }
}

void Puzzle_Window::clickButton(sf::Vector2i mouse_pos) {

    sf::Vector2f mouse = sf::Vector2f(mouse_pos);

    if (backbtn.getGlobalBounds().contains(mouse)){
        back_button = true;
    }
    else if (playbtn.getGlobalBounds().contains(mouse)){
        playbtn.setPosition(-300, -300);
        playClicked();
    }
    else if (file_explorer_open){
        fileExplorerClick(mouse);
    }
    else if (game_started){
        if (up.getGlobalBounds().contains(mouse)){
            number.setString(std::to_string(std::stoi((std::string) number.getString())+1));
        }
        else if (down.getGlobalBounds().contains(mouse) && 2 < std::stoi((std::string) number.getString())){
            number.setString(std::to_string(std::stoi((std::string) number.getString())-1));
        }
    }
}

void Puzzle_Window::fileExplorerMouseAnimation(sf::Vector2f mouse) {

    if (rshow_all.getGlobalBounds().contains(mouse)){
        rshow_all.setFillColor(sf::Color(120, 109, 109, 0));
        rprev.setFillColor(sf::Color(120, 109, 109, 100));
        ropen.setFillColor(sf::Color(120, 109, 109, 100));
    }
    else if (rprev.getGlobalBounds().contains(mouse)){
        rshow_all.setFillColor(sf::Color(120, 109, 109, 100));
        rprev.setFillColor(sf::Color(120, 109, 109, 0));
        ropen.setFillColor(sf::Color(120, 109, 109, 100));
    }
    else if (ropen.getGlobalBounds().contains(mouse)){
        rshow_all.setFillColor(sf::Color(120, 109, 109, 100));
        rprev.setFillColor(sf::Color(120, 109, 109, 100));
        ropen.setFillColor(sf::Color(120, 109, 109, 0));
    }
    else{
        rshow_all.setFillColor(sf::Color(120, 109, 109, 100));
        rprev.setFillColor(sf::Color(120, 109, 109, 100));
        ropen.setFillColor(sf::Color(120, 109, 109, 100));
    }
}

/**
 * NOta personal: lo que sucede con cada if se puede dividir en métodos
 * @param mouse
 */
void Puzzle_Window::fileExplorerClick(sf::Vector2f mouse) {

    sf::Text* directory;
    if (rshow_all.getGlobalBounds().contains(mouse)){

        files_directions.clear();
        std::string path = getpwuid(getuid())->pw_dir;
        float yposition = rshow_all.getPosition().y + rshow_all.getGlobalBounds().height+5;
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            sf::Text t_file;
            t_file.setFont(font_f);
            t_file.setString((const std::string &) entry.path());
            t_file.setCharacterSize(20);
            t_file.setPosition(rshow_all.getPosition().x, yposition);
            files_directions.push_back(t_file);
            yposition = yposition+25;
        }
    }
    else if (rprev.getGlobalBounds().contains(mouse)){
        std::cout << "Still not implemented" << std::endl;
    }
    else if (ropen.getGlobalBounds().contains(mouse)){
        loadImage();

//        fragmentImage(36); // sacar eliminar

    }
    else{
        for (int i = 0; i < files_directions.size(); ++i) {
            directory = &files_directions.at(i);
            if (directory->getGlobalBounds().contains(mouse)){
                directory->setColor(sf::Color::Magenta);
                path_selected = directory->getString(); // tener cuidado de estarlo limpiando
                break;
            }
            else{
                directory->setColor(sf::Color::White);
            }
        }
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

void Puzzle_Window::playClicked() {

    font_f.loadFromFile("../Assets/Fonts/Arial.ttf");

    rbackground.setSize(sf::Vector2f(1100, 900));
    rbackground.setPosition((1100-rbackground.getGlobalBounds().width)/2, (900-rbackground.getGlobalBounds().height)/2);
    rbackground.setFillColor(sf::Color::Black);
    rbackground.setFillColor(sf::Color(0,0,0,150));

    rgeneral.setSize(sf::Vector2f(300, 500));
    rgeneral.setPosition((1100-rgeneral.getGlobalBounds().width)/2, (900-rgeneral.getGlobalBounds().height)/2);
    rgeneral.setFillColor(sf::Color(120, 109, 109, 128));

    show_all.setFont(font_f);
    show_all.setString("Show All");
    show_all.setCharacterSize(30);
    show_all.setPosition(rgeneral.getPosition().x + 10, rgeneral.getPosition().y + 5);

    open.setFont(font_f);
    open.setString("Open");
    open.setCharacterSize(30);
    open.setPosition(show_all.getPosition().x + 205, show_all.getPosition().y);

    open.setFont(font_f);
    open.setString("Open");
    open.setCharacterSize(30);
    open.setPosition(show_all.getPosition().x + 205, show_all.getPosition().y);

    prev.setFont(font_f);
    prev.setString("Prev");
    prev.setCharacterSize(30);
    prev.setPosition(show_all.getPosition().x + 130, show_all.getPosition().y);

    rshow_all.setSize(sf::Vector2f(125, 40));
    rshow_all.setPosition(rgeneral.getPosition().x+5, rgeneral.getPosition().y+5);
    rshow_all.setFillColor(sf::Color(120, 109, 109, 100));
    rshow_all.setOutlineColor(sf::Color(120, 109, 109));

    rprev.setSize(sf::Vector2f(72, 40));
    rprev.setPosition(prev.getPosition().x-7, rshow_all.getPosition().y);
    rprev.setFillColor(sf::Color(120, 109, 109, 100));
    rprev.setOutlineColor(sf::Color(120, 109, 109));

    ropen.setSize(sf::Vector2f(85, 40));
    ropen.setPosition(open.getPosition().x-7, rshow_all.getPosition().y);
    ropen.setFillColor(sf::Color(120, 109, 109, 100));
    ropen.setOutlineColor(sf::Color(120, 109, 109));

    std::string path = "../Assets/Pictures";
    float yposition = rshow_all.getPosition().y + rshow_all.getGlobalBounds().height+5;
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        sf::Text t_file;
        t_file.setFont(font_f);
        t_file.setString((const std::string &) entry.path());
        t_file.setCharacterSize(20);
        t_file.setPosition(rshow_all.getPosition().x, yposition);
        files_directions.push_back(t_file);
        yposition = yposition+25;
//        files_directions.at(0);
    }

    file_explorer_open = true;
}

void Puzzle_Window::file_explorer_drawing() {
    mywindow->draw(rbackground);
    mywindow->draw(rgeneral);
    mywindow->draw(rshow_all);
    mywindow->draw(show_all);
    mywindow->draw(rprev);
    mywindow->draw(ropen);
    mywindow->draw(prev);
    mywindow->draw(open);
    for (int i = 0; i < files_directions.size(); ++i) {
        mywindow->draw(files_directions.at(i));
    }
}

/**
 * Falta manejar errores al abrir archivos invalidos
 */
void Puzzle_Window::loadImage() {

    if (!path_selected.empty()) {
        sf::Image base_image;
        if (base_image.loadFromFile(path_selected)) {
            sf::Image image;
            image.create(600, 700);
//            Copy image1 on image2 at position (10, 10)
            image.copy(base_image, 10, 10);
            resizeImage(base_image, image);
            texture.loadFromImage(image);
            sprite.setTexture(texture);
            sprite.setPosition((1100 - sprite.getGlobalBounds().width) / 2,
                               (900 - sprite.getGlobalBounds().height) / 2);
            file_explorer_open = false;
            game_started = true;
            // Boton de fragmentar imagen //
            up.setFont(font_f);
            up.setString("+");
            up.setCharacterSize(30);
            up.setPosition(50.0f, 300.0f);

            number.setFont(font_f);
            number.setString("2");
            number.setCharacterSize(20);
            number.setPosition(53.0f, 330.0f);

            down.setFont(font_f);
            down.setString("-");
            down.setCharacterSize(30);
            down.setPosition(54.0f, 340.0f);

        } else {
            files_directions.clear();
            std::string path = path_selected;
            float yposition = rshow_all.getPosition().y + rshow_all.getGlobalBounds().height + 5;
            for (const auto &entry : std::filesystem::directory_iterator(path)) {
                sf::Text t_file;
                t_file.setFont(font_f);
                t_file.setString((const std::string &) entry.path());
                t_file.setCharacterSize(20);
                t_file.setPosition(rshow_all.getPosition().x, yposition);
                files_directions.push_back(t_file);
                yposition = yposition + 25;
            }

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
    // Load an image file from a file
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