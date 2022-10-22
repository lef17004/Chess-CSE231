/**********************************************************************
 * gl demo
 * just a simple program to demonstrate how to create an open gl window,
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for interface
#include "uiDraw.h"       // for draw*
#include <set>            // for std::set
#include <cassert>        // for assert
#include <fstream>        // for ifstream
#include <string>         // for string
#include "position.h"
#include "board.h"
#include "testRunner.h"
#include "testKing.h"
#include "testPawn.h"
#include "move.h"
#include "piece.h"
#include "testRunner.h"
using namespace std;



/*********************************************
 * GET SLECTED MOVE
 * Returns the selected move out of the set. 
 *********************************************/
Move getselectedmove(set<Move>& moves, int location)
{
   for (auto move : moves)
   {
      if (move.getDes().getLocation() == location)
         return move;
   }
   Move move;
   return move;
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from opengl to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callback(Interface* pui, void* p)
{
   // The first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in opengl.
   Board * board = (Board*) p;
   ogstream gout;
   
   
   // Holds possible moves.
   set <int> possible;
   
   
   // Get User Input
   auto ui = *pui;
   Position selectedPosition(ui.getSelectPosition(), true);
   Position hoverPosition(ui.getHoverPosition(), true);
   Position previousPosition(ui.getPreviousPosition(), true);

   // Draw
   board->display(gout);
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());
   board->displayPieces(gout);

   // Move
   if (board->move(previousPosition, selectedPosition))
   {
      pui->clearSelectPosition();
   }
   else if (selectedPosition.isValid() && board->getPiece(selectedPosition)->isWhite() == board->isWhiteTurn())
   {
      auto piece3 = board->getPiece(selectedPosition);
      auto moves = piece3->getPossibleMoves(*board);
      for (auto move : moves)
      {
         move.display(gout);
      }
   }


   if (pui->getSelectPosition() != -1 && board->getPiece(selectedPosition)->getLetter() == 's')
      pui->clearSelectPosition();
}


/*********************************
 * Main is pretty sparse. Just initializes
 * my demo type and calls the display engine.
 * That is all!
 *********************************/
#ifdef _win32
#include <windows.h>
int winapi winmain(
   _in_ hinstance hinstance,
   _in_opt_ hinstance hprevinstance,
   _in_ pstr pcmdline,
   _in_ int ncmdshow)
#else // !_win32
int main(int argc, char** argv)
#endif // !_win32
{
   Interface ui("chess");
   
   Board chessboard;

   TestRunner tests;
   tests.run();
   
   
   ui.run(callback, (void*)&chessboard);

   return 0;
}
