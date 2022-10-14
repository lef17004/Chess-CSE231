
#include "position.h"
#include <iostream>
using namespace std;
/******************************************************************************
 * POSITION:: Default Constructor
 * 56 is (0, 0)
 * TODO: Move to header file.
 ******************************************************************************/
Position::Position()
{
   location = 56;
}

/******************************************************************************
 * POSITION:: NON DEFAULT CONSTRUCTOR
 * Sets the position to given row and column.
 * TODO: One line, move to header file.
 ******************************************************************************/
Position::Position(int r, int c)
{
   set(r, c);
}

/******************************************************************************
 * POSITION:: GET LOCATION
 * Returns the location in position.
 * TODO: One line, move to header file.
 ******************************************************************************/
int Position::getLocation() const
{
   return location;
}

/******************************************************************************
 * POSITION:: GET ROW
 * Returns row of chess board.
 * TODO: One line, move to header file.
 ******************************************************************************/
int Position::getRow() const
{
   return 7 - (location / 8);
}

/******************************************************************************
 * POSITION:: GET COL
 * Returns col of chess board.
 * TODO: One line, move to header file.
 ******************************************************************************/
int Position::getCol() const
{
   return location % 8;
}

/******************************************************************************
 * POSITION:: GET X
 * Returns the x position in pixels.
 * TODO: One line, move to header file.
 ******************************************************************************/
int Position::getX()
{
   return (int)((double)(location % 8) * 32.0);
}

/******************************************************************************
 * POSITION:: GET Y
 * Returns the y position in pixels.
 * TODO: One line, move to header file.
 ******************************************************************************/
int Position::getY()
{
   return (int)((double)(location / 8) * 32.0);
}

/******************************************************************************
 * POSITION:: IS VALID
 * Returns a bool indicating if the position exists on a chess board or not.
 * TODO: One line, move to header file.
 ******************************************************************************/
bool Position::isValid()
{
   return 0 <= location && location < 64;
}

/******************************************************************************
 * POSITION:: SET
 * Sets the location uses the row and col.
 * TODO: One line, move to header file.
 ******************************************************************************/
void Position::set(int r, int c)
{
   if ((0 <= r && r <= 7) && (0 <= c && c <= 7))
      location = c + ((7 - r) * 8);
   else
      location = -1;
}

/******************************************************************************
 * POSITION:: LESS THAN
 * Determines which position is less. .
 * TODO: One line, move to header file.
 ******************************************************************************/
bool Position::operator < (const Position & rhs) const
{
   cout << rhs.location << endl;
   return this->location < rhs.location;
}

/******************************************************************************
 * POSITION:: GET LETTER COORDS
 * Returns the position in letter coordiantes. 
 ******************************************************************************/
/*
  8    0,  1,  2,  3,  4,  5,  6,  7,
  7    8,  9, 10, 11, 12, 13, 14, 15,
  6   16, 17, 18, 19, 20, 21, 22, 23,
  5   24, 25, 26, 27, 28, 29, 30, 31,
  4   32, 33, 34, 35, 36, 37, 38, 39,
  3   40, 41, 42, 43, 44, 45, 46, 47,
  2   48, 49, 50, 51, 52, 53, 54, 55,
  1   56, 57, 58, 59, 60, 61, 62, 63
  
       A   B   C   D   E   F   G   H
*/
string Position::getLetterCoords()
{
   string letterCord = "";
   const int numberToLetters[] = {'a', 'b', 'c', 'd',
                                  'e', 'f', 'g', 'h'};
   
   letterCord += numberToLetters[getCol()];
   letterCord += std::to_string(getRow() + 1);
   
   return letterCord;
}

/******************************************************************************
 * POSITION:: COMPARISON
 * Determines if positions are equal or not. .
 * TODO: One line, move to header file.
 ******************************************************************************/
bool Position::operator==(const Position & rhs)
{
   return this->location == rhs.location;
}

/******************************************************************************
 * POSITION:: DELTA CONSTRUCTO
 * Constructor that tkaes a position and a delta.
 * TODO: One line, move to header file.
 ******************************************************************************/
Position::Position(const Position & position, const Delta & delta)
{
   set(position.getRow() + delta.y, position.getCol() + delta.x);
}

/******************************************************************************
 * POSITION:: ASSIGNMENT
 * Copies a postion. 
 ******************************************************************************/
Position & Position::operator = (const Position & rhs)
{
   location = rhs.location;
   return *this;
}
