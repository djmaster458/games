/*
* Class for Player Input Handling
* Using Command Pattern for Input Handling
*/
#include "command.hpp"

void RotateShipCommand::execute()
{
    _sprite->rotate(_angle);
}