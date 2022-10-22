#include "move.h"
#include "piece.h"

/******************************************************************************
 * MOVE Default Constructor
 ******************************************************************************/
Move::Move()
{
   source = Position();
   dest = Position();
   piece = UNDEFINED_PIECE;
   enpassant = false;
   castleK = false;
   castleQ = false;
   isWhite = false;
   promoting = false;
}

/******************************************************************************
 * MOVE:: GET TEXT
 * Outputs the content of a move into Smith Notation.
 ******************************************************************************/
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
   else if (promoting)
      smithNotation += promotion;
   else if (piece != UNDEFINED_PIECE)
      smithNotation += getCapture();

   return smithNotation;
}

/******************************************************************************
 * MOVE:: GET PROMOTION
 * Normally would need a lot more logic, but if it's always promoting to queen
 * I think this is all we need.
 ******************************************************************************/
char Move::getPromotion()
{
   if (promoting)
      return QUEEN;
   else
      return UNDEFINED_PIECE;
}

/******************************************************************************
 * MOVE:: SET CASTLE
 * Sets move to castle. True is king side castle. False is queen side castle.
 ******************************************************************************/
void Move::setCastle(bool isKing)
{
   castleK = isKing;
   castleQ = !isKing;
}
