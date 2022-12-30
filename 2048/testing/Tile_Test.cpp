#include "CppUTest/TestHarness.h"
#include "Tile.hpp"
#include "SFML/Graphics/Color.hpp"
#include <cstdint>
#include "Colors.h"

using namespace std;

#define Given

TEST_GROUP(Tile_Test)
{
   Tile *instance;

   void teardown()
   {
      if(instance)
      {
         delete instance;
      }
   }

   void TileIsInitializedWith(uint32_t value)
   {
      instance = new Tile(value);
   }

   void TheTileValueShouldBe(uint32_t expected)
   {
      uint32_t actual = instance->GetValue();
      CHECK_EQUAL(expected, actual);
   }

   void TheTileColorShouldBe(ColorRGBA_t expected)
   {
      ColorRGBA_t actual = instance->GetColor();
      CHECK_EQUAL(expected, actual);
   }

};

TEST(Tile_Test, ShouldInitializeTileWithAGivenValue)
{
   Given TileIsInitializedWith(2);
   TheTileValueShouldBe(2);
}

TEST(Tile_Test, TileColorShouldBeRedWhenItsValueIs2)
{
   Given TileIsInitializedWith(2);
   TheTileColorShouldBe(Red);
}