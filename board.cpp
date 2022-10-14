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
   board[0] = new Rook(7, 0, false);
   board[1] = new Knight(7, 1, false);
   board[2] = new Bishop(7, 2, false);
   board[3] = new Queen(7, 3, false);
   board[4] = new King(7, 4, false);
   board[5] = new Bishop(7, 5, false);
   board[6] = new Knight(7, 6, false);
   board[7] = new Rook(7, 7, false);
   
   board[8] = new Pawn(6, 0, false);
   board[9] = new Pawn(6, 1, false);
   board[10] = new Pawn(6, 2, false);
   board[11] = new Pawn(6, 3, false);
   board[12] = new Pawn(6, 4, false);
   board[13] = new Pawn(6, 5, false);
   board[14] = new Pawn(6, 6, false);
   board[15] = new Pawn(6, 7, false);
   
   for (int positionIndex = 16; positionIndex < 48; positionIndex++)
   {
      Position position(positionIndex);
      board[position.getLocation()] = new Space(position.getRow(), position.getCol(), false);
   }
   
   board[48] = new Pawn(1, 0, true);
   board[49] = new Pawn(1, 1, true);
   board[50] = new Pawn(1, 2, true);
   board[51] = new Pawn(1, 3, true);
   board[52] = new Pawn(1, 4, true);
   board[53] = new Pawn(1, 5, true);
   board[54] = new Pawn(1, 6, true);
   board[55] = new Pawn(1, 7, true);
   
   board[56] = new Rook(0, 0, true);
   board[57] = new Knight(0, 1, true);
   board[58] = new Bishop(0, 2, true);
   board[59] = new Queen(0, 3, true);
   board[60] = new King(0, 4, true);
   board[61] = new Bishop(0, 5, true);
   board[62] = new Knight(0, 6, true);
   board[63] = new Rook(0, 7, true);
      
   
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
bool Board::move(Move & move)
{
   
   
   if (move.getSrc().getLocation() == -1 || move.getDes().getLocation() == -1)
      return false;
   
   return false;
   Position source = move.getSrc();
   Position destination = move.getDes();
   
   if (move.getCapture() == 's')
      swap(source, destination);
   
   currentMove++;
   
}



/******************************************************************************
 *
 ******************************************************************************/
bool Board::move(Position & positionFrom, Position & positionTo)
{
   if (!positionFrom.isValid() || !positionTo.isValid())
      return false;
   
   if (getPiece(positionFrom)->isWhite() != isWhiteTurn())
      return false;

   Piece * piece = getPiece(positionFrom);
   set<Move> * moves = piece->getPossibleMoves(*this);
   bool found = false;
   Move selectedMove;
   for (auto move: *moves)
   {
      if (move.getDes() == positionTo)
      {
         selectedMove = move;
         found = true;
      }
   }
   
   if (!found)
      return false;
      
   if (selectedMove.getCapture() == 'M')
      swap(positionFrom, positionTo);
   else
   {
      getPiece(positionFrom)->move(positionTo, currentMove);
      delete board[positionTo.getLocation()];
      board[positionTo.getLocation()] = getPiece(positionFrom);
      board[positionFrom.getLocation()] = new Space(positionFrom.getRow(), positionFrom.getCol(), false);
   }
   
   currentMove++;
   return true;
   
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
   //delete temp;
}

void Board::display(ogstream & gout)
{
   gout.drawBoard();
}

void Board::displayPieces(ogstream & gout)
{
   for (auto piece : board)
      piece->display(gout);
}


Piece & Board::operator[] (Position & pos)
{
   return *board[pos.getLocation()];
}
