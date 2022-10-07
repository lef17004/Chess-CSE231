//
//  space.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#include "piece.h"

Space::Space()
{
   
}

Space::Space(int r, int c, bool isWhite): Piece(r, c, isWhite)
{
   
}

set<Move> & Space::getPossibleMoves(const Board & board)
{
   Piece * p = board.getPiece(position);
   return *new set<Move>();
}

