//
//  position.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "position.h"

Position::Position()
{
   location = 56;
}

Position::Position(int r, int c)
{
   set(r, c);
}

int Position::getLocation() const
{
   return location;
}

int Position::getRow() const
{
   return 7 - (location / 8);
}

int Position::getCol() const
{
   return location % 8;
}

int Position::getX()
{
   return (int)((double)(location % 8) * 32.0);
}

int Position::getY()
{
   return (int)((double)(location / 8) * 32.0);
}

bool Position::isValid()
{
   return 0 <= location && location < 64;
}

void Position::set(int r, int c)
{
   location = c + ((7 - r) * 8);
}

bool Position::operator < (const Position & rhs) const
{
   return this->location < rhs.location;
}

string Position::getLetterCoords()
{
   string letterCord = "";
   const int numberToLetters[] = {'a', 'b', 'c', 'd',
                                  'e', 'f', 'g', 'h'};
   
   letterCord += numberToLetters[getCol()];
   letterCord += std::to_string(getRow() + 1);
   
   return letterCord;
}

bool Position::operator==(const Position & rhs)
{
   return this->location == rhs.location;
}

Position::Position(const Position & position, const Delta & delta)
{
   set(position.getRow() + delta.y, position.getCol() + delta.x);
}
