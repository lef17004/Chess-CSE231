#pragma once

#include "piece.h"
#include <array>
#include "position.h"
#include "move.h"
#include "uiDraw.h"

using namespace std;


// Forward Declaration - If removed you will suffer
class Piece;

class Board
{
private:
   array<Piece*, 64> board;
   int currentMove;
   
   void swap(const Position & pos1, const Position & pos2);
   void assertBoard();
   
public:
   Board();
   ~Board();
   int getCurrentMove() const { return currentMove; }
   bool isWhiteTurn() const { return !(currentMove % 2); }
   void display(ogstream & gout) { gout.drawBoard(); }
   void displayPieces(ogstream & gout);
   
   Piece * getPiece(const Position & pos) const { return board[pos.getLocation()]; }
   Piece & operator[] (Position & pos) { return *board[pos.getLocation()]; }
   
   void setPiece(Piece * piece);
   void free();
   void reset();
   bool move(Position & positionFrom, Position & positionTo);
   void setPiece(Piece * piece, const Position & pos);
   void setBoardToEmpty();
   
   Piece * piece;    
   
   friend class TestBoard;
   friend class TestPawn;
   friend class TestKing;
};
