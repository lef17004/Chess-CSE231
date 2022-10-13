//
//  queen.cpp
//  Lab01
//
//  Created by Michael LeFevre on 10/12/22.
//

#include "piece.h"
// TODO: Move to header file.
set<Move> * Knight::getPossibleMoves(const Board & board)
{
   array<Delta, 8> deltas = 
   {
  
                          Delta(- 1,  2), Delta( 1,  2),
           Delta(-2,  1),                             Delta( 2,  1),
           Delta(-2, -1),                             Delta( 2, -1),
                           Delta(- 1, -2), Delta(1, -2)
   };
   return new set<Move>();
}

/******************************************************************************
 * KNIGHT DISPLAY
 ******************************************************************************/
void Knight::display(ogstream& gout)
{
   gout.drawKnight(position.getLocation(), !isWhite());
}
