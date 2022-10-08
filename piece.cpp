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
 * PIECE::PIECE - Nondefault Constructor
 ******************************************************************************/
Piece::Piece(int r, int c, bool isWhite)
{
   position = Position(r, c);
   fWhite = isWhite;
   nMoves = 0;
   lastMove = -1;
}

/******************************************************************************
 * PIECE::GET LETTER
 * Get's the letter of the piece
 ******************************************************************************/
char Piece::getLetter()
{
   return 'M';
}

/******************************************************************************
 * PIECE::GET POSSIBLE MOVES
 *  Returns a set of moves for each move a piece can make
 ******************************************************************************/
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
