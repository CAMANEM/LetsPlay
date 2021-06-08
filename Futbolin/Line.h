//
// Created by marco on 5/25/21.
//

#ifndef LETSPLAY_LINE_H
#define LETSPLAY_LINE_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>


class Line : public sf::Drawable, sf::Transformable {
public:
    /*!
     * @brief Constructor
     */
    Line();

    /*!
     * @brief Contructor principal
     * @param x1 Coordenada x1
     * @param y1 Coordenada y1
     * @param x2 Coordenada x2
     * @param y2 Coordenada y2
     * @param color Color de la linea
     */
    Line(float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);

    /*!
     * @brief Destructor
     */
    ~Line();

    /*!
     * @brief Getter para los puntos de una linea
     * @return Vector que contiene las coordenadas de la linea
     */
    sf::VertexArray getPoints();


private:
    sf::VertexArray m_points;
    sf::Color m_color;

    /*!
     * @brief Funcion que se encarga de dibujar en pantalla la linea
     * @param target Ventana sobre la cual trabajar
     * @param states
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //LETSPLAY_LINE_H
