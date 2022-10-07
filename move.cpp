//
//  move.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "move.h"


Move::Move()
{
   source = Position();
   dest = Position();
   piece = 'M';
   enpassant = false;
   castleK = false;
   castleQ = false;
   isWhite = false;
}

string Move::getText()
{
   string smithNotation = "";
   smithNotation += source.getLetterCoords();
   smithNotation += dest.getLetterCoords();
   
   char promotion = getPromotion();
   if (castleK)
      smithNotation += "c";
   else if (castleQ)
      smithNotation += "C";
   else if (enpassant)
      smithNotation += "E";
   else if (promotion != 'M')
      smithNotation += promotion;
   else if (piece != 'M')
      smithNotation += getCapture();
   
   
   
   
   return smithNotation;
}

bool Move::operator < (const Move & rhs) const
{
   return this->dest < rhs.dest;
}

char Move::getPromotion()
{
   if (dest.getRow() == 0 || dest.getRow() == 7)
      return 'Q';
   return 'M';
}


void Move::setCastle(bool isKing)
{
   castleK = isKing;
   castleQ = !isKing;
}
