//
//  piece.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "piece.h"
#include <iostream>

Piece::Piece()
{
   position = Position();
   fWhite = false;
   nMoves = 0;
   lastMove = -1;
}

Piece::Piece(int r, int c, bool isWhite)
{
   position = Position(r, c);
   fWhite = isWhite;
   nMoves = 0;
   lastMove = -1;
}

char Piece::getLetter()
{
   return 'M';
}

set<Move> & Piece::getPossibleMoves(const Board & board)
{
   board.isWhiteTurn();
   Move move;
   set<Move> * moveSet = new set<Move>();
   move.setSource(Position(0, 0));
   move.setDest(Position(1, 0));
   moveSet->insert(move);
   return *moveSet;
}

void Piece::useBoard(Board & board)
{
   board.setPiece(this);
}

void Piece::displayPiece()
{
   std::cout << "Piece\n" << std::endl;
}

bool Piece::justMoved(int turnNumber)
{
   return ((lastMove + 1) == turnNumber) ||
          ((lastMove + 2) == turnNumber);
   
}

set<Move> & Piece::getMovesSlide(const Board & board, array<Delta, 8> deltas)
{
   for (Delta delta : deltas)
   {
      
   }
   return *new set<Move>();
}
