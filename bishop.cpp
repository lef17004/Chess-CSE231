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
   return new set<Move>();
}

void Piece::display(ogstream& gout)
{
   gout.drawBishop(position.getLocation(), !isWhite());
}
