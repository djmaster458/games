#include "CppUTest/TestHarness.h"
#include "Board.hpp"
#include <vector>
#include <iostream>

using namespace std;

TEST_GROUP(Board_Test)
{
   Board *instance;

   void setup()
   {
      instance = new Board();
   }

   void teardown()
   {
      delete instance;
   }

   void TheBoardStateShouldBe(const vector<vector<uint32_t>> &expected)
   {
      const vector<vector<uint32_t>> actual = instance->GetState();

      for(size_t i = 0; i < expected.size(); i++)
      {
         for(size_t j = 0; j < expected[i].size(); j++)
         {
            CHECK_EQUAL(expected[i][j], actual[i][j]);
         }
      }
   }
};

TEST(Board_Test, ShouldInitializeWithEmptyAnZeroedBoardState)
{
   vector<vector<uint32_t>> zeroed = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
   TheBoardStateShouldBe(zeroed);
}