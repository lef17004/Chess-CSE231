//
//  piece.h
//  Lab01
//
//  Created by Jane Orr on 9/28/22.
//

#pragma once
class Piece
{
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;

public:
   void piece(int r, int c, bool white) {}
   void assign(Position position) {}
   void assign(Piece piece) {}
   bool isWhite() { return False;  }
   int getNMoves() { return 0; }
   Position getPosition() { return *new Position; }
   bool justMoved() { return False; }
   virtual char getLetter() = 0;
   virtual void display(ogstream gout) = 0;
   //virtual void getMoves(Board board) = 0;
