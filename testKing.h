/******************************************************************************
 * Header File:
 *    TestKing : contains unit tests for the King class
 * 
 * Lab01
 *
 * Created by Michael LeFevre on 9/28/22.
 *******************************************************************************/


#pragma once

#include <iostream>
#include "piece.h"
#include "board.h"
using namespace std;


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
 */


 /******************************************************************************
  * TEST-KING
  * Containts test cases for the King class
  ******************************************************************************/
class TestKing
{
public:
   TestKing() {}
   
   /***************************************************************************
    * Runs the test cases
    ***************************************************************************/
   void run()
   {
      test_kingFree();
      test_kingBlocked();
      test_kingCapture();
      test_kingCastleKingMove();
      test_kingCastleRookMove();
      test_kingCastleBlocked();
      test_kingCastle();
      
      
      cout << "TestKing Completed" << endl;
   }
   
   /***************************************************************************
    * Test's that the king moves correctly when placed alone on the board
    ***************************************************************************/
   void test_kingFree()
   {
      // Setup
      King * whiteKing = new King(0, 0, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 28;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[28] = whiteKing;
      
      // Exercise
      set<Move> whiteKingMoves = whiteKing->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
      
      assert(moves->find("e5d6") != moves->end());
      assert(moves->find("e5e6") != moves->end());
      assert(moves->find("e5f6") != moves->end());
      assert(moves->find("e5d5") != moves->end());
      assert(moves->find("e5f5") != moves->end());
      assert(moves->find("e5d4") != moves->end());
      assert(moves->find("e5e4") != moves->end());
      assert(moves->find("e5f4") != moves->end());
  
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 28);
      assert(whiteKing->nMoves            == 0);
      assert(whiteKing->lastMove          == 0);
      
      // Teardown
      delete whiteKing;
      tearDownBoard(testBoard);
      delete moves;
      
   }
   
   /***************************************************************************
    * Verifies that the king can't move when surounded by friendly pawns
    ***************************************************************************/
   void test_kingBlocked()
   {
      // Setup
      King * whiteKing = new King(0, 0, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 28;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Pawn * whitePawn1 = new Pawn(0, 0, false);
      whitePawn1->position.location = 27;
      whitePawn1->fWhite = true;
      
      Pawn * whitePawn2 = new Pawn(0, 0, false);
      whitePawn2->position.location = 20;
      whitePawn2->fWhite = true;
      
      Pawn * whitePawn3 = new Pawn(0, 0, false);
      whitePawn3->position.location = 21;
      whitePawn3->fWhite = true;
      
      Pawn * whitePawn4 = new Pawn(0, 0, false);
      whitePawn4->position.location = 29;
      whitePawn4->fWhite = true;
      
      Pawn * whitePawn5 = new Pawn(0, 0, false);
      whitePawn5->position.location = 35;
      whitePawn5->fWhite = true;
      
      Pawn * whitePawn6 = new Pawn(0, 0, false);
      whitePawn6->position.location = 36;
      whitePawn6->fWhite = true;
      
      Pawn * whitePawn7 = new Pawn(0, 0, false);
      whitePawn7->position.location = 37;
      whitePawn7->fWhite = true;

      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[28] = whiteKing;
      testBoard->board[27] = whitePawn1;
      testBoard->board[20] = whitePawn2;
      testBoard->board[21] = whitePawn3;
      testBoard->board[29] = whitePawn4;
      testBoard->board[35] = whitePawn5;
      testBoard->board[36] = whitePawn6;
      testBoard->board[37] = whitePawn7;
      
      // Exercise
      set<Move> whiteKingMoves = whiteKing->getMoves(*testBoard);
      
      // Verify
      assert(whiteKingMoves.size()        == 0);
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 28);
      assert(whiteKing->nMoves            == 0);
      assert(whiteKing->lastMove          == 0);
      
      // Teardown
      delete whiteKing;
      delete whitePawn1;
      delete whitePawn2;
      delete whitePawn3;
      delete whitePawn4;
      delete whitePawn5;
      delete whitePawn6;
      delete whitePawn7;
      
      
      tearDownBoard(testBoard);
     
   }
   
   /***************************************************************************
    * verifies that the king can capture enemy pawns
    ***************************************************************************/
   void test_kingCapture()
   {
      // Setup
      King * whiteKing = new King(0, 0, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 28;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Pawn * blackPawn1 = new Pawn(0, 0, false);
      blackPawn1->position.location = 27;
      blackPawn1->fWhite = false;
      
      Pawn * blackPawn2 = new Pawn(0, 0, false);
      blackPawn2->position.location = 20;
      blackPawn2->fWhite = false;
      
      Pawn * blackPawn3 = new Pawn(0, 0, false);
      blackPawn3->position.location = 21;
      blackPawn3->fWhite = false;
      
      Pawn * blackPawn4 = new Pawn(0, 0, false);
      blackPawn4->position.location = 29;
      blackPawn4->fWhite = false;
      
      Pawn * blackPawn5 = new Pawn(0, 0, false);
      blackPawn5->position.location = 35;
      blackPawn5->fWhite = false;
      
      Pawn * blackPawn6 = new Pawn(0, 0, false);
      blackPawn6->position.location = 36;
      blackPawn6->fWhite = false;
      
      Pawn * blackPawn7 = new Pawn(0, 0, false);
      blackPawn7->position.location = 37;
      blackPawn7->fWhite = false;
      
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[28] = whiteKing;
      testBoard->board[27] = blackPawn1;
      testBoard->board[20] = blackPawn2;
      testBoard->board[21] = blackPawn3;
      testBoard->board[29] = blackPawn4;
      testBoard->board[35] = blackPawn5;
      testBoard->board[36] = blackPawn6;
      testBoard->board[37] = blackPawn7;
      
      // Exercise
      set<Move> whiteKingMoves = whiteKing->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);

      assert(whiteKingMoves.size() == 8);
      assert(moves->find("e5d6p")  != moves->end());
      assert(moves->find("e5e6p")  != moves->end());
      assert(moves->find("e5f6p")  != moves->end());
      assert(moves->find("e5d5p")  != moves->end());
      assert(moves->find("e5f5p")  != moves->end());
      assert(moves->find("e5d4p")  != moves->end());
      assert(moves->find("e5e4p")  != moves->end());
      assert(moves->find("e5f4p")  != moves->end());
      
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 28);
      assert(whiteKing->nMoves            == 0);
      assert(whiteKing->lastMove          == 0);
      
      // Teardown
      delete whiteKing;
      delete blackPawn1;
      delete blackPawn2;
      delete blackPawn3;
      delete blackPawn4;
      delete blackPawn5;
      delete blackPawn6;
      delete blackPawn7;
      delete moves;
      tearDownBoard(testBoard);
   }
   
   /***************************************************************************
    * Verifies that the king moves correclty in the castle procedure
    ***************************************************************************/
   void test_kingCastleKingMove()
   {
      // Setup
      King * whiteKing = new King(0, 0, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 1;
      
      Pawn * whitePawn1 = new Pawn(0, 0, false);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Pawn * whitePawn2 = new Pawn(0, 0, false);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Pawn * whitePawn3 = new Pawn(0, 0, false);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Rook * whiteRook1 = new Rook(0, 0, false);
      whiteRook1->position.location = 56;
      whiteRook1->fWhite = true;
      
      Rook * whiteRook2 = new Rook(0, 0, false);
      whiteRook2->position.location = 63;
      whiteRook2->fWhite = true;

      Board * testBoard = buildSimpleBoard();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[56] = whiteRook1;
      testBoard->board[63] = whiteRook2;
      
      // Exercise
      set<Move> whiteKingMoves = whiteKing->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
   
      assert(whiteKingMoves.size() == 2);
      assert(moves->find("elf1")  != moves->end());
      assert(moves->find("eldl")  != moves->end());
      
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 60);
      assert(whiteKing->nMoves            == 1);
      assert(whiteKing->lastMove          == 0);
      
      // Teardown
      delete whiteKing;
      delete whitePawn1;
      delete whitePawn2;
      delete whitePawn3;
      delete whiteRook1;
      delete whiteRook2;
      delete moves;
      tearDownBoard(testBoard);
   }
   
   /***************************************************************************
    * verifies that the rook moves correctly in the castle move
    ***************************************************************************/
   void test_kingCastleRookMove()
   {
      // Setup
      King * whiteKing = new King(0, 0, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Pawn * whitePawn1 = new Pawn(0, 0, false);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Pawn * whitePawn2 = new Pawn(0, 0, false);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Pawn * whitePawn3 = new Pawn(0, 0, false);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Rook * whiteRook1 = new Rook(0, 0, false);
      whiteRook1->position.location = 56;
      whiteRook1->fWhite = true;
      whiteRook1->nMoves = 1;
      
      Rook * whiteRook2 = new Rook(0, 0, false);
      whiteRook2->position.location = 63;
      whiteRook2->fWhite = true;
      whiteRook2->nMoves = 1;
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[56] = whiteRook1;
      testBoard->board[63] = whiteRook2;
      
      // Exercise
      set<Move> whiteKingMoves = whiteKing->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
      
      assert(whiteKingMoves.size() == 2);
      assert(moves->find("elf1")  != moves->end());
      assert(moves->find("eldl")  != moves->end());
      
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 60);
      assert(whiteKing->nMoves            == 0);
      assert(whiteKing->lastMove          == 0);
      
      // Teardown
      delete whiteKing;
      delete whitePawn1;
      delete whitePawn2;
      delete whitePawn3;
      delete whiteRook1;
      delete whiteRook2;
      delete moves;
      tearDownBoard(testBoard);
   }
   
   /***************************************************************************
    * Verifies that the caslte option is not avaliable when it shouldn't be
    ***************************************************************************/
   void test_kingCastleBlocked()
   {
      // Setup
      King * whiteKing = new King(0, 0, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Pawn * whitePawn1 = new Pawn(0, 0, false);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Pawn * whitePawn2 = new Pawn(0, 0, false);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Pawn * whitePawn3 = new Pawn(0, 0, false);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Pawn * whitePawn4 = new Pawn(0, 0, false);
      whitePawn4->position.location = 57;
      whitePawn4->fWhite = true;
      
      Pawn * whitePawn5 = new Pawn(0, 0, false);
      whitePawn5->position.location = 54;
      whitePawn5->fWhite = true;
      
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[57] = whitePawn4;
      testBoard->board[54] = whitePawn5;
      
      // Exercise
      set<Move> whiteKingMoves = whiteKing->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
      
      assert(whiteKingMoves.size() == 2);
      assert(moves->find("elf1")  != moves->end());
      assert(moves->find("eldl")  != moves->end());
      
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 28);
      assert(whiteKing->nMoves            == 0);
      assert(whiteKing->lastMove          == 0);
      
      // Teardown
      delete whiteKing;
      delete whitePawn1;
      delete whitePawn2;
      delete whitePawn3;
      delete whitePawn4;
      delete whitePawn5;
      delete moves;
      tearDownBoard(testBoard);
   }
   
   /***************************************************************************
    * verifies the castle option is available when proper conditions are filled
    ***************************************************************************/
   void test_kingCastle()
   {
      // Setup
      King * whiteKing = new King(0, 0, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Pawn * whitePawn1 = new Pawn(0, 0, false);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Pawn * whitePawn2 = new Pawn(0, 0, false);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Pawn * whitePawn3 = new Pawn(0, 0, false);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Rook * whiteRook1 = new Rook(0, 0, false);
      whiteRook1->position.location = 56;
      whiteRook1->fWhite = true;
      whiteRook1->nMoves = 0;
      
      Rook * whiteRook2 = new Rook(0, 0, false);
      whiteRook2->position.location = 63;
      whiteRook2->fWhite = true;
      whiteRook2->nMoves = 0;
      
      Board * testBoard = buildSimpleBoard();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[56] = whiteRook1;
      testBoard->board[63] = whiteRook2;
      
      // Exercise
      set<Move> whiteKingMoves = whiteKing->getMoves(*testBoard);
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
 
      assert(whiteKingMoves.size() == 4);
      assert(moves->find("elf1")  != moves->end());
      assert(moves->find("eldl")  != moves->end());
      assert(moves->find("E1glc")  != moves->end());
      assert(moves->find("elc1C")  != moves->end());
      
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 60);
      assert(whiteKing->nMoves            == 0);
      assert(whiteKing->lastMove          == 0);
      
      // Teardown
      delete whiteKing;
      delete whitePawn1;
      delete whitePawn2;
      delete whitePawn3;
      delete whiteRook1;
      delete whiteRook2;
      delete moves;
      tearDownBoard(testBoard);
   }
   
   /***************************************************************************
    * clears the board memory
    ***************************************************************************/
   void tearDownBoard(Board * board)
   {
      // Brother Helfrich, if you could comment the correct way to release all the memory in board
      // or go over it in class that would be helpful!
      
      for (int i = 0; i < board->board.size(); i++)
      {
         //delete board->board[i];
      }
      delete board;
   }
   
   /***************************************************************************
    * converts the moves into string set's to more easily verify that the 
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
   
   /***************************************************************************
    * sets up the basic board
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
   
};
