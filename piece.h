//
//  piece.h
//  Lab01
//
//  Created by Jane Orr on 9/28/22.
//
#pragma once
#include "board.h"
class Board;

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
   void assign(Piece & piece) {}
   bool isWhite() { return false;  }
   int getNMoves() { return 0; }
   Position getPosition() { return *new Position; }
   bool justMoved() { return false; }
   virtual char getLetter() = 0;
   virtual void display(ogstream & gout) = 0;
   virtual void getMoves(Board * board) = 0;
};

class Pawn: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual void getMoves(Board * board) {}
};

class Rook: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual void getMoves(Board * board) {}
};

class Knight: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual void getMoves(Board * board) {}
};

class Bishop: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual void getMoves(Board * board) {}
};

class King: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual void getMoves(Board * board) {}
};

class Queen: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual void getMoves(Board * board) {}
};
