#ifndef Tile_H
#define Tile_H

#include <vector>
#include <cstdint>
#include "Colors.h"

using namespace std;

class Tile
{
public:
    Tile(uint32_t value);
    const uint32_t GetValue(void) { return _value; };
    const ColorRGBA_t GetColor(void) { return _color; };

private:
    uint32_t _value;
    ColorRGBA_t _color;
};


#endif // !Tile_H