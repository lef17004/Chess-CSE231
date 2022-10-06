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
   
   Board()
   {
      board[0]  = new Rook(  'A', 8, false);
      board[1]  = new Knight('B', 8, false);
      board[2]  = new Bishop('C', 8, false);
      board[3]  = new Queen( 'D', 8, false);
      board[4]  = new King(  'E', 8, false);
      board[5]  = new Bishop('F', 8, false);
      board[6]  = new Knight('G', 8, false);
      board[7]  = new Rook(  'H', 8, false);
      
      board[8]  = new Pawn(  'A', 7, false);
      board[9]  = new Pawn(  'B', 7, false);
      board[10] = new Pawn(  'C', 7, false);
      board[11] = new Pawn(  'D', 7, false);
      board[12] = new Pawn(  'E', 7, false);
      board[13] = new Pawn(  'F', 7, false);
      board[14] = new Pawn(  'G', 7, false);
      board[15] = new Pawn(  'H', 7, false);
      
      
      
      for (int index = 16; index < 49; index++)
      {
         board[index] = new Space(Position::calculateCol(index), Position::calculateRow(index));
      }
      
      
      board[48] = new Pawn(  'A', 2, true);
      board[49] = new Pawn(  'B', 2, true);
      board[50] = new Pawn(  'C', 2, true);
      board[51] = new Pawn(  'D', 2, true);
      board[52] = new Pawn(  'E', 2, true);
      board[53] = new Pawn(  'F', 2, true);
      board[54] = new Pawn(  'G', 2, true);
      board[55] = new Pawn(  'H', 2, true);
      
      
      board[56] = new Rook(  'A', 1, true);
      board[57] = new Knight('B', 1, true);
      board[58] = new Bishop('C', 1, true);
      board[59] = new Queen( 'D', 1, true);
      board[60] = new King(  'E', 1, true);
      board[61] = new Bishop('F', 1, true);
      board[62] = new Knight('G', 1, true);
      board[63] = new Rook(  'H', 1, true);
   }
   Board(ogstream gout, bool reset) {}
   int getCurrentMove() { return currentMove; }
   bool whiteTurn() { return currentMove % 2; }
   void display(int posHover, int posSel) {}
   Piece * get(const Position & pos) { return board[pos.getLocation()]; }
   void free() {}
   void reset() {}
   void move(Move move) {}
   void setBoardArray(std::array<Piece*, 64>) {}
   void setBoardToEmpty()
   {
      for (int index = 0; index < 64; index++)
      {
         board[index] = new Space(Position::calculateCol(index), Position::calculateRow(index));
      }
   }
};
