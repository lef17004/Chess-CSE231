//
//  piece.hpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#pragma once
#include "board.h"
#include "position.h"
#include "move.h"
#include <set>
#include "delta.h"
class Board;

class Piece
{
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;
   
public:
   
   Piece();
   Piece(int r, int c, bool isWhite);
   
   bool isWhite() { return  fWhite; }
   bool isMove() { return nMoves > 0; }
   int getNMoves() { return nMoves; }
   Position & getPosition() { return position; }
   bool justMoved(int turnNumber);
   set<Move> & getMovesSlide(const Board & board, array<Delta, 8> deltas);
   
   virtual char getLetter();
   virtual set<Move> & getPossibleMoves(const Board & board);
   // display
   
   // Test ----------------------------
   void useBoard(Board & board);
   void displayPiece();
   
   int pos;
   // Test ----------------------------
   
   friend class TestPiece;
   friend class TestPawn;
   friend class TestKing;
};

class Pawn: public Piece
{
public:
   Pawn();
   Pawn(int r, int c, bool isWhite);
   
   virtual char getLetter() { return 'p'; }
   virtual set<Move> & getPossibleMoves(const Board & board);
   
   friend class TestPawn;
};


class Space: public Piece
{
public:
   Space();
   Space(int r, int c, bool isWhite);
   
   virtual char getLetter() { return 's'; }
   virtual set<Move> & getPossibleMoves(const Board & board);
};

class King: public Piece
{
public:
   King();
   King(int r, int c, bool isWhite);
   
   virtual char getLetter() { return 'k'; }
   virtual set<Move> & getPossibleMoves(const Board & board);
};

class Rook: public Piece
{
public:
   Rook();
   Rook(int r, int c, bool isWhite);
   
   virtual char getLetter() { return 'r'; }
   virtual set<Move> & getPossibleMoves(const Board & board);
};
