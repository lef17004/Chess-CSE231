//
//  testBoard.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//
#include <iostream>
using namespace std;
#pragma once
class TestBoard
{
public:
   void run()
   {
      test_Get();
      test_GetCurrentMove();
      test_IsWhiteTurn();
      test_IsWhiteTurnFalse();
      test_SetPiece();
      test_SetPieceWrongPiece();
      test_Move();
      
      cout << "TestBoard Completed\n";
   }
   
   // Tests getting a peice from the board. 
   void test_Get()
   {
      // Setup
      Board board;
      Position pos(5, 5);
      Piece * pawn = new Pawn(5, 5, true);
      board.board[21] = pawn;
      
      // Exercise
      Piece * pieceFromBoard = board.getPiece(pos);
      
      // Verify
      assert(pieceFromBoard == pawn);
      
      // Teardown
      delete pawn;
   }
   
   // Tests getting the current move.
   void test_GetCurrentMove()
   {
      // Setup
      Board board;
      board.currentMove = 55;
      
      // Exercise
      int currentMove = board.getCurrentMove();
      
      // Verify
      assert(currentMove == 55);
      
      // Teardown
      board.free();
   }
   
   // Test is white turn when it's white's turn.
   void test_IsWhiteTurn()
   {
      // Setup
      Board board;
      board.currentMove = 2;
      
      // Exercise
      bool isWhiteMove = board.isWhiteTurn();
      
      // Verify
      assert(isWhiteMove == true);
      
      // Teardown
      board.free();
   }
   
   // Test get turn when it is black's turn.
   void test_IsWhiteTurnFalse()
   {
      // Setup
      Board board;
      board.currentMove = 3;
      
      // Exercise
      bool isWhiteMove = board.isWhiteTurn();
      
      // Verify
      assert(isWhiteMove == false);
      
      // Teardown
      board.free();
   }
   
   // Test set piece.
   void test_SetPiece()
   {
      // Setup
      Board board;
      Piece * pawn = new Pawn(3, 7, false);
      board.board[39] = new Space(3, 7, false);
      
      // Exercise
     board.setPiece(pawn);
      
      // Verify
      assert(pawn == board.board[39]);
      
      // Teardone
      delete pawn;
      board.free();
   }
   
   // Tests that assert works when piece is in the wrong place.
   // TODO: Remove soon.
   void test_SetPieceWrongPiece()
   {
      // Setup
      Board board;
      Piece * pawn = new Pawn(3, 7, false);
      board.board[39] = new Space(3, 7, false);
      
      // Exercise
      // I suppose this is really more testing that the assert works.
      // Keep for now and remove later.
      //board.setPiece(pawn);
      
      // Verify
      assert(pawn != board.board[39]);
      
      // Teardone
      delete pawn;
      board.free();
   }
   
   // Test that the move method works.
   // TODO: Change this test to basic move.
   // TODO: Create more move tests for next week's assignment.
   void test_Move()
   {
      // Setup
      Board board;
      board.board[57] = new Pawn(0, 1, true);
      board.board[49] = new Space(1, 1, false);
      
      Move move;
      move.setSource(Position(0, 1));
      move.setDest(Position(1, 1));
      
      // Exercise
      board.move(move);
      
      // Verify
      //assert(board.board[57]->getLetter() == 's');
      //assert(board.board[49]->getLetter() == 'p');
      
   }
   
};
