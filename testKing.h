//
//  testKing.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#pragma once
#include <iostream>
using namespace std;

class TestKing
{
public:
   void run()
   {
      test_kingFree();
      test_kingBlocked();
      test_kingCapture();
      test_kingCastleKingMove();
      test_kingCastleRookMove();
      test_kingCastleBlocked();
      test_kingCastle();
      cout << "TestKing Completed\n" << endl;
   }
   
   /***************************************************************************
    * Test's that the king moves correctly when placed alone on the board
    ***************************************************************************/
   void test_kingFree()
   {
      // Setup
      Piece * whiteKing = new King(4, 4, true);
      whiteKing->fWhite = true;
      whiteKing->position.location = 28;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      testBoard->board[28] = whiteKing;
      
      // Exercise
      set<Move> whiteKingMoves = *(whiteKing->getPossibleMoves(*testBoard));
      
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
      testBoard->free();
      delete testBoard;
      delete moves;
      
   }
   
   /***************************************************************************
    * Verifies that the king can't move when surounded by friendly pawns
    ***************************************************************************/
   void test_kingBlocked()
   {
      // Setup
      Piece * whiteKing = new King(4, 4, true);
      whiteKing->fWhite = true;
      whiteKing->position.location = 28;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Piece * whitePawn1 = new Pawn(4, 3, true);
      whitePawn1->position.location = 27;
      whitePawn1->fWhite = true;
      
      Piece * whitePawn2 = new Pawn(5, 4, true);
      whitePawn2->position.location = 20;
      whitePawn2->fWhite = true;
      
      Piece * whitePawn3 = new Pawn(5, 5, true);
      whitePawn3->position.location = 21;
      whitePawn3->fWhite = true;
      
      Piece * whitePawn4 = new Pawn(4, 5, true);
      whitePawn4->position.location = 29;
      whitePawn4->fWhite = true;
      
      Piece * whitePawn5 = new Pawn(3, 3, true);
      whitePawn5->position.location = 35;
      whitePawn5->fWhite = true;
      
      Piece * whitePawn6 = new Pawn(3, 6, true);
      whitePawn6->position.location = 36;
      whitePawn6->fWhite = true;
      
      Piece * whitePawn7 = new Pawn(3, 5, true);
      whitePawn7->position.location = 37;
      whitePawn7->fWhite = true;
      
      Piece * whitePawn8 = new Pawn(5, 3, true);
      whitePawn8->position.location = 19;
      whitePawn8->fWhite = true;
      
      
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      testBoard->board[28] = whiteKing;
      testBoard->board[27] = whitePawn1;
      testBoard->board[20] = whitePawn2;
      testBoard->board[21] = whitePawn3;
      testBoard->board[29] = whitePawn4;
      testBoard->board[35] = whitePawn5;
      testBoard->board[36] = whitePawn6;
      testBoard->board[37] = whitePawn7;
      testBoard->board[19] = whitePawn8;
      
      // Exercise
      set<Move> whiteKingMoves = *(whiteKing->getPossibleMoves(*testBoard));
      
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
      delete whitePawn8;
      
      testBoard->free();
      delete testBoard;
      
   }
   
   /***************************************************************************
    * verifies that the king can capture enemy pawns
    ***************************************************************************/
   void test_kingCapture()
   {
      // Setup
      Piece * whiteKing = new King(4, 4, true);
      whiteKing->fWhite = true;
      whiteKing->position.location = 28;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Piece * blackPawn1 = new Pawn(4, 3, false);
      blackPawn1->position.location = 27;
      blackPawn1->fWhite = false;
      
      Piece * blackPawn2 = new Pawn(5, 4, false);
      blackPawn2->position.location = 20;
      blackPawn2->fWhite = false;
      
      Piece * blackPawn3 = new Pawn(5, 5, false);
      blackPawn3->position.location = 21;
      blackPawn3->fWhite = false;
      
      Piece * blackPawn4 = new Pawn(4, 5, false);
      blackPawn4->position.location = 29;
      blackPawn4->fWhite = false;
      
      Piece * blackPawn5 = new Pawn(3, 3, false);
      blackPawn5->position.location = 35;
      blackPawn5->fWhite = false;
      
      Piece * blackPawn6 = new Pawn(3, 6, false);
      blackPawn6->position.location = 36;
      blackPawn6->fWhite = false;
      
      Piece * blackPawn7 = new Pawn(3, 5, false);
      blackPawn7->position.location = 37;
      blackPawn7->fWhite = false;
      
      Piece * blackPawn8 = new Pawn(5, 3, false);
      blackPawn8->position.location = 19;
      blackPawn8->fWhite = false;
      
      
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      testBoard->board[28] = whiteKing;
      testBoard->board[27] = blackPawn1;
      testBoard->board[20] = blackPawn2;
      testBoard->board[21] = blackPawn3;
      testBoard->board[29] = blackPawn4;
      testBoard->board[35] = blackPawn5;
      testBoard->board[36] = blackPawn6;
      testBoard->board[37] = blackPawn7;
      testBoard->board[19] = blackPawn8;
      
      // Exercise
      set<Move> whiteKingMoves = *(whiteKing->getPossibleMoves(*testBoard));
      
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
      testBoard->free();
      delete testBoard;
   }
   
