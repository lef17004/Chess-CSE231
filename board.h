//
//  board.h
//  Lab01
//
//  Created by Michael LeFevre on 9/28/22.
//
#include <array>
#include "position.h"
#pragma once
class Piece {};


class Board
{
private:
   std::array<Piece, 64> board;
   int currentMove;
   ogstream gout;
   
   void swap(Position pos1, Position pos2) {}
   void assertBoard() {}
   
public:
   Board(ogstream gout, bool reset) {}
   int getCurrentMove() { return -1; }
   bool whiteTurn() { return false; }
   void display(int posHover, int posSel) {}
   Piece get(Position pos) { return * new Piece; }
   void free() {}
   void reset() {}
   //void move(Move move) {}

};
