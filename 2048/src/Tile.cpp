#include "Tile.hpp"

Tile::Tile(uint32_t value)
{
    _value = value;

    switch (value)
    {
    case 2:
        _color = Red;
        break;
    
    default:
        _color = 0xFF;
        break;
    }
}