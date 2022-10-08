//
//  rook.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#include "piece.h"

Rook::Rook() {}
Rook::Rook(int r, int c, bool isWhite): Piece(r, c, isWhite) {}
set<Move> * Rook::getPossibleMoves(const Board & board)
{
   return new set<Move>();
}
