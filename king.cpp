//
//  king.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#include "piece.h"
#include "delta.h"

King::King() { }

King::King(int r, int c, bool isWhite): Piece(r, c, isWhite) {}

set<Move> & King::getPossibleMoves(const Board & board)
{
   
   array<Delta, 8> deltas = {Delta(-1, 1),  Delta(0, 0),  Delta(1, 1),
                             Delta(-1, 0),                Delta(1, 0),
                             Delta(01, -1), Delta(0, -1), Delta(1, -1) };
   
   
   
   
   
   
   
   
   return *new set<Move>();
}
