//
//  queen.cpp
//  Lab01
//
//  Created by Michael LeFevre on 10/12/22.
//

#include "piece.h"
// TODO: Move to header file.
set<Move> * Bishop::getPossibleMoves(const Board & board)
{
   array<Delta, 8> deltas = 
   { 
      Delta(-1, 1),           Delta(1, 1),

      Delta(-1,-1),           Delta(1,-1)
   };

   return new set<Move>();
}

/******************************************************************************
 * BISHOP DISPLAY
 ******************************************************************************/
void Bishop::display(ogstream & gout)
{
   gout.drawBishop(position.getLocation(), !isWhite());
}
