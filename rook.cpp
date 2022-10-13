
#include "piece.h"

Rook::Rook() {}
Rook::Rook(int r, int c, bool isWhite): Piece(r, c, isWhite) {}

/******************************************************************************
 * ROOK:: GET POSSIBLE MOVES
 * Gets the possible moves for the rook.
 * TODO: Implement this function. 
 ******************************************************************************/
set<Move> * Rook::getPossibleMoves(const Board & board)
{
   array<Delta, 8> deltas =
   { 
                  Delta(0,  1),
      Delta(-1, 0),           Delta(1, 0),
                  Delta(0, -1)
   };

   return new set<Move>();
}

/******************************************************************************
 * ROOK DISPLAY
 ******************************************************************************/
void Rook::display(ogstream& gout)
{
   gout.drawRook(position.getLocation(), !isWhite());
}
