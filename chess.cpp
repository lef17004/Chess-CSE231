/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "position.h"
#include "board.h"
#include "testRunner.h"
#include "testKing.h"
#include "testPawn.h"
#include "move.h"
#include "piece.h"
#include "testRunner.h"
using namespace std;

/***************************************************
 * DRAW
 * Draw the current state of the game
 ***************************************************/
void draw(const char* board, const Interface & ui, const set <int> & possible)
{
   ogstream gout;
   
   // draw the checkerboard
   //gout.drawBoard();
   Board board2;
   board2.display(gout);
   
   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());
   int selected = ui.getSelectPosition();
   
   if (0 <= selected && selected < 64)
   {
      auto piece2 = board2.getPiece(Position(selected));
      auto moves = piece2->getPossibleMoves(board2);
      for (auto move : *moves)
      {
         move.display(gout);
      }
   }
   board2.displayPieces(gout);
   
}

/*********************************************
 * MOVE 
 * Execute one movement. Return TRUE if successful
 *********************************************/

Move getSelectedMove(set<Move> & moves, int location)
{
   for (auto move: moves)
   {
      if (move.getDes().getLocation() == location)
         return move;
   }
   Move move;
   return move;
   
}
/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
   set <int> possible;
   ogstream gout;
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   //Board * board = (Board *)p;
   Board * board = (Board *) p;
   // move
   auto ui = *pUI;
   Position selectedPosition(ui.getSelectPosition(), true);
   Position hoverPosition(ui.getHoverPosition(), true);
   Position previousPosition(ui.getPreviousPosition(), true);
   
   board->display(gout);
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());
   board->displayPieces(gout);
   
   if (board->move(previousPosition, selectedPosition))
   {
      pUI->clearSelectPosition();
   }
   else if (selectedPosition.isValid() && board->getPiece(selectedPosition)->isWhite() == board->isWhiteTurn())
   {
      auto piece3 = board->getPiece(selectedPosition);
      auto moves = piece3->getPossibleMoves(*board);
      for (auto move : *moves)
      {
         move.display(gout);
      }
   }
   
   // draw any selections
   
   if (pUI->getSelectPosition() != -1 && board->getPiece(selectedPosition)->getLetter() == 's')
      pUI->clearSelectPosition();

}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   Interface ui("Chess");    
   Board chessBoard;

   TestRunner tests;
   tests.run();
   // set everything into action
   // (void *) (&board);
   // (Board * p)
   ui.run(callBack, (void *) &chessBoard);

   return 0;
}
