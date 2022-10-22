//
//  queen.cpp
//  Lab01
//
//  Created by Michael LeFevre on 10/12/22.
//

#include "piece.h"


/******************************************************************************
 * QUEEN:: GET POSSIBLE MOVES
 * Returns a set of the Queen's possible moves.
 ******************************************************************************/
set<Move> Queen::getPossibleMoves(const Board& board)
{
   array<Delta, 8> deltas = 
   {  Delta(-1, 1),  Delta(0, 1),  Delta(1, 1),
      Delta(-1, 0),                Delta(1, 0),
      Delta(-1, -1), Delta(0, -1), Delta(1, -1) 
   };

   return getMovesSlide(board, deltas);
}
