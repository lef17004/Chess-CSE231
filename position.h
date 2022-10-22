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
   Position(): location(56) {}
   Position(int r, int c) { set(r, c); }
   Position(int location, bool convert = false);
   Position(const Position& position, const Delta& delta) { set(position.getRow() + delta.y, position.getCol() + delta.x); }
   int getLocation() const { return location; }
   int getRow() const { return 7 - (location / 8); }
   int getCol() const { return location % 8; }
   int getX() { return (int)((double)(location % 8) * 32.0); }
   int getY() { return (int)((double)(location / 8) * 32.0); }
   string getLetterCoords();
   bool isValid() { return 0 <= location && location < 64; }

   void set(int r, int c);

   bool operator < (const Position& rhs) const { return this->location < rhs.location; }
   bool operator == (const Position& rhs) { return this->location == rhs.location; }
   Position& operator = (const Position& rhs);

   friend class TestPosition;
   friend class TestMove;
   friend class TestPawn;
   friend class TestKing;
};
