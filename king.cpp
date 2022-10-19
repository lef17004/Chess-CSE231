#include "piece.h"
#include "delta.h"


/******************************************************************************
 * KING::GET POSSIBLE MOVES
 *  Returns the possible moves for the King.
 ******************************************************************************/
set<Move>* King::getPossibleMoves(const Board& board)
{

   // Moves the King can make
   array<Delta, 8> deltas =
   {
      Delta(-1, 1),  Delta(0, 1),  Delta(1, 1),
      Delta(-1, 0),                Delta(1, 0),
      Delta(-1, -1), Delta(0, -1), Delta(1, -1)
   };

   set<Move>* moves = getMovesNoSlide(board, deltas);

   // King side caslte
   if (!isMove())
   {
      Position posSpace(position.getRow(), 5);
      Position posMove(position.getRow(), 6);
      Position posRook(position.getRow(), 7);

      if (board.getPiece(posMove)->getLetter() == 's' &&
         board.getPiece(posSpace)->getLetter() == 's' &&
         board.getPiece(posRook)->getLetter() == 'r' &&
         board.getPiece(posRook)->isMove() == false)
      {
         Move move;
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle(true);
         moves->insert(move);
      }
   }

   // Queen side castle 
   if (!isMove())
   {
      Position posSpace1(position.getRow(), 3);
      Position posMove(position.getRow(), 2);
      Position posSpace2(position.getRow(), 1);
      Position posRook(position.getRow(), 0);

      if (board.getPiece(posMove)->getLetter() == 's' &&
         board.getPiece(posSpace1)->getLetter() == 's' &&
         board.getPiece(posSpace2)->getLetter() == 's' &&
         board.getPiece(posRook)->getLetter() == 'r' &&
         board.getPiece(posRook)->isMove() == false)
      {
         Move move;
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCastle(false);
         moves->insert(move);
      }
   }

   return moves;
}
