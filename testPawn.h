/******************************************************************************
 * Header File:
 *    TestPawn : contains unit tests for the Pawn class
 * 
 * Lab01
 *
 * Created by Michael LeFevre on 9/28/22.
 *******************************************************************************/


#pragma once

#include <iostream>
#include "piece.h"
#include "board.h"
#include "position.h"
#include "move.h"
#include <algorithm>
using namespace std;


/******************************************************************************
 * TEST-PAWN
 * Containts test cases for the Pawn class
 ******************************************************************************/
class TestPawn
{
public:
   /*
    8    0,  1,  2,  3,  4,  5,  6,  7,
    7    8,  9, 10, 11, 12, 13, 14, 15,
    6   16, 17, 18, 19, 20, 21, 22, 23,
    5   24, 25, 26, 27, 28, 29, 30, 31,
    4   32, 33, 34, 35, 36, 37, 38, 39,
    3   40, 41, 42, 43, 44, 45, 46, 47,
    2   48, 49, 50, 51, 52, 53, 54, 55,
    1   56, 57, 58, 59, 60, 61, 62, 63
    
        A   B   C   D   E   F   G   H
    
    These sets are testing the pawn class with regards to move, but move is not being tested.
    So that's why moves methods are being used while pawn's attributes are accessed directly.
    
    */
   TestPawn() {}
   
   /*
    
    
    
    */

   /**************************************************************************
    * Runs the Pawn Test Cases
    ***************************************************************************/
   void run()
   {
      test_pawnBlocked();
      test_pawnSimpleMove();
      test_pawnPromotion();
      test_PawnEnpassant();
      testPawnCapture();
      cout << "TestPawn Completed" << endl;
   }
   
   /**************************************************************************
    * Tests to see if the pawn can move or not
    ***************************************************************************/
   void test_pawnBlocked()
   {
      // Setup
      Pawn * whitePawn = new Pawn(4, 3, true);
      Pawn * blackPawn = new Pawn(3, 3, false);
      whitePawn->position.location = 35;
      blackPawn->position.location = 27;
      Board * testBoard = buildSimpleBoard();
      
      
      testBoard->board[35] = whitePawn;
      testBoard->board[27] = blackPawn;
      
      // Excercise
      set<Move> whitePawnMoves = whitePawn->getMoves(*testBoard);
      
      // Verify
      assert(whitePawnMoves.size() == 0);
      
      // Teardown
      delete whitePawn;
      delete blackPawn;
      tearDownBoard(testBoard);
   }
   
   /**************************************************************************
    * Tests the basic moves of the pawn and its return values
    ***************************************************************************/
   void test_pawnSimpleMove()
   {
      // Setup
      Pawn * whitePawn = new Pawn(0, 0, true);
      whitePawn->position.location = 33;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[33] = whitePawn;
      
      
      
      // Exercise
      set<Move> whitePawnsMoves = whitePawn->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whitePawnsMoves);
      
      assert(moves->find("64b5")          != moves->end());
      assert(whitePawn->fWhite            == true);
      assert(whitePawn->position.location == 33);
      assert(whitePawn->nMoves            == 0);
      assert(whitePawn->lastMove          == 0);
      
      
      // Teardown
      delete whitePawn;
      tearDownBoard(testBoard);
      delete moves;
      
   }
   
   /**************************************************************************
    * Tests to see if promotion can happen and its return values
    ***************************************************************************/
   void test_pawnPromotion()
   {
      // Setup
      Pawn * whitePawn = new Pawn(0, 0, true);
      whitePawn->position.location = 9;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[9] = whitePawn;
      
      // Exercise
      set<Move> whitePawnMoves = whitePawn->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whitePawnMoves);
      
      assert(moves->find("67680")          != moves->end());
      assert(whitePawn->fWhite            == true);
      assert(whitePawn->position.location == 9);
      assert(whitePawn->nMoves            == 0);
      assert(whitePawn->lastMove          == 0);
      
      // Teardown
      delete whitePawn;
      tearDownBoard(testBoard);
      delete moves;
      
   }
   
   /**************************************************************************
    * Tests the right values for en passant
    ***************************************************************************/
   void test_PawnEnpassant()
   {
      // Setup
      Pawn * whitePawn = new Pawn(0, 0, true);
      whitePawn->position.location = 25;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      
      Pawn * blackPawn1 = new Pawn(0, 0, true);
      blackPawn1->fWhite = false;
      blackPawn1->position.location = 8;
      blackPawn1->lastMove = 0;
      blackPawn1->nMoves = 0;
      
      Pawn * blackPawn2 = new Pawn(0, 0, true);
      blackPawn2->fWhite = false;
      blackPawn2->position.location = 16;
      blackPawn2->lastMove = 1;
      blackPawn2->nMoves = 0;
      
      Pawn * blackPawn3 = new Pawn(0, 0, true);
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
      set<Move> whitePawnMoves = whitePawn->getMoves(*testBoard);
      
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
      tearDownBoard(testBoard);
      delete moves;
   }
   
   /**************************************************************************
    * Tests if the Pawn is Captured
    ***************************************************************************/
   void testPawnCapture()
   {
      // Setup
      Pawn * whitePawn = new Pawn(0, 0, true);
      whitePawn->position.location = 17;
      whitePawn->fWhite = true;
      whitePawn->lastMove = 0;
      whitePawn->nMoves = 0;
      
      
      Pawn * blackPawn1 = new Pawn(0, 0, true);
      blackPawn1->fWhite = false;
      blackPawn1->position.location = 8;
      blackPawn1->lastMove = 0;
      blackPawn1->nMoves = 0;
      
      Pawn * blackPawn2 = new Pawn(0, 0, true);
      blackPawn2->fWhite = false;
      blackPawn2->position.location = 9;
      blackPawn2->lastMove = 1;
      blackPawn2->nMoves = 0;
      
      Pawn * blackPawn3 = new Pawn(0, 0, true);
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
      set<Move> whitePawnMoves = whitePawn->getMoves(*testBoard);
      
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
      tearDownBoard(testBoard);
      delete moves;
   }
   
   /**************************************************************************
    * Builds the board
    ***************************************************************************/
   Board * buildSimpleBoard()
   {
      Board * board = new Board();
      array<Piece*, 64> pieceArray = {
         new Space(0, 0), new Space(0, 1), new Space(0 ,2), new Space(0, 3), new Space(0, 4), new Space(0, 5), new Space(0, 6), new Space(0, 7),
         new Space(1, 0), new Space(1, 1), new Space(1 ,2), new Space(1, 3), new Space(1, 4), new Space(1, 5), new Space(1, 6), new Space(1, 7),
         new Space(2, 0), new Space(2, 1), new Space(2 ,2), new Space(2, 3), new Space(2, 4), new Space(2, 5), new Space(2, 6), new Space(2, 7),
         new Space(3, 0), new Space(3, 1), new Space(3 ,2), new Space(3, 3), new Space(3, 4), new Space(3, 5), new Space(3, 6), new Space(3, 7),
         new Space(4, 0), new Space(4, 1), new Space(4 ,2), new Space(4, 3), new Space(4, 4), new Space(4, 5), new Space(4, 6), new Space(4, 7),
         new Space(5, 0), new Space(5, 1), new Space(5 ,2), new Space(5, 3), new Space(5, 4), new Space(5, 5), new Space(5, 6), new Space(5, 7),
         new Space(6, 0), new Space(6, 1), new Space(6 ,2), new Space(6, 3), new Space(6, 4), new Space(6, 5), new Space(6, 6), new Space(6, 7),
         new Space(7, 0), new Space(7, 1), new Space(7 ,2), new Space(7, 3), new Space(7, 4), new Space(7, 5), new Space(7, 6), new Space(7, 7)
      };
      board->board = (pieceArray);
      return board;
   }
   
   /**************************************************************************
    * Clears the board memory
    ***************************************************************************/
   void tearDownBoard(Board * board)  // Frees all of the memory of the Board
   {
      
      for (int i = 0; i < board->board.size(); i++)
      {
         //delete board->board[i];
      }
      delete board;
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
