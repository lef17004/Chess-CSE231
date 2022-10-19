
#pragma once
#include "board.h"
#include "position.h"
#include "move.h"
#include <set>
#include "delta.h"
#include <memory>
#include "uiDraw.h"
using namespace std;


// Forward Declaration
class Board;


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
   
   bool isWhite() { return  fWhite; }
   bool isMove() { return nMoves > 0; }
   int getNMoves() { return nMoves; }
   Position & getPosition() { return position; }
   void setPosition(const Position & pos) { position = pos; }
   bool justMoved(int turnNumber);
   void move(const Position & position, int move);
   
   // Get Moves
   set<Move> * getMovesSlide(const Board & board, array<Delta, 8> deltas);
   set<Move> * getMovesNoSlide(const Board& board, array<Delta, 8> deltas);

   // Virtual Methods
   virtual char getLetter();
   virtual set<Move> * getPossibleMoves(const Board & board);
   virtual void display(ogstream & gout);

   
   // Friend Classes
   friend class TestPiece;
   friend class TestPawn;
   friend class TestKing;
};


class Pawn: public Piece
{
public:
   Pawn();
   Pawn(int r, int c, bool isWhite);
   void addPromotion(set<Move> &Moves, Move& move);
   
   virtual char getLetter() { return 'p'; }
   virtual set<Move> * getPossibleMoves(const Board & board);
   virtual void display(ogstream & gout);
   
   
   friend class TestPawn;
};


class Space: public Piece
{
public:
   Space() {}
   Space(int r, int c, bool isWhite): Piece(r, c, isWhite) {}
   
   virtual char getLetter() { return 's'; }
   virtual set<Move> * getPossibleMoves(const Board & board) { return new set<Move>(); };
   virtual void display(ogstream & gout) {}
};


class King: public Piece
{
public:
   King() {}
   King(int r, int c, bool isWhite): Piece(r, c, isWhite) {}
   
   virtual char getLetter() { return 'k'; }
   virtual set<Move> * getPossibleMoves(const Board & board);
   virtual void display(ogstream & gout) { gout.drawKing(position.getLocation(), !isWhite()); }
};


class Rook: public Piece
{
public:
   Rook();
   Rook(int r, int c, bool isWhite): Piece(r, c, isWhite) {};
   
   virtual char getLetter() { return 'r'; }
   virtual set<Move> * getPossibleMoves(const Board & board);
   virtual void display(ogstream & gout) { gout.drawRook(position.getLocation(), !isWhite()); }
};


class Knight: public Piece
{
public:
   Knight() {}
   Knight(int r, int c, bool isWhite): Piece(r, c, isWhite) {}
   
   virtual char getLetter() { return 'k'; }
   virtual set<Move> * getPossibleMoves(const Board & board);
   virtual void display(ogstream & gout) { gout.drawKnight(position.getLocation(), !isWhite()); }
};


class Bishop: public Piece
{
public:
   Bishop() {}
   Bishop(int r, int c, bool isWhite): Piece(r, c, isWhite) {}
   
   virtual char getLetter() { return 'b'; }
   virtual set<Move> * getPossibleMoves(const Board & board);
   virtual void display(ogstream & gout) { gout.drawBishop(position.getLocation(), !isWhite()); }
};


class Queen: public Piece
{
public:
   Queen() {}
   Queen(int r, int c, bool isWhite): Piece(r, c, isWhite) {}
   
   virtual char getLetter() { return 'b'; }
   virtual set<Move> * getPossibleMoves(const Board & board);
   virtual void display(ogstream & gout) { gout.drawQueen(position.getLocation(), !isWhite()); }
};
