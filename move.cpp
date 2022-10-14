

#include "move.h"

/******************************************************************************
 * MOVE Default Constructor
 ******************************************************************************/
Move::Move()
{
   source = Position();
   dest = Position();
   piece = 'M';
   enpassant = false;
   castleK = false;
   castleQ = false;
   isWhite = false;
   promoting = false;
}

/******************************************************************************
 * MOVE:: GET TEXT
 * Outputs the content of a move into smith notation.
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
   else if (piece != 'M')
      smithNotation += getCapture();
   
   return smithNotation;
}

/******************************************************************************
 * MOVE:: LESS THAN OPERATOR
 * This is need to work with a set.
 * TODO: One line, move to header file.
 ******************************************************************************/
bool Move::operator < (const Move & rhs) const
{
   return this->dest < rhs.dest;
}

/******************************************************************************
 * MOVE:: GET PROMOTION
 * Normally would need a lot more logic, but if it's always promoting to queen
 * I think this is all we need.
 ******************************************************************************/
char Move::getPromotion()
{
   return 'Q';
}

/******************************************************************************
 * MOVE:: SET CASTLE
 * Sets move to castle. True is king side caslte. False is queen side castle. 
 ******************************************************************************/
void Move::setCastle(bool isKing)
{
   castleK = isKing;
   castleQ = !isKing;
}


void Move::display(ogstream & gout)
{
   gout.drawPossible(dest);
}
