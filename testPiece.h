//
//  testPiece.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#pragma once
#include "piece.h"
#include <iostream>
#include <set>
#include "move.h"
using namespace std;

class TestPiece
{
public:
   void run()
   {
      test_DefaultConstructor();
      test_NonDefaultConstructor();
      test_JustMovedTrue();
      test_JustMovedTrueOpponent();
      test_JustMovedFalse();
      test_GetPossibleMoves();
      
      cout << "TestPiece Complete" << endl;
   }
   
   // Test Deault Constructor
   void test_DefaultConstructor()
   {
      // Setup
      Piece * piece = new Piece();
      
      // Verify
      assert(piece->position == Position(0,0));
      assert(piece->fWhite == false);
      assert(piece->nMoves == 0);
      assert(piece->lastMove == -1);
      
      // Teardown
      delete piece;
   }
   
   // Test that Non default constructor works correctly.
   void test_NonDefaultConstructor()
   {
      // Setup
      Piece * piece = new Piece(7, 6, true);
      
      // Verify
      assert(piece->position == Position(7,6));
      assert(piece->fWhite == true);
      assert(piece->nMoves == 0);
      assert(piece->lastMove == -1);
      
      // Teardown
      delete piece;
   }
   
   // Tests if player moved last turn on their next turn
   void test_JustMovedTrue()
   {
      // Setup
      int turnNumber = 4;
      Piece * piece = new Piece();
      piece->nMoves = 2;
      piece->lastMove = 2;
      piece->fWhite = true;
      piece->position = Position(0,0);
      
      // Exercise
      bool movedLastTurn = piece->justMoved(turnNumber);
      
      // Verify
      //assert(movedLastTurn == true);
      
      // Teardown
      delete piece;
      
   }
   
   // Tests if player moved last turn on opponents turn
   void test_JustMovedTrueOpponent()
   {
      // Setup
      int turnNumber = 3;
      Piece * piece = new Piece();
      piece->nMoves = 2;
      piece->lastMove = 2;
      piece->fWhite = true;
      piece->position = Position(0,0);
      
      // Exercise
      bool movedLastTurn = piece->justMoved(turnNumber);
      
      // Verify
      assert(movedLastTurn == true);
      
      // Teardown
      delete piece;
      
   }
   
   // Tests if player just moved. False condition. 
   void test_JustMovedFalse()
   {
      // Setup
      int turnNumber = 10;
      Piece * piece = new Piece();
      piece->nMoves = 2;
      piece->lastMove = 2;
      piece->fWhite = true;
      piece->position = Position(0,0);
      
      // Exercise
      bool movedLastTurn = piece->justMoved(turnNumber);
      
      // Verify
      assert(movedLastTurn == false);
      
      // Teardown
      delete piece;
      
   }
   
   void test_GetPossibleMoves()
   {
      // Setup
      Board board;
      Piece * piece = new Piece();
      
      // Exercise
      auto moveSet = piece->getPossibleMoves(board);
      
      // Verify
      assert(moveSet.size() == 1);
      
      set<string> * moves = compileMoves(moveSet);
      assert(moves->find("a1a2") != moves->end());
      
      // Teardown
      delete piece;
      delete moves;
   }
   
   /**************************************************************************
    * Converts the moves into string set's to more easily verify that the
    * moves are correct
    ***************************************************************************/
   set<string> * compileMoves(const set<Move> & moves)
   {
      std::set<string> * movesAsStrings = new set<string>;
      for (Move move: moves)
      {
         movesAsStrings->insert(move.getText());
      }
      return movesAsStrings;
   }
   
};
