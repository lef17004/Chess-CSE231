
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
   return new set<Move>();
}

void Rook::display(ogstream& gout)
{
   gout.drawRook(position.getLocation(), !isWhite());
}
