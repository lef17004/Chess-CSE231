
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
   // ogstream gout;
   
   void swap(const Position & pos1, const Position & pos2);
   void assertBoard();
   
public:
   Board();
   int getCurrentMove() const;
   bool isWhiteTurn() const; 
   void display(ogstream & gout);
   void displayPieces(ogstream & gout);
   
   Piece * getPiece(const Position & pos) const;
   Piece & operator[] (Position & pos);
   
   void setPiece(Piece * piece);
   void free();
   void reset();
   bool move(Move & move);
   bool move(Position & positionFrom, Position & positionTo);
   void setPiece(Piece * piece, const Position & pos);
   void setBoardToEmpty();
   
   

   
   Piece * piece;
   
   
   friend class TestBoard;
   friend class TestPawn;
   friend class TestKing;
};
