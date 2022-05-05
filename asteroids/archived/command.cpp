/*
* Class for Player Input Handling
* Using Command Pattern for Input Handling
*/
#include "command.hpp"
#include <math.h>

#define PI 3.14159265

static float DegToRad(float degrees)
{
    return degrees * PI / 180.f;
}

// Rotates a ship by angle degrees/second
void RotateCommand::execute()
{
    _sprite->rotate(_angle * _deltaTime.asSeconds());
}

void MoveCommand::execute()
{
    Vector2f velocity;

    velocity.x = _speed * sin(DegToRad(_sprite->getRotation()));
    velocity.y = _speed * -cos(DegToRad(_sprite->getRotation()));

    _sprite->move(velocity.x * _deltaTime.asSeconds(), velocity.y * _deltaTime.asSeconds());
}