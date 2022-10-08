//
//  testMove.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#pragma once
#include "move.h"
#include "position.h"

#define PAWN 'p'
#define KING 'k'
#define NONE 'M'

#include <iostream>
using namespace std;
class TestMove
{
public:
   void run()
   {
      test_getTextInitialMove();
      test_getTextCaptrue();
      test_getTextCastleKing();
      test_getTextCastleQueen();
      test_getTextEnpassant();
      test_getTextPromotion();
      test_lessThan1();
      test_lessThan2();
      test_SetSource();
      test_SetDestination();
      cout << "TestMove complete\n";
   }
   
   // Pawn Initial Move
   void test_getTextInitialMove()
   {
      // Setup
      Move move;
      move.piece = NONE;
      move.source = Position(1, 1);
      move.dest = Position(2, 1);
      move.enpassant = false;
      move.castleK = false;
      move.castleQ = false;
      move.isWhite = true;
      
      // Exercise
      string text = move.getText();
      
      // Verify
      assert(text == "b2b3");
      
      
   }
   
   // Captured Something
   void test_getTextCaptrue()
   {
      Move move;
      move.piece = PAWN;
      move.source = Position(5, 1);
      move.dest = Position(6, 0);
      move.enpassant = false;
      move.castleK = false;
      move.castleQ = false;
      move.isWhite = true;
      
      // Exercise
      string text = move.getText();
      
      // Verify
      assert(text == "b6a7p");
   }
   
   void test_getTextCastleKing()
   {
      Move move;
      move.piece = NONE;
      move.source = Position(0, 4);
      move.dest = Position(0, 6);
      move.enpassant = false;
      move.castleK = true;
      move.castleQ = false;
      move.isWhite = true;
      
      // Exercise
      string text = move.getText();
      
      // Verify
      assert(text == "e1g1c");
   }
   
   void test_getTextCastleQueen()
   {
      Move move;
      move.piece = NONE;
      move.source = Position(0, 4);
      move.dest = Position(0, 2);
      move.enpassant = false;
      move.castleK = false;
      move.castleQ = true;
      move.isWhite = true;
      
      // Exercise
      string text = move.getText();
      
      // Verify
      assert(text == "e1c1C");
   }
   
   void test_getTextEnpassant()
   {
      Move move;
      move.piece = NONE;
      move.source = Position(4, 1);
      move.dest = Position(5, 2);
      move.enpassant = true;
      move.castleK = false;
      move.castleQ = false;
      move.isWhite = true;
      
      // Exercise
      string text = move.getText();
      
      // Verify
      assert(text == "b5c6E");
   }
   
   void test_getTextPromotion()
   {
      Move move;
      move.piece = NONE;
      move.source = Position(6, 1);
      move.dest = Position(7, 1);
      move.enpassant = false;
      move.castleK = false;
      move.castleQ = false;
      move.isWhite = true;
      move.setPromotion();
      
      // Exercise
      string text = move.getText();
      
      // Verify
      assert(text == "b7b8Q");
   }
   
   void test_lessThan1()
   {
      // Setup
      Position testPos1;
      testPos1.location = 53;
      
      Position testPos2;
      testPos2.location = 55;
      
      Move testMove1;
      Move testMove2;
      
      testMove1.dest = testPos1;
      testMove2.dest = testPos2;
      
      // Exercise
      bool isLessThan = testMove1 < testMove2;
      
      // Verify
      assert(isLessThan);
   }
   
   void test_lessThan2()
   {
      // Setup
      Position testPos1;
      testPos1.location = 53;
      
      Position testPos2;
      testPos2.location = 55;
      
      Move testMove1;
      Move testMove2;
      
      testMove1.dest = testPos1;
      testMove2.dest = testPos2;
      
      // Exercise
      bool isLessThan = testMove2 < testMove1;
      
      // Verify
      assert(!isLessThan);
   }
   
   void test_SetSource()
   {
      // Setup
      Position position(0, 0);
      Move move;
      move.source = Position(5,5);
      
      // Exercise
      move.setSource(position);
      
      // Verify
      assert(move.source.getLocation() == 56);
      
   }
   
   void test_SetDestination()
   {
      // Setup
      Position position(0, 0);
      Move move;
      move.source = Position(5,5);
      
      // Exercise
      move.setDest(position);
      
      // Verify
      assert(move.dest.getLocation() == 56);
      
   }
};
