#include "position.h"
#include <iostream>
using namespace std;


/******************************************************************************
 * POSITION:: SET
 * Sets the location uses the row and col.
 ******************************************************************************/
void Position::set(int r, int c)
{
   if ((0 <= r && r <= 7) && (0 <= c && c <= 7))
      location = c + ((7 - r) * 8);
   else
      location = -1;
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
   const int numberToLetters[] = { 'a', 'b', 'c', 'd',
                                  'e', 'f', 'g', 'h' };

   letterCord += numberToLetters[getCol()];
   letterCord += std::to_string(getRow() + 1);

   return letterCord;
}

/******************************************************************************
 * POSITION:: Conversion CONSTRUCTOR
 * The positions for our board don't match the once the user clicks. This constructor
 *  converts a UI location to our Position class.
 ******************************************************************************/
Position::Position(int location, bool convert)
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

/******************************************************************************
 * POSITION:: ASSIGNMENT
 * Copies a postion.
 ******************************************************************************/
Position& Position::operator = (const Position& rhs)
{
   location = rhs.location;
   return *this;
}
