//
//  board.cpp
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#include "board.h"

/*
 Move to header on function at a time. If program does not compile after moving one, undo
 and talk to Brother Helfrich about it.
 */

/******************************************************************************
 * BOARD:: DEFAULT Constructo
 * Sets the board to normal game configuration.
 * TODO: Set up board with pieces in correct spots rather than spaces.
 *
 ******************************************************************************/
Board::Board()
{
   for (int index = 0; index < 64; index++)
   {
      board[index] = new Space();
      board[index]->isWhite();
   }
}

/******************************************************************************
 * BOARD:: SET PIECE
 * Places a piece in the board. Uses the piece's position.
 * TODO: One line, can be moved to header.
 ******************************************************************************/
void Board::setPiece(Piece * piece)
{
   board[piece->getPosition().getLocation()] = piece;
}

/******************************************************************************
 * BOARD:: SET PIECE
 * Places a piece in the board. Uses the provided location.
 * Also sets the position of piece to given position.
 ******************************************************************************/
void Board::setPiece(Piece * piece, const Position & pos)
{
   piece->setPosition(pos);
   board[pos.getLocation()] = piece;
}

/******************************************************************************
 * BOARD:: IS WHITE TURN
 * Returns true if white's turn, false if black's turn.
 * TODO: One line, move to header.
 ******************************************************************************/
bool Board::isWhiteTurn() const
{
   return !(currentMove % 2);
}

/******************************************************************************
 * BOARD:: GET PIECE
 * Returns pointer to piece at given location.
 * TODO: One line, move to header.
 ******************************************************************************/
Piece * Board::getPiece(const Position & pos) const
{
   return board[pos.getLocation()];
}

/******************************************************************************
 * BOARD:: SET BOARD TO EMPTY
 * Method used to make a completely empty baord. Used in unit tests..
 * TODO: Make private.
 ******************************************************************************/
void Board::setBoardToEmpty()
{
   for (int index = 0; index < 64; index++)
   {
      Position pos(index);
      int row = pos.getRow();
      int col = pos.getCol();
      board[index] = new Space(row, col, false);
   }
}

/******************************************************************************
 *BOARD:: FREE
 *Frees all the memory being used by board.
 *TODO: Figure out why program crashes if uncommented.
 ******************************************************************************/
void Board::free()
{
//   for (auto piece : board)
//      delete piece;
}

/******************************************************************************
 * BOARD:: GET CURRENT MOVE
 * Returns the current move of the game.
 * TODO: One line, move to header.
 ******************************************************************************/
int Board::getCurrentMove() const
{
   return currentMove;
}

/******************************************************************************
 * BOARD:: MOVE
 * Executes a move.
 * TODO: Needs finished. Only the most basic of movement is implemented.
 ******************************************************************************/
void Board::move(Move & move)
{
   Position source = move.getSrc();
   Position destination = move.getDes();
   
   swap(source, destination);
}

/******************************************************************************
 * BOARD:: SWAP
 * Swaps the positions of two pieces on the board. 
 ******************************************************************************/
void Board::swap(const Position & pos1, const Position & pos2)
{
   Piece * temp = getPiece(pos1);
   setPiece(board[pos2.getLocation()], pos1);
   setPiece(temp, pos2);
   delete temp;
}