   /***************************************************************************
    * Verifies that the king moves correclty in the castle procedure
    ***************************************************************************/
   void test_kingCastleKingMove()
   {
      // Setup
      Piece * whiteKing = new King(0, 4, true);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 1;
      
      Piece * whitePawn1 = new Pawn(1, 3, true);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Piece * whitePawn2 = new Pawn(1, 4, true);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Piece * whitePawn3 = new Pawn(1, 5, true);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Piece * whiteRook1 = new Rook(0, 0, true);
      whiteRook1->position.location = 56;
      whiteRook1->fWhite = true;

      Piece * whiteRook2 = new Rook(0, 7, true);
      whiteRook2->position.location = 63;
      whiteRook2->fWhite = true;
      
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[56] = whiteRook1;
      testBoard->board[63] = whiteRook2;
      
      // Exercise
      set<Move> whiteKingMoves = *(whiteKing->getPossibleMoves(*testBoard));
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
      
      assert(whiteKingMoves.size() == 2);
      assert(moves->find("e1f1")  != moves->end());
      assert(moves->find("e1d1")  != moves->end());
      
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
      testBoard->free();
      delete testBoard;
   }
   
   /***************************************************************************
    * verifies that the rook moves correctly in the castle move
    ***************************************************************************/
   void test_kingCastleRookMove()
   {
      // Setup
      Piece * whiteKing = new King(0, 1, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Piece * whitePawn1 = new Pawn(0, 1, false);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Piece * whitePawn2 = new Pawn(0, 1, false);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Piece * whitePawn3 = new Pawn(0, 1, false);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Piece * whiteRook1 = new Rook(0, 1, false);
      whiteRook1->position.location = 56;
      whiteRook1->fWhite = true;
      whiteRook1->nMoves = 1;

      Piece * whiteRook2 = new Rook(0, 1, false);
      whiteRook2->position.location = 63;
      whiteRook2->fWhite = true;
      whiteRook2->nMoves = 1;
      
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[56] = whiteRook1;
      testBoard->board[63] = whiteRook2;
      
      // Exercise
      set<Move> whiteKingMoves = *(whiteKing->getPossibleMoves(*testBoard));
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
      
      assert(whiteKingMoves.size() == 2);
      assert(moves->find("e1f1")  != moves->end());
      assert(moves->find("e1d1")  != moves->end());
      
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
      testBoard->free();
      delete testBoard;
   }
   
   /***************************************************************************
    * Verifies that the caslte option is not avaliable when it shouldn't be
    ***************************************************************************/
   void test_kingCastleBlocked()
   {
      // Setup
      Piece * whiteKing = new King(0, 1, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Piece * whitePawn1 = new Pawn(0, 1, false);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Piece * whitePawn2 = new Pawn(0, 1, false);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Piece * whitePawn3 = new Pawn(0, 1, false);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Piece * whitePawn4 = new Pawn(0, 1, false);
      whitePawn4->position.location = 57;
      whitePawn4->fWhite = true;
      
      Piece * whitePawn5 = new Pawn(0, 1, false);
      whitePawn5->position.location = 54;
      whitePawn5->fWhite = true;
      
      
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[57] = whitePawn4;
      testBoard->board[54] = whitePawn5;
      
      // Exercise
      set<Move> whiteKingMoves = *(whiteKing->getPossibleMoves(*testBoard));
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
      
      assert(whiteKingMoves.size() == 2);
      assert(moves->find("e1f1")  != moves->end());
      assert(moves->find("e1d1")  != moves->end());
      
      assert(whiteKing->fWhite            == true);
      assert(whiteKing->position.location == 60);
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
      testBoard->free();
      delete testBoard;
   }
   
   /***************************************************************************
    * verifies the castle option is available when proper conditions are filled
    ***************************************************************************/
   void test_kingCastle()
   {
      // Setup
      Piece * whiteKing = new King(0, 1, false);
      whiteKing->fWhite = true;
      whiteKing->position.location = 60;
      whiteKing->lastMove = 0;
      whiteKing->nMoves = 0;
      
      Piece * whitePawn1 = new Pawn(0, 1, false);
      whitePawn1->position.location = 51;
      whitePawn1->fWhite = true;
      
      Piece * whitePawn2 = new Pawn(0, 1, false);
      whitePawn2->position.location = 52;
      whitePawn2->fWhite = true;
      
      Piece * whitePawn3 = new Pawn(0, 1, false);
      whitePawn3->position.location = 53;
      whitePawn3->fWhite = true;
      
      Piece * whiteRook1 = new Rook(0, 1, false);
      whiteRook1->position.location = 56;
      whiteRook1->fWhite = true;
      whiteRook1->nMoves = 0;

      Piece * whiteRook2 = new Rook(0, 1, false);
      whiteRook2->position.location = 63;
      whiteRook2->fWhite = true;
      whiteRook2->nMoves = 0;
      
      Board * testBoard = new Board();
      testBoard->setBoardToEmpty();
      testBoard->board[60] = whiteKing;
      testBoard->board[51] = whitePawn1;
      testBoard->board[52] = whitePawn2;
      testBoard->board[53] = whitePawn3;
      testBoard->board[56] = whiteRook1;
      testBoard->board[63] = whiteRook2;
      
      // Exercise
      set<Move> whiteKingMoves = *(whiteKing->getPossibleMoves(*testBoard));
      
      // Verify
      set<string> * moves = compileMoves(whiteKingMoves);
      
      assert(whiteKingMoves.size() == 4);
      assert(moves->find("e1f1")  != moves->end());
      assert(moves->find("e1d1")  != moves->end());
      assert(moves->find("e1g1c")  != moves->end());
      assert(moves->find("e1c1C")  != moves->end());
      
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
      testBoard->free();
      delete testBoard;
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
   

};
