/******************************************************************************
 * Header File:
 *    Position : The representation of a position on the board
 * 
 * Lab01
 *
 * Created by Michael LeFevre on 9/28/22.
 *******************************************************************************/


#pragma once
#include <math.h>


 /******************************************************************************
  * POSITION
  * A class to represent a position on the board
  ******************************************************************************/
class Position
{
private:
   char location;
   //squareWidth: Double Static
   //squareHeight: Double Static
   friend class TestPawn;
   friend class TestKing;
public:
   Position() {}
   Position(char colLetter, int rowNumber)
   {
      location = calculateLocation(colLetter, rowNumber);
   }
   Position(int location): location(location) {}

   
   int getLocation() { return location; }
   int getRow() { return calculateRow(location); }
   char getColumn() { return calculateCol(location); }
   int getX() { return 0; }
   int getY() { return 0; }
   bool isValid()
   {
      return 0 <= location && location <= 63;
   }

   void set(char colLetter, int rowNumber)
   {
      location = calculateLocation(colLetter, rowNumber);
   }
   
   bool operator == (Position & rhs) { return location == rhs.location; }
   Position & operator = (Position & rhs)
   {
      Position * pos = new Position(location);
      return *pos;
      
   }
   //Position operator + (Position & rhs) { return *new Position; }
   
   //   void setRow(int r) {}
   //   void setCol(int c) {}
   // operator<<()
   // operator>>()
//   void adjustRow(int dRow) {}
//   void adjustCol(int dCol) {}
   
   static int calculateLocation(char colLetter, int rowNumber)
   {
      int col = colLetter - 'A';
      int row = rowNumber - 1;
      
      assert(0 <= row && row <= 7);
      assert(0 <= col && col <= 7);
      
      int pos = 63 - 7 + col - (row * 8);
      return pos;
   }
   
   static int calculateRow(int location)
   {
      int row = ceil((64.0 - location) / 8.0);
      assert(0 <= row && row <= 7);
      return row;
   }
   
   static char calculateCol(int location)
   {
      int colLetter = 'A' + (location % 8);
      return colLetter;
   }
   
};
