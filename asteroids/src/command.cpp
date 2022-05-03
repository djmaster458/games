/*
* Class for Player Input Handling
* Using Command Pattern for Input Handling
*/
#include "command.hpp"

// Rotates a ship by angle degrees/second
void RotateShipCommand::execute()
{
    _sprite->rotate(_angle * _time.asSeconds());
}