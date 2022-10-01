/******************************************************************************
 * Header File:
 *    Board : The representation of the board
 * 
 * Lab01
 *
 * Created by Michael LeFevre on 9/28/22.
 *******************************************************************************/


#pragma once

#include <array>
#include "position.h"
#include "piece.h"
#include "move.h"
#include "board.h"


 /******************************************************************************
  * BOARD 
  * The board object
  ******************************************************************************/
class Board
{
private:
   std::array<Piece*, 64> board;
   int currentMove;
   ogstream gout;
   
   void swap(Position pos1, Position pos2) {}
   void assertBoard() {}
   friend class TestPawn;
   friend class TestKing;
   
public:
   
   Board() {}
   Board(ogstream gout, bool reset) {}
   int getCurrentMove() { return -1; }
   bool whiteTurn() { return false; }
   void display(int posHover, int posSel) {}
   Piece * get(Position pos) { return NULL; }
   void free() {}
   void reset() {}
   void move(Move move) {}
   void setBoardArray(std::array<Piece*, 64>) {}
};
