//
//  pawn.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#include "piece.h"

Pawn::Pawn() { }

Pawn::Pawn(int r, int c, bool isWhite): Piece(r, c, isWhite) {}

set<Move> & Pawn::getPossibleMoves(const Board & board)
{
   return *new set<Move>();
}
