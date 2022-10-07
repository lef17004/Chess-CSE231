//
//  testPawn.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#pragma once

#include "piece.h"

#include <iostream>
using namespace std;

class TestPawn
{
public:
   void run()
   {
      test_DefaultConstructor();
      test_pawnBlocked();
      test_pawnSimpleMove();
      test_pawnPromotion();
      test_PawnEnpassant();
      testPawnCapture();
      cout << "TestPawn Completed\n";
   }
   
   void test_DefaultConstructor()
   {
      Piece * pawn = new Pawn(1, 1, false);
   }
   
   /**************************************************************************
    * Tests to see if the pawn can move or not
    ***************************************************************************/
   void test_pawnBlocked()
   {
      // Setup
      Piece * whitePawn = new Pawn('A', 3, true);
      Piece * blackPawn = new Pawn('A', 3, false);
      whitePawn->position = Position(35);
      blackPawn->position = Position(27);
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      //Board * testBoard = buildSimpleBoard();


      testBoard->setPiece(whitePawn);
      testBoard->setPiece(blackPawn);

      // Excercise
      set<Move> whitePawnMoves = whitePawn->getPossibleMoves(*testBoard);

      // Verify
      assert(whitePawnMoves.size() == 0);

      // Teardown
      delete whitePawn;
      delete blackPawn;

      testBoard->free();
   }
   
   /**************************************************************************
    * Tests the basic moves of the pawn and its return values
    ***************************************************************************/
   void test_pawnSimpleMove()
   {
      // Setup
      Piece * whitePawn = new Pawn(0, 1, true);
      whitePawn->position.location = 33;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[33] = whitePawn;
      
      
      
      // Exercise
      set<Move> whitePawnsMoves = whitePawn->getPossibleMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whitePawnsMoves);
      
      assert(moves->find("64b5")          != moves->end());
      assert(whitePawn->fWhite            == true);
      assert(whitePawn->position.location == 33);
      assert(whitePawn->nMoves            == 0);
      assert(whitePawn->lastMove          == 0);
      
      
      // Teardown
      delete whitePawn;
      testBoard->free();
      delete testBoard;
      delete moves;
      
   }
   
   /**************************************************************************
    * Tests to see if promotion can happen and its return values
    ***************************************************************************/
   void test_pawnPromotion()
   {
      // Setup
      Pawn * whitePawn = new Pawn('A', 1, true);
      whitePawn->position.location = 9;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[9] = whitePawn;
      
      // Exercise
      set<Move> whitePawnMoves = whitePawn->getPossibleMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whitePawnMoves);
      
      assert(moves->find("67680")          != moves->end());
      assert(whitePawn->fWhite            == true);
      assert(whitePawn->position.location == 9);
      assert(whitePawn->nMoves            == 0);
      assert(whitePawn->lastMove          == 0);
      
      // Teardown
      delete whitePawn;
      testBoard->free();
      delete testBoard;
      delete moves;
      
   }
   
   /**************************************************************************
    * Tests the right values for en passant
    ***************************************************************************/
   void test_PawnEnpassant()
   {
      // Setup
      Pawn * whitePawn = new Pawn('A', 1, true);
      whitePawn->position.location = 25;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      
      Pawn * blackPawn1 = new Pawn('A', 1, true);
      blackPawn1->fWhite = false;
      blackPawn1->position.location = 8;
      blackPawn1->lastMove = 0;
      blackPawn1->nMoves = 0;
      
      Pawn * blackPawn2 = new Pawn('A', 1, true);
      blackPawn2->fWhite = false;
      blackPawn2->position.location = 16;
      blackPawn2->lastMove = 1;
      blackPawn2->nMoves = 0;
      
      Pawn * blackPawn3 = new Pawn('A', 1, true);
      blackPawn3->fWhite = false;
      blackPawn3->position.location = 18;
      blackPawn3->lastMove = 1;
      blackPawn3->nMoves = 0;
      
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[25] = whitePawn;
      testBoard->board[8]  = blackPawn1;
      testBoard->board[16] = blackPawn2;
      testBoard->board[18] = blackPawn3;
      
      // Exercise
      set<Move> whitePawnMoves = whitePawn->getPossibleMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whitePawnMoves);
      
      assert(moves->find("65c6E") != moves->end());
      assert(moves->find("b5a6E") != moves->end());
      
      assert(whitePawn->fWhite            == true);
      assert(whitePawn->position.location == 25);
      assert(whitePawn->nMoves            == 0);
      assert(whitePawn->lastMove          == 0);
      
      // Teardown
      delete whitePawn;
      delete blackPawn1;
      delete blackPawn2;
      delete blackPawn3;
      testBoard->free();
      delete testBoard;
      delete moves;
   }
   
   /**************************************************************************
    * Tests if the Pawn is Captured
    ***************************************************************************/
   void testPawnCapture()
   {
      // Setup
      Pawn * whitePawn = new Pawn('A', 1, true);
      whitePawn->position.location = 17;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      
      Pawn * blackPawn1 = new Pawn('A', 1, true);
      blackPawn1->fWhite = false;
      blackPawn1->position.location = 8;
      blackPawn1->lastMove = 0;
      blackPawn1->nMoves = 0;
      
      Pawn * blackPawn2 = new Pawn('A', 1, true);
      blackPawn2->fWhite = false;
      blackPawn2->position.location = 9;
      blackPawn2->lastMove = 1;
      blackPawn2->nMoves = 0;
      
      Pawn * blackPawn3 = new Pawn('A', 1, true);
      blackPawn3->fWhite = false;
      blackPawn3->position.location = 10;
      blackPawn3->lastMove = 1;
      blackPawn3->nMoves = 0;
      
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[25] = whitePawn;
      testBoard->board[8]  = blackPawn1;
      testBoard->board[16] = blackPawn2;
      testBoard->board[18] = blackPawn3;
      
      // Exercise
      set<Move> whitePawnMoves = whitePawn->getPossibleMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whitePawnMoves);
      
      assert(moves->find("b6a7p") != moves->end());
      assert(moves->find("b6c7p") != moves->end());
      
      assert(whitePawn->fWhite            == true);
      assert(whitePawn->position.location == 17);
      assert(whitePawn->nMoves            == 0);
      assert(whitePawn->lastMove          == 0);
      
      // Teardown
      delete whitePawn;
      delete blackPawn1;
      delete blackPawn2;
      delete blackPawn3;
      testBoard->free();
      delete testBoard;
      delete moves;
   }
   
   
   
   /**************************************************************************
    * Builds the board
    ***************************************************************************/
   Board * buildSimpleBoard()
   {
      Board * board = new Board();
      array<Piece*, 64> pieceArray = {};
      for (int index = 0; index < 64; index++)
      {
         pieceArray[index] = new Space(0, 1, false);
      }
      
      
      return board;
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
