//
//  move.h
//  Lab01
//
//  Created by Michael LeFevre on 9/28/22.
//
#include "position.h"
#include <string>

#pragma once
class Move
{
private:
   Position source;
   bool dest;
   char piece;
   char capture;
   bool enpassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   string error;
   
public:
   Move() {}
   string getText() { return "Michael"; }
   Position getSrc() { return * new Position; }
   Position getDes() { return * new Position; }
   char getPromotion() { return 'M'; }
   char getCapture() { return 'M'; }
   bool getEnPassant() { return false; }
   bool getCastleK() { return false; }
   bool getCastleQ() { return false; }
   bool getWhiteMove() { return false; }
   void setEnPassant() {}
   void setCastle(bool isKing) {}
   void setCastleQ() {}
   void setWhiteMove() {}
   void assign(Move move) {}
   void assign(string move) {}
   // operator <<()
   // operator >>()
};
