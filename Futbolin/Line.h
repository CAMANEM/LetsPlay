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
    Line();
    Line(float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);
    ~Line();

    sf::VertexArray getPoints();

    void update();
    void render(sf::RenderTarget& target);

private:
    sf::VertexArray m_points;
    sf::Color m_color;
    virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //LETSPLAY_LINE_H
