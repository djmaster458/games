#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

/*
 * Generic Class for issuing commands to sprites
 * Using Command Pattern for Input Handling
 */
class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class RotateCommand : public Command
{
public:
    RotateCommand(Sprite *sprite, const Time &deltaTime, float angle)
        : _sprite(sprite), _deltaTime(deltaTime), _angle(angle)
    {
    }

    virtual void execute();

private:
    Sprite *_sprite;
    const Time &_deltaTime;
    float _angle;
};

class MoveCommand : public Command
{
public:
    MoveCommand(Sprite *sprite, const Time &deltaTime, float speed)
        : _sprite(sprite), _deltaTime(deltaTime), _speed(speed)
    {
    }

    virtual void execute();

private:
    Sprite *_sprite;
    const Time &_deltaTime;
    float _speed;
};
#endif