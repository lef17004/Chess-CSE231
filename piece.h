//
//  piece.h
//  Lab01
//
//  Created by Jane Orr on 9/28/22.
//
#pragma once
#include "board.h"
#include <set>
#include <vector>
#include "move.h"
using namespace std;
class Board;

class Piece
{
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;
   friend class TestPawn;

public:
   Piece(int r, int c, bool white) {}
   virtual ~Piece() {};
   void assign(Position position) {}
   void assign(Piece & piece) {}
   bool isWhite() { return false;  }
   int getNMoves() { return 0; }
   Position getPosition() { return *new Position; }
   bool justMoved() { return false; }
   virtual char getLetter() = 0;
   virtual void display(ogstream & gout) = 0;
   virtual set<Move> getMoves(Board & board) = 0;
   
};

class Pawn: public Piece
{
public:
   Pawn(int r, int c, bool white): Piece(r, c, white) {}
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

   
class Rook: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class Knight: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class Bishop: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class King: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class Queen: public Piece
{
public:
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class Space: public Piece
{
public:
   Space(int r, int c): Piece(r, c, false) {}
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};
