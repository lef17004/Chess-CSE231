/**********************************************************************
 * gl demo
 * just a simple program to demonstrate how to create an open gl window,
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiinteract.h"   // for interface
#include "uidraw.h"       // for draw*
#include <set>            // for std::set
#include <cassert>        // for assert
#include <fstream>        // for ifstream
#include <string>         // for string
#include "position.h"
#include "board.h"
#include "testrunner.h"
#include "testking.h"
#include "testpawn.h"
#include "move.h"
#include "piece.h"
#include "testrunner.h"
using namespace std;


/***************************************************
 * draw
 * draw the current state of the game
 ***************************************************/
void draw(const char* board, const interface& ui, const set <int>& possible)
{
   ogstream gout;

   // draw the checkerboard
   //gout.drawboard();
   board board2;
   board2.display(gout);

   // draw any selections
   gout.drawhover(ui.gethoverposition());
   gout.drawselected(ui.getselectposition());
   int selected = ui.getselectposition();

   if (0 <= selected && selected < 64)
   {
      auto piece2 = board2.getpiece(position(selected));
      auto moves = piece2->getpossiblemoves(board2);
      for (auto move : *moves)
      {
         move.display(gout);
      }
   }
   board2.displaypieces(gout);
}

/*********************************************
 * move
 * execute one movement. return true if successful
 *********************************************/
move getselectedmove(set<move>& moves, int location)
{
   for (auto move : moves)
   {
      if (move.getdes().getlocation() == location)
         return move;
   }
   move move;
   return move;
}

/*************************************
 * all the interesting work happens here, when
 * i get called back from opengl to draw a frame.
 * when i am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callback(interface* pui, void* p)
{
   set <int> possible;
   ogstream gout;
   // the first step is to cast the void pointer into a game object. this
   // is the first step of every single callback function in opengl. 
   //board * board = (board *)p;
   board* board = (board*)p;
   // move
   auto ui = *pui;
   position selectedposition(ui.getselectposition(), true);
   position hoverposition(ui.gethoverposition(), true);
   position previousposition(ui.getpreviousposition(), true);

   board->display(gout);
   gout.drawhover(ui.gethoverposition());
   gout.drawselected(ui.getselectposition());
   board->displaypieces(gout);

   if (board->move(previousposition, selectedposition))
   {
      pui->clearselectposition();
   }
   else if (selectedposition.isvalid() && board->getpiece(selectedposition)->iswhite() == board->iswhiteturn())
   {
      auto piece3 = board->getpiece(selectedposition);
      auto moves = piece3->getpossiblemoves(*board);
      for (auto move : *moves)
      {
         move.display(gout);
      }
   }

   // draw any selections
   if (pui->getselectposition() != -1 && board->getpiece(selectedposition)->getletter() == 's')
      pui->clearselectposition();
}


/*********************************
 * main is pretty sparse.  just initialize
 * my demo type and call the display engine.
 * that is all!
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
   interface ui("chess");
   board chessboard;

   testrunner tests;
   tests.run();
   // set everything into action
   // (void *) (&board);
   // (board * p)
   ui.run(callback, (void*)&chessboard);

   return 0;
}
