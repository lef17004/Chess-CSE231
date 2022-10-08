//
//  pawn.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#include "piece.h"
#include "delta.h"

Pawn::Pawn() { }

Pawn::Pawn(int r, int c, bool isWhite): Piece(r, c, isWhite) {}

set<Move> & Pawn::getPossibleMoves(const Board & board)
{
   set<Move> moves;
   Position posMove(getPosition(), isWhite() ? Delta(0, 1) : Delta(0, -1));
   Move move;
   if (posMove.isValid() && board.getPiece(posMove)->getLetter() == 's') {
      move.setSource(getPosition());
      move.setDest(posMove);
      move.setWhiteMove(isWhite());

      if (posMove.getRow() == 7 || posMove.getRow() == 0) {
         addPromotion(moves, move);
      }
      else {
         moves.insert(move);
      }
   }
   if (!isMove()) {
      Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
      Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());
      if (board.getPiece(posMove)->getLetter() == 's' && board.getPiece(posCheck)->getLetter() == 's') {
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         moves.insert(move);
      }
   }

   for (int i = -1; i <= 1; i++) {
      Position posMove(position.getRow() + isWhite() ? 1 : -1, position.getCol() + i);
      if (posMove.isValid() && board.getPiece(posMove)->getLetter() == 's' && board.getPiece(posMove)->isWhite() != isWhite()) {
         move.setSource(getPosition());
         move.setDest(posMove);
         move.setWhiteMove(isWhite());
         move.setCapture(board.getPiece(posMove)->getLetter());
         if (posMove.getRow() == 7 || posMove.getRow() == 0) {
            addPromotion(moves, move);
         }
         else {
            moves.insert(move);
         }
      }
   }

   for (int i = -1; i <= 1; i++) {
      Position posMove(position.getRow() + isWhite() ? 1 : -1, position.getCol() + i);
      Position posKill(position.getRow(), position.getCol() + i);
      if (posMove.isValid() && position.getRow() == isWhite() ? 4 : 3 && board.getPiece(posMove)->getLetter() == 's' &&
         board.getPiece(posKill)->getLetter() == 'p' && board.getPiece(posKill)->isWhite() != isWhite() &&
         board.getPiece(posKill)->getNMoves() == 1 && board.getPiece(posKill)->justMoved(board.getCurrentMove())) {
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

void Pawn::addPromotion(set<Move>& Moves, Move& move) {
   
}
