#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

/*
* Generic Class for Player Input Handling
* Using Command Pattern for Input Handling
*/
class Command
{
public:
    virtual ~Command(){}
    virtual void execute() = 0;
};

class RotateShipCommand : public Command
{
public:
    RotateShipCommand(Sprite *sprite, float angle)
    : _sprite(sprite), _angle(angle)
    {}

    virtual void execute();

private:
    Sprite *_sprite;
    float _angle;
};
#endif