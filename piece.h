#pragma once

#include "board.h"
#include "position.h"
#include "move.h"
#include <set>
#include "delta.h"
#include <memory>
#include "uiDraw.h"
using namespace std;

const char SPACE = 's';
const char PAWN = 'p';
const char ROOK = 'r';
const char BISHOP = 'b';
const char KNIGHT = 'n';
const char QUEEN = 'Q';
const char KING = 'k';
const char UNDEFINED_PIECE = 'M';



// Forward Declaration
class Board;
class Queen;


// Do not make a Piece object. It should be abstract, but we are keeping it not abstract for the sake of unit tests.
// Ask Brother Helfrich for suggestions of how to test abstract class. 
class Piece
{
protected:
   Position position;
   bool fWhite;
   int nMoves;
   int lastMove;

public:
   Piece();
   Piece(int r, int c, bool isWhite);
   ~Piece() {}
   
   bool isWhite() { return  fWhite; }
   bool isMove() { return nMoves > 0; }
   int getNMoves() { return nMoves; }
   Position& getPosition() { return position; }
   void setPosition(const Position& pos) { position = pos; }
   bool justMoved(int turnNumber);
   void move(const Position& position, int move);

   // Get Moves
   set<Move> getMovesSlide(const Board& board, array<Delta, 8> deltas);
   set<Move> getMovesNoSlide(const Board& board, array<Delta, 8> deltas);

   // Virtual Methods
   virtual char getLetter() { return UNDEFINED_PIECE; }
   virtual set<Move> getPossibleMoves(const Board& board);
   virtual void display(ogstream& gout);

   // Friend Classes
   friend class TestPiece;
   friend class TestPawn;
   friend class TestKing;
};



class Space : public Piece
{
public:
   Space(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}

   virtual char getLetter() { return SPACE; }
   virtual void display(ogstream& gout) {}
};

class King : public Piece
{
public:
   King(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}

   virtual char getLetter() { return KING; }
   virtual set<Move> getPossibleMoves(const Board& board);
   virtual void display(ogstream& gout) { gout.drawKing(position.getLocation(), !isWhite()); }
};

class Rook : public Piece
{
public:
   Rook(int r, int c, bool isWhite) : Piece(r, c, isWhite) {};

   virtual char getLetter() { return ROOK; }
   virtual set<Move> getPossibleMoves(const Board& board);
   virtual void display(ogstream& gout) { gout.drawRook(position.getLocation(), !isWhite()); }
};

class Knight : public Piece
{
public:
   Knight(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}

   virtual char getLetter() { return KNIGHT; }
   virtual set<Move> getPossibleMoves(const Board& board);
   virtual void display(ogstream& gout) { gout.drawKnight(position.getLocation(), !isWhite()); }
};

class Bishop : public Piece
{
public:
   Bishop(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}

   virtual char getLetter() { return BISHOP; }
   virtual set<Move> getPossibleMoves(const Board& board);
   virtual void display(ogstream& gout) { gout.drawBishop(position.getLocation(), !isWhite()); }
};

class Queen : public Piece
{
public:
   Queen(int r, int c, bool isWhite) : Piece(r, c, isWhite) {}

   virtual char getLetter() { return QUEEN; }
   virtual set<Move> getPossibleMoves(const Board& board);
   virtual void display(ogstream& gout) { gout.drawQueen(position.getLocation(), !isWhite()); }
};

class Pawn : public Piece
{
public:
   Pawn(int r, int c, bool isWhite): Piece(r, c, isWhite) {}
   void addPromotion(set<Move> &Moves, Move& move);
   
   virtual char getLetter() { return PAWN; }
   virtual set<Move> getPossibleMoves(const Board& board);
   virtual void display(ogstream& gout);
   
   Piece * promote(const Position & pos, bool color)
   {
      Piece * pQueen = new Queen(pos.getRow(), pos.getCol(), color);
      
      // Make setter instead of weird cast thing.
      ((Pawn*)pQueen)->nMoves = nMoves;
      ((Pawn*)pQueen)->lastMove = lastMove;
      return pQueen;
   }
   
   friend class TestPawn;
};
