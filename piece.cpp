//
//  piece.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "piece.h"
#include <iostream>


/******************************************************************************
 * PIECE::PIECE - Default Constructor
 ******************************************************************************/
Piece::Piece()
{
   position = Position();
   fWhite = false;
   nMoves = 0;
   lastMove = -1;
}

/******************************************************************************
 * PIECE::PIECE - Non-Default Constructor
 ******************************************************************************/
Piece::Piece(int r, int c, bool isWhite)
{
   position = Position(r, c);
   fWhite = isWhite;
   nMoves = 0;
   lastMove = -1;
}


/******************************************************************************
 * PIECE::GET POSSIBLE MOVES
 * Returns a set of moves for each move a piece can make
 ******************************************************************************/
set<Move> Piece::getPossibleMoves(const Board& board)
{
   set<Move> moveSet;
   return moveSet;
}

/******************************************************************************
 * Tempory Method to ensure code would compile.
 ******************************************************************************/
void Piece::display(ogstream& gout)
{

}

/******************************************************************************
 * PIECE: JUST MOVED
 * Checks to see if a piece has moved on the previous turn.
 ******************************************************************************/
bool Piece::justMoved(int turnNumber)
{
   return ((lastMove + 1) == turnNumber) ||
      ((lastMove + 2) == turnNumber);
}

/******************************************************************************
 * PIECE:: GET MOVES SLIDE
 * Uses delta to get all the moves in a sliding pattern.
 ******************************************************************************/
set<Move> Piece::getMovesSlide(const Board& board, array<Delta, 8> deltas)
{
   set<Move> moves;
   for (Delta delta : deltas)
   {
      Position posMove(position, delta);
      while (posMove.isValid() && board.getPiece(posMove.getLocation())->getLetter() == SPACE)
      {
         Move move;
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         moves.insert(move);
         posMove = Position(posMove.getRow() + delta.y, posMove.getCol() + delta.x);
      }

      // Handle capture
      if (posMove.isValid() && board.getPiece(posMove)->isWhite() != fWhite)
      {
         Move move;
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         if (board.getPiece(position)->getLetter() != SPACE)
         {
            move.setCapture(board.getPiece(position)->getLetter());
         }
         moves.insert(move);
      }
   }
   return moves;
}

/******************************************************************************
 * PIECE:: GET MOVES NO SLIDE
 * Returns set of moves using a delta.
 ******************************************************************************/
set<Move>  Piece::getMovesNoSlide(const Board& board, array<Delta, 8> deltas)
{
   set<Move> moves;
   for (Delta delta : deltas)
   {
      Position posMove(position, delta);

      bool isValid = posMove.isValid();

      if (isValid)
      {
         bool isWhite2 = board.getPiece(posMove)->isWhite() != fWhite;
         bool isSpace = board.getPiece(posMove.getLocation())->getLetter() == SPACE;
         if ((isWhite2 || isSpace))
         {
            Move move;
            move.setSource(getPosition());
            move.setDest(posMove);
            move.setWhiteMove(isWhite());
            if (board.getPiece(posMove)->getLetter() != SPACE)
            {
               move.setCapture(board.getPiece(posMove)->getLetter());
            }
            moves.insert(move);
         }
      }
   }
   return moves;
}


/******************************************************************************
 * PIECE::MOVE
 * Sets a piece to its new postion, updates the turn number and number of moves. 
 ******************************************************************************/
void Piece::move(const Position& position, int turn)
{
   this->position = position;
   nMoves += 1;
   lastMove = turn;
}
