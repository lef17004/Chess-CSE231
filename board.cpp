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
      
   currentMove = 0;
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
   //piece->setPosition(pos);
   piece->move(pos, currentMove);
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
   {
      return false;
   }
   
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
      
   // Move to blank spot
   if (selectedMove.getCapture() == 'M')
      swap(positionFrom, positionTo);
   // Capture
   else
   {
      
      Piece * piece1 = getPiece(positionFrom);
      Piece * piece2 = getPiece(positionTo);
      
      delete piece2;
      setPiece(piece1, positionTo);
      setPiece(new Space(positionFrom.getRow(), positionFrom.getCol(), false), positionFrom);
//      
//      getPiece(positionFrom)->move(positionTo, currentMove);
//      delete board[positionTo.getLocation()];
//      board[positionTo.getLocation()] = getPiece(positionFrom);
//      board[positionFrom.getLocation()] = new Space(positionFrom.getRow(), positionFrom.getCol(), false);
//      board[positionTo.getLocation()]->move(positionTo, currentMove);
   }
   
   // Promotion
   if (selectedMove.getPromotion() != 'M')
   {
      Piece * pawn = board[positionTo.getLocation()];
      Piece * queen = new Queen(pawn->getPosition().getRow(), pawn->getPosition().getCol(), pawn->isWhite());
      // TODO: Need copy constructor
      delete pawn;
      setPiece(queen, positionTo);
      //board[positionTo.getLocation()] = queen;
      
   }
   
   std::array<std::array<Position, 2>, 4> castlingPositions = {
      // Space(rook move to)   Rook
      {Position(61),           Position(63),  // White King side Castle  - castleType = 0
       Position(5),            Position(7),   // Black King side Castle  - castleType = 1
       Position(56),           Position(59),  // White Queen side Castle - castleType = 2
       Position(3),            Position(0)    // Black Queen side Castle - castleType = 3
      }
   };
   
   // Castling
   if (selectedMove.getCastleK() || selectedMove.getCastleQ())
   {
      int castleType = 0;
      //if white, and selected move is Kings side castle
      if (selectedMove.getWhiteMove() && selectedMove.getCastleK())
         castleType = 0;

      //if white, and selected move is Queens side castle
      else if (selectedMove.getWhiteMove() && selectedMove.getCastleQ())
         castleType = 2;

      //if NOT white(AKA black), and selected move is Kings side castle
      else if (!selectedMove.getWhiteMove() && selectedMove.getCastleK())
         castleType = 1;

      //if NOT white(AKA black), and selected move is Queens side castle
      else if (!selectedMove.getWhiteMove() && selectedMove.getCastleQ())
         castleType = 3;
      
      swap(castlingPositions[castleType][0], castlingPositions[castleType][1]);
      
   }
   
   if (selectedMove.getEnPassant())
   {
      int positionChange = isWhiteTurn() ? -1 : 1;
      Position posKill(positionTo.getRow() + positionChange, positionTo.getCol());
      delete getPiece(posKill);
      setPiece(new Space(posKill.getRow(), posKill.getCol(), false), posKill);
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
   Piece * piece1 = getPiece(pos1);
   Piece * piece2 = getPiece(pos2);
   //Piece * temp = piece1;
   
   //piece1->move(pos2, currentMove);
   //piece2->move(pos1, currentMove);
   
   setPiece(piece2, pos1);
   setPiece(piece1, pos2);
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
