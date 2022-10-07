//
//  board.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "board.h"


Board::Board()
{
   makePiece();
   
   for (int index = 0; index < 64; index++)
   {
      board[index] = new Space();
      board[index]->isWhite();
   }
   
   
}



Piece & Board::getPiece()
{
   return *this->piece;
}

void Board::setPiece(Piece * piece)
{
   board[piece->getPosition().getLocation()] = piece;
}

Piece & Board::makePiece()
{
   return *new Piece();
}

bool Board::isWhiteTurn() const
{
   return !(currentMove % 2);
}

Piece * Board::getPiece(const Position & pos) const
{
   Piece * pawn = new Pawn();
   Piece * piece = new Piece();
   pawn->getNMoves();
   piece->isMove();
   return board[pos.getLocation()];
   return new Piece();
}

void Board::setBoardToEmpty()
{
   for (int index = 0; index < 64; index++)
   {
      Position pos(index);
      int row = pos.getRow();
      int col = pos.getCol();
      board[index] = new Space(row, col, false);
   }
}

void Board::free()
{
//   for (auto piece : board)
//      delete piece;
}

int Board::getCurrentMove()
{
   return currentMove;
}

void Board::move(const Move & move)
{
   
}
