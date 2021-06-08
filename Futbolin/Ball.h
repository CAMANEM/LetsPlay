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
    /*!
     * @brief Constructor para el objeto.
     */
    Ball();

    /*!
     * @brief Constructor para el objeto con variables definidas.
     * @param center Coordenadas para el centro de la bola.
     * @param radius Radio correspondiente a la bola.
     * @param color Color de la bola.
     */
    Ball(sf::Vector2f center, float radius, sf::Color color);

    /*!
     * @brief Destructor del objeto
     */
    ~Ball();

    /*!
     * @brief Constructor de una bola a partir de otra.
     */
    Ball(const Ball&);

    /*!
     * @brief Igualar valores de una bola a otra.
     * @return Bola modificada.
     */
    Ball& operator=(const Ball&);

    /*!
     * @brief Setter para la posicion de la bola.
     * @param x Coordenada x.
     * @param y Coordenada y.
     */
    void setPosition(float x, float y);

    /*!
     * @brief Setter para el angulo en que la bola se encuentra apuntando.
     */
    void setAngle(float angle);

    /*!
     * @brief Setter para la aceleracion que posee la bola.
     * @param acceleration Valor a darle a la aceleracion.
     */
    void setAcceleration(sf::Vector2f acceleration);

    /*!
     * @brief Setter para la velocidad que la bola posee.
     * @param velocity Velocidad a darle a la bola.
     */
    void setVelocity(sf::Vector2f velocity);

    /*!
     * @brief Getter para la posicion de la bola.
     * @return La posicion de la bola.
     */
    sf::Vector2f getPosition();

    /*!
     * @brief Getter para la velocidad de la bola.
     * @return La velocidad de la bola.
     */
    const sf::Vector2f getVelocity() const;

    /*!
     * @brief Getter para la aceleracion de la bola.
     * @return La aceleracion de la bola.
     */
    sf::Vector2f getAcceleration();

    /*!
     * @brief Getter para el radio de la bola.
     * @return El radio de la bola.
     */
    float getRadius();

    /*!
     * @brief Getter para la masa de la bola.
     * @return La masa de la bola.
     */
    float getMass();

    /*!
     * @brief Funcion encargada de mover la bola con respecto a los valores de un vector.
     * @param velocity Valores con los que mover la bola.
     */
    void move(sf::Vector2f velocity);

    /*!
     * @brief Rotacion a darle a la bola.
     * @param angle Angulo con el cual la bola debe de rotar.
     */
    void rotate(float angle);

    /*!
     * @brief Funcion encargada de actualizar la velocidad con la que debe de moverse la bola
     * @param deltaTime Tiempo que ha pasado entre las actualizaciones.
     */
    void updateVelocity(float deltaTime);

    /*!
     * @brief Funcion encargada de verificar si el mouse se encuentra encima de la bola.
     * @param mouse Coordenadas correspondientes a la posicion del mouse.
     * @return Bool correspondiente al resultado de la verificacion.
     */
    bool checkCollisionPoint(const sf::Vector2f& mouse);

    /*!
     * @brief Funcion encargada de verificar si la bola ha colisionado con algun borde correspondiente al tablero.
     * @param window Ventana sobre la cual trabajar.
     */
    void updateCollisionBorder(const sf::RenderWindow& window);

    /*!
     * @brief Actualizador de las variables de la bola.
     * @param window Ventana sobre la cual trabajar.
     * @param deltaTime Tiempo que ha pasado desde la ultima actualizacion.
     */
    void update(const sf::RenderWindow& window, float deltaTime);

    /*!
     * @brief Reenderizacion en pantalla de la bola.
     */
    void render();

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

    /*!
     * @brief Inicializador para las variables de la bola.
     */
    void initVariables();

    /*!
     * @brief Inicializador para la forma de la bola.
     */
    void initShape();

    /*!
     * @brief Funcion que se encarga de dibujar en pantalla la bola
     * @param target Ventana sobre la cual trabajar
     * @param states
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //LETSPLAY_BALL_H
