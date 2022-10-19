#pragma once

#include <string>
#include "delta.h"

using namespace std;

/*
7    0,  1,  2,  3,  4,  5,  6,  7,
6    8,  9, 10, 11, 12, 13, 14, 15,
5   16, 17, 18, 19, 20, 21, 22, 23,
4   24, 25, 26, 27, 28, 29, 30, 31,
3   32, 33, 34, 35, 36, 37, 38, 39,
2   40, 41, 42, 43, 44, 45, 46, 47,
1   48, 49, 50, 51, 52, 53, 54, 55,
0   56, 57, 58, 59, 60, 61, 62, 63

     0   1   2   3   4   5   6   7
*/
class Position
{
private:
   int location; // Switch to char after testing is done. 
   static double squareWidth;
   static double squareHeight;

public:
   Position();
   Position(int r, int c);
   Position(int location, bool convert = false)
   {
      this->location = location;
      if (convert && 0 <= location && location < 64)
      {
         int table[] = {56, 57, 58, 59, 60, 61, 62, 63,
                        48, 49, 50, 51, 52, 53, 54, 55,
                        40, 41, 42, 43, 44, 45, 46, 47,
                        32, 33, 34, 35, 36, 37, 38, 39,
                        24, 25, 26, 27, 28, 29, 30, 31,
                        16, 17, 18, 19, 20, 21, 22, 23,
                         8,  9, 10, 11, 12, 13, 14, 15,
                         0,  1,  2,  3,  4,  5,  6,  7
         };
         this->location = table[location];
      }


   }
   Position(const Position& position, const Delta& delta);
   int getLocation() const;
   int getRow() const;
   int getCol() const;
   int getX();
   int getY();
   string getLetterCoords();
   bool isValid();

   void set(int r, int c);

   bool operator < (const Position& rhs) const;
   bool operator == (const Position& rhs);
   Position& operator = (const Position& rhs);

   friend class TestPosition;
   friend class TestMove;
   friend class TestPawn;
   friend class TestKing;
};
