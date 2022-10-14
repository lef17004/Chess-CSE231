//
//  piece.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "piece.h"
#include <iostream>

/******************************************************************************
 * PIECE::PIECE - Default Constructor
 ******************************************************************************/
Piece::Piece()
{
   position = Position();
   fWhite = false;
   nMoves = 0;
   lastMove = -1;
}

/******************************************************************************
 * PIECE::PIECE - Nondefault Constructor
 ******************************************************************************/
Piece::Piece(int r, int c, bool isWhite)
{
   position = Position(r, c);
   fWhite = isWhite;
   nMoves = 0;
   lastMove = -1;
}

/******************************************************************************
 * PIECE::GET LETTER
 * Get's the letter of the piece
 ******************************************************************************/
char Piece::getLetter()
{
   return 'M';
}

/******************************************************************************
 * PIECE::GET POSSIBLE MOVES
 *  Returns a set of moves for each move a piece can make
 ******************************************************************************/
set<Move> * Piece::getPossibleMoves(const Board & board)
{
   board.isWhiteTurn();
   Move move;
   set<Move> * moveSet = new set<Move>();
   move.setSource(Position(0, 0));
   move.setDest(Position(1, 0));
   moveSet->insert(move);
   return moveSet;
}


/******************************************************************************
 * Tempory Method to ensure code would compile.
 ******************************************************************************/
void Piece::display(ogstream & gout)
{
   std::cout << "Piece\n" << std::endl;
   gout.drawPawn(position.getLocation(), !isWhite());
}

/******************************************************************************
 * PIECE: JUST MOVED
 *  Check to see if a piece has moved on the previous turn.
 ******************************************************************************/
bool Piece::justMoved(int turnNumber)
{
	return ((lastMove + 1) == turnNumber) ||
          ((lastMove + 2) == turnNumber);
   
}

/******************************************************************************
 * PIECE:: GET MOVES SLIDE
 *  Uses delta to get all the moves in a sliding pattern.
 ******************************************************************************/
set<Move> * Piece::getMovesSlide(const Board & board, array<Delta, 8> deltas)
{
   set<Move> * moves = new set<Move>();
   for (Delta delta : deltas)
   {
      Position posMove(position, delta);
		while (posMove.isValid() && board.getPiece(posMove.getLocation())->getLetter() == 's')
		{
			Move move;
			move.setSource(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			moves->insert(move);
         posMove = Position(posMove.getRow() + delta.y, posMove.getCol() + delta.x);
		}
     
      
      
//		if (posMove.isValid() &&
//			((board.getPiece(position))->isWhite() != fWhite || board.getPiece(posMove.getLocation())->getLetter() != 's'))
      if (posMove.isValid() && board.getPiece(posMove)->isWhite() != fWhite)
		{
			Move move;
			move.setSource(getPosition());
			move.setDest(posMove);
			move.setWhiteMove(isWhite());
			if (board.getPiece(position)->getLetter() != 's')
			{
				move.setCapture(board.getPiece(position)->getLetter());
			}
			moves->insert(move);
		}
   }
   return moves;
}

/******************************************************************************
 * PIECE:: GET MOVES NO SLIDE
 * Returns set of moves using a delta.
 ******************************************************************************/
set<Move> * Piece::getMovesNoSlide(const Board& board, array<Delta, 8> deltas)
{
	set<Move> * moves = new set<Move>;
	for (Delta delta : deltas)
	{
		Position posMove(position, delta);
      
      bool isValid = posMove.isValid();
     
      if (isValid)
      {
         bool isWhite2 = board.getPiece(posMove)->isWhite() != fWhite;
         bool isSpace = board.getPiece(posMove.getLocation())->getLetter() == 's';
         if ((isWhite2 || isSpace))
         {
            Move move;
            move.setSource(getPosition());
            move.setDest(posMove);
            move.setWhiteMove(isWhite());
            if (board.getPiece(posMove)->getLetter() != 's')
            {
               move.setCapture(board.getPiece(posMove)->getLetter());
            }
            moves->insert(move);
         }
      }
      
      
	}
	return moves;

}


void Piece::move(const Position & position, int turn)
{
   this->position = position;
   nMoves += 1;
   lastMove = turn;
}
