//
//  move.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#pragma once

#include "position.h"
#include <string>
#include "uiDraw.h"

using namespace std;


class Move
{
private:
   Position source;
   Position dest;
   char piece;
   bool enpassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   bool promoting;

public:
   Move();
   string getText();
   Position& getSrc() { return source; }
   Position& getDes() { return dest; }
   char getCapture() { return piece; }
   char getPromotion();
   bool getEnPassant() { return enpassant; }
   bool getCastleK() { return castleK; }
   bool getCastleQ() { return castleQ; }
   bool getWhiteMove() { return isWhite; }
   void setEnPassant() { enpassant = true; }
   void setCastle(bool isKing);
   void setWhiteMove(bool isWhite) { this->isWhite = isWhite; }
   void setCapture(char name) { piece = name; }
   void setBlackMove() { isWhite = false; }
   void setSource(const Position& source) { this->source = source; }
   void setDest(const Position& dest) { this->dest = dest; }
   void setPromotion() { promoting = true; }

   bool operator < (const Move& rhs) const { return this->dest < rhs.dest; } 

   void display(ogstream& gout) { gout.drawPossible(dest); }

   friend class TestMove;
};
