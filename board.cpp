//
//  board.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "board.h"


Board::Board()
{
   for (int index = 0; index < 64; index++)
   {
      board[index] = new Space();
      board[index]->isWhite();
   }
}


void Board::setPiece(Piece * piece)
{
   board[piece->getPosition().getLocation()] = piece;
}

void Board::setPiece(Piece * piece, const Position & pos)
{
   piece->setPosition(pos);
   board[pos.getLocation()] = piece;
}

bool Board::isWhiteTurn() const
{
   return !(currentMove % 2);
}

Piece * Board::getPiece(const Position & pos) const
{
   return board[pos.getLocation()];
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

int Board::getCurrentMove() const
{
   return currentMove;
}

void Board::move(Move & move)
{
   Position source = move.getSrc();
   Position destination = move.getDes();
   
   swap(source, destination);
}


void Board::swap(const Position & pos1, const Position & pos2)
{
   Piece * temp = getPiece(pos1);
   setPiece(board[pos2.getLocation()], pos1);
   setPiece(temp, pos2);
   delete temp;
}
