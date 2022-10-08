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

set<Move> * King::getPossibleMoves(const Board & board)
{
   
   array<Delta, 8> deltas = {Delta(-1, 1),  Delta(0, 0),  Delta(1, 1),
                             Delta(-1, 0),                Delta(1, 0),
                             Delta(01, -1), Delta(0, -1), Delta(1, -1) };
	set<Move> moves = getMovesNoSlide(board, deltas);
   
	if (!isMove())
	{
		Position posSpace(position.getRow(), 5);
		Position posMove(position.getRow(), 6);
		Position posRook(position.getRow(), 7);

		if (board.getPiece(posMove)->getLetter() == 's' &&
			board.getPiece(posSpace)->getLetter() == 's' &&
			board.getPiece(posRook)->getLetter() == 'r' &&
			board.getPiece(posRook)->isMove() == false)
		{
			Move move;
			move.setSource(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCastle(true);
			moves.insert(move);
		}
	}

	if (!isMove())
	{
		Position posSpace1(position.getRow(), 3);
		Position posMove(position.getRow(), 2);
		Position posSpace2(position.getRow(), 1);
		Position posRook(position.getRow(), 0);

		if (board.getPiece(posMove)->getLetter() == 's' &&
			board.getPiece(posSpace1)->getLetter() == 's' &&
			board.getPiece(posSpace2)->getLetter() == 's' &&
			board.getPiece(posRook)->getLetter() == 'r' &&
			board.getPiece(posRook)->isMove() == false)
		{
			Move move;
			move.setSource(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			move.setCastle(true);
			moves.insert(move);
		}
	}

   return moves;
}
