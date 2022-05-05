#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Ship
{
public:
    Ship(Sprite &sprite) : mSprite(sprite) {}
    void Accelerate(float deltaTime);
    void Move(float deltaTime);
    void Decelerate();
    void Rotate(float angle, float deltaTime);
    const Vector2f GetDirection();

private:
    Sprite &mSprite;
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;
};

#endif // !SHIP_HPP