/******************************************************************************
 * Header File:
 *    Move : handles the logic of the piece movements and game rules
 * 
 * Lab01
 *
 * Created by Michael LeFevre on 9/28/22.
 *******************************************************************************/


#pragma once

#include "position.h"
#include <string>

// Forward Declaration. Delete and die from errors. 
class Board;

 /******************************************************************************
  * MOVE
  * Game rules and movements Logic
  ******************************************************************************/
class Move
{
private:
   Position source;
   Position dest;
   char piece;
   char capture;
   bool enpassant;
   bool castleK;
   bool castleQ;
   bool isWhite;
   string error;
   
public:
   // Getters
   Move() {}
   Move(Position & position, vector<int> & delta)
   {
      dest = position;
      dest.set((char)(position.getColumn() + delta[0]), position.getRow() + delta[1]);
   }
   string getText()           const { return "Michael"; }
   const Position & getSrc()  const { return source; }
   const Position & getDes()  const { return dest; }
   char getPromotion()        const { return piece; }
   char getCapture()          const { return capture; }
   bool getEnPassant()        const { return enpassant; }
   bool getCastleK()          const { return castleK; }
   bool getCastleQ()          const { return castleQ; }
   bool getWhiteMove()        const { return isWhite; }

   // Setters
   void getCapture(char letter) { capture = tolower(letter); }
   void setWhiteMove(bool f) { isWhite = f; }
   void setSrc(const Position & src) { source = src; }
   void setDes(const Position& des) { dest = des; }
   void setEnPassant() { enpassant = true; }
   void setPromote(char letter) { piece = letter; }
   void complete(const Board & board) {}
   void setCastle(bool isKing)
   {
      if (isKing)
         castleK = true;
      else
         castleQ = true;
   };
   
   void assign(Move move) {}
   void assign(string move) {}
   // operator <<()
   // operator >>()
   // friend ostream & operator << (ostream& out, Move & rhs);
   // friend istream & operator >> (istream& in, Move& rhs);
   
   bool operator < (const Move & rhs) const
   {
      return dest.getLocation() < rhs.dest.getLocation();
   }
   //const Move & operator = (const Move & rhs);
   const Move & operator = (const string& s)
   {
      //read(s);
      return *this;
   }
   const Move & operator = (const char* s)
   {
      const string str(s);
      //read(str);
      return *this;
   }
};
