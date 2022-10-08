
#include "piece.h"

/******************************************************************************
 * Ok, this file isn't needed and everything can be moved to the header.
 * It was created for a good reason and was needed at the time.
 * Now it isn't and can be removed.
 ******************************************************************************/

// TODO: Move to header file.
Space::Space()
{
   
}

// TODO: Move to header file.
Space::Space(int r, int c, bool isWhite): Piece(r, c, isWhite)
{
   
}

// TODO: Move to header file.
set<Move> * Space::getPossibleMoves(const Board & board)
{
   return new set<Move>();
}

