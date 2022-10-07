//
//  board.hpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#pragma once
#include "piece.h"
#include <array>
#include "position.h"
#include "move.h"
using namespace std;

class Piece;

class Board
{
private:
   array<Piece*, 64> board;
   int currentMove;
   // ogstream gout;
   
   void swap(Position pos1, Position pos2);
   void assertBoard();
   
public:
   Board();
   int getCurrentMove();
   bool isWhiteTurn() const; 
   //void display( posHover,  PosSel)
   Piece * getPiece(const Position & pos) const;
   void setPiece(Piece * piece);
   void free();
   void reset();
   void move(const Move & move);
   void setBoardToEmpty();
   
   
   Piece & getPiece();
   Piece & makePiece();
   
   Piece * piece;
   
   
   friend class TestBoard;
   friend class TestPawn;
   friend class TestKing;
};
