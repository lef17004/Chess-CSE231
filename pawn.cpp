#include "piece.h"
#include "delta.h"
#include <iostream>

/******************************************************************************
 * PAWN:: GET POSSIBLE MOVES
 * Gets the possible moves for the pawn.
 ******************************************************************************/
set<Move>  Pawn::getPossibleMoves(const Board & board)
{
   set<Move> moves;
   Position posMove(getPosition(), isWhite() ? Delta(0, 1) : Delta(0, -1));
   Move move;
   
   // Single Space Move
   if (posMove.isValid() && board.getPiece(posMove)->getLetter() == 's')
   {
      move.setSource(getPosition());
      move.setDest(posMove);
      move.setWhiteMove(isWhite());

      if (posMove.getRow() == 7 || posMove.getRow() == 0)
      {
         addPromotion(moves, move);
      }
      else
      {
         moves.insert(move);
      }
   }
   
   // Double Space Move
   if (!isMove())
   {
      Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
      Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());
      if (board.getPiece(posMove)->getLetter() == 's' && board.getPiece(posCheck)->getLetter() == 's')
      {
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         moves.insert(move);
      }
   }
  
   
   
   int values[2] = {-1, 1};
   
   // Capture Moves
   for (auto i : values)
   {
      Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
      if (posMove.isValid() && board.getPiece(posMove)->getLetter() != SPACE && board.getPiece(posMove)->isWhite() != isWhite())
      {
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(board.getPiece(posMove)->getLetter());
         if (posMove.getRow() == 7 || posMove.getRow() == 0)
         {
            addPromotion(moves, move);
         }
         else
         {
            moves.insert(move);
         }
      }
   }
   
   // En Passant
   for (auto i : values)
   {
      Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + i);
      Position posKill(position.getRow(), position.getCol() + i);
      
      
      if (posMove.isValid() && (position.getRow() == (isWhite() ? 4 : 3)) && board.getPiece(posMove)->getLetter() == SPACE &&
         board.getPiece(posKill)->getLetter() == PAWN && board.getPiece(posKill)->isWhite() != isWhite() &&
         board.getPiece(posKill)->getNMoves() == 1 && board.getPiece(posKill)->justMoved(board.getCurrentMove()))
      {
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(board.getPiece(posMove)->getLetter());
         move.setEnPassant();
         moves.insert(move);
      }
   }
   return moves;
}

/******************************************************************************
 * PAWN:: ADD PRMOTION
 * The logic to promote a pawn. 
 ******************************************************************************/
void Pawn::addPromotion(set<Move> & Moves, Move& move)
{
   move.setPromotion();
   Moves.insert(move);
}

/******************************************************************************
 * PAWN DISPLAY
 * Displays Pawns on the UI
 ******************************************************************************/
void Pawn::display(ogstream& gout)
{
   gout.drawPawn(position.getLocation(), !isWhite());
}
