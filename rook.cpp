#include "piece.h"


/******************************************************************************
 * ROOK:: GET POSSIBLE MOVES
 * Returns the possible moves for the rook.
 ******************************************************************************/
set<Move> Rook::getPossibleMoves(const Board& board)
{
   array<Delta, 8> deltas =
   { 
                  Delta(0,  1),
      Delta(-1, 0),           Delta(1, 0),
                  Delta(0, -1)
   };

   set<Move> moves = getMovesSlide(board, deltas);
   
   return  moves;
}
