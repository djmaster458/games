/*
* Class for Player Input Handling
* Using Command Pattern for Input Handling
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Command
{
public:
    virtual ~Command(){}
    virtual void execute() = 0;
};

class MoveShipCommand : public Command
{
public:
    MoveShipCommand(Sprite *sprite, float x, float y)
    : _sprite(sprite), _x(x), _y(y)
    {}

    virtual void execute()
    {
        prevPos = _sprite->getPosition();
        _sprite->move(Vector2f(_x, _y));
    }

private:
    Sprite *_sprite;
    float _x, _y;
    Vector2f prevPos;
};