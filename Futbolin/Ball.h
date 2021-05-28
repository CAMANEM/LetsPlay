//
// Created by marco on 5/25/21.
//

#ifndef LETSPLAY_BALL_H
#define LETSPLAY_BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <cmath>

class Ball : public sf::Drawable{
public:
    Ball();
    Ball(sf::Vector2f center, float radius, sf::Color color);
    ~Ball();
    Ball(const Ball&);
    Ball& operator=(const Ball&);

    void			setPosition(float x, float y);
    void			setAngle(float angle);
    void			setAcceleration(sf::Vector2f acceleration);
    void			setVelocity(sf::Vector2f velocity);

    sf::Vector2f	getPosition();
    const sf::Vector2f	getVelocity() const;
    sf::Vector2f	getAcceleration();
    float			getRadius();
    float			getMass();


    void			move(sf::Vector2f velocity);
    void			rotate(float angle);

    void			updateVelocity(float deltaTime);
    bool			checkCollisionPoint(const sf::Vector2f& mouse);
    void			updateCollisionBorder(const sf::RenderWindow& window);

    void			update(const sf::RenderWindow& window, float deltaTime);
    void			render();

private:
    unsigned int MAX_POINTS;
    float VISCOSITY;
    sf::VertexArray m_vertices;
    sf::Color COLOR_SHAPE;
    sf::Color m_color;
    sf::Vector2f viscosity;
    sf::Vector2f m_center;
    sf::Vector2f m_velocity;
    sf::Vector2f m_acceleration;
    float m_radius;
    float m_angle;
    float m_mass;
    void initVariables();
    void initShape();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //LETSPLAY_BALL_H
