/******************************************************************************\
 * Header File:
 *    Piece : Representation of a basic peice object
 * 
 * Lab01
 *
 * Created by Jane Orr on 9/28/22.
 *******************************************************************************/

#pragma once

#include "board.h"
#include <set>
#include <vector>
#include "move.h"
#include "uiDraw.h"
using namespace std;

// Forward Declaraion. Keep unless you want lots of errors.
class Board;

enum PieceType
{
   SPACE,
   BLANK,
   PAWN,
   ROOK,
   BISHOP,
   KNIGHT,
   QUEEN,
   KING
};

 /******************************************************************************
  * PIECE
  * represents a basic playable piece on the board
  ******************************************************************************/
class Piece
{
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;
   PieceType type;
   
   friend class TestPawn;
   friend class TestKing;

public:
   Piece(char colLetter, char rowNumber, bool white)
   {
      position = Position(colLetter, rowNumber);
      fWhite = white;
      lastMove = -1;
      nMoves = 0;
   }
   virtual ~Piece() {};
   void assign(Position position) {}
   void assign(Piece & piece) {}
   bool isWhite() { return fWhite;  }
   int getNMoves() { return nMoves; }
   Position & getPosition() { return position; }
   bool justMoved(int currentTurn) { return currentTurn == lastMove + 1; }
   
   virtual char getLetter() = 0;
   virtual void display(ogstream & gout) = 0;
   virtual set<Move> getMoves(Board & board) = 0;

   set<Move> getMovesSlide(Board& board, vector<vector<int>> delta)
   {
      set<Move> moves;
      for (int i = 0; i < delta.size(); i++)
      {
         Position posMove(position, delta[i]);
         Move move;
         while ((posMove.isValid()) && (board[posMove] && type == SPACE))
         {
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            moves.insert(move);
         }

         if (posMove.isValid() && (board[posMove]));
      }
      return *new set<Move>();
   }
   
};

class Pawn: public Piece
{
public:
   Pawn(char colLetter, char rowNumber, bool white): Piece(colLetter, rowNumber, white)
   {
      type = PAWN;
   }
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

   
class Rook: public Piece
{
public:
   Rook(char colLetter, char rowNumber, bool white): Piece(colLetter, rowNumber, white)
   {
      type = ROOK;
   }
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class Knight: public Piece
{
public:
   Knight(char colLetter, char rowNumber, bool white): Piece(colLetter, rowNumber, white)
   {
      type = KNIGHT;
   }
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class Bishop: public Piece
{
public:
   Bishop(char colLetter, char rowNumber, bool white): Piece(colLetter, rowNumber, white)
   {
      type = BISHOP;
   }
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class King: public Piece
{
public:
   King(char colLetter, char rowNumber, bool white): Piece(colLetter, rowNumber, white)
   {
      type = KING;
   }
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
   
   friend class TestKing;
};

class Queen: public Piece
{
public:
   Queen(char colLetter, char rowNumber, bool white): Piece(colLetter, rowNumber, white)
   {
      type = QUEEN;
   }
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};

class Space: public Piece
{
public:
   Space(char colLetter, char rowNumber): Piece(colLetter, rowNumber, false)
   {
      type = SPACE;
   }
   virtual char getLetter() { return 'M'; }
   virtual void display(ogstream & gout) {}
   virtual set<Move> getMoves(Board & board) { return *new set<Move>; }
};
