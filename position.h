//
//  position.h
//  Lab01
//
//  Created by Michael LeFevre on 9/28/22.
//

#pragma once
class Position
{
private:
   char location;
   //squareWidth: Double Static
   //squareHeight: Double Static
   friend class TestPawn;
public:
   Position() {}
   Position(int location) {}
   int getLocation() { return 0; }
   int getRow() { return 0; }
   int getColumn() { return 0; }
   int getX() { return 0; }
   int getY() { return 0; }
   bool isValid() { return false; }
   void setRow(int r) {}
   void setCol(int c) {}
   void set(int r, int c) {}
   void adjustRow(int dRow) {}
   void adjustCol(int dCol) {}
   bool operator == (Position & rhs) { return false; }
   Position operator = (Position & rhs) { return *new Position; }
   Position operator + (Position & rhs) { return *new Position; }
   // operator<<()
   // operator>>()
};
