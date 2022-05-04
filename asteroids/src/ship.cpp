#include "ship.hpp"
#include <math.h>

#define PI 3.14159265
#define ACCEL_FACTOR 0.1f
#define MAX_VELOCITY 5.f

static float DegToRad(float degrees)
{
    return degrees * PI / 180.f;
}

const Vector2f Ship::GetDirection()
{
    Vector2f direction;
    direction.x = sin(DegToRad(mSprite.getRotation()));
    direction.y = -cos(DegToRad(mSprite.getRotation()));
    return direction;
}

void Ship::Accelerate(float deltaTime)
{
    Vector2f direction = GetDirection();
    acceleration.x += ACCEL_FACTOR * direction.x;
    acceleration.y += ACCEL_FACTOR * direction.y;
}

void Ship::Decelerate()
{
    acceleration.x = 0.;
    acceleration.y = 0.;
}

void Ship::Move(float deltaTime)
{
    velocity.x += acceleration.x * deltaTime;
    velocity.y += acceleration.y * deltaTime;

    if(velocity.x > MAX_VELOCITY)
    {
        velocity.x = MAX_VELOCITY;
    }

    if(velocity.y > MAX_VELOCITY)
    {
        velocity.y = MAX_VELOCITY;
    }

    mSprite.move(velocity.x * deltaTime, velocity.y * deltaTime);
}

void Ship::Rotate(float angle, float deltaTime)
{
    mSprite.rotate(angle * deltaTime);
}