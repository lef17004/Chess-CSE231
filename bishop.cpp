//
//  queen.cpp
//  Lab01
//
//  Created by Michael LeFevre on 10/12/22.
//

#include "piece.h"

/******************************************************************************
 * BISHOP::GET POSSIBLE MOVES
 * Returns a set of moves for Bishop.
 ******************************************************************************/
set<Move>* Bishop::getPossibleMoves(const Board& board)
{
   array<Delta, 8> deltas = 
   { 
      Delta(-1, 1),           Delta(1, 1),

      Delta(-1,-1),           Delta(1,-1)
   };

   return getMovesSlide(board, deltas);
}