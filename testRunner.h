/******************************************************************************
 * Header File:
 *    TestRunner : Runs the unit tests
 * 
 * Lab01
 *
 * Created by Michael LeFevre on 9/28/22.
 *******************************************************************************/


#pragma once

#include "testPawn.h"
#include "testBoard.h"
#include "testPiece.h"
#include "testKing.h"
#include "testPosition.h"
#include "testMove.h"
#include <iostream>
using namespace std;


 /******************************************************************************
  * TEST-RUNNER
  * Runs all of the tests
  ******************************************************************************/
class TestRunner
{
public:
   TestRunner() {}
   
   void run()
   {
      TestPosition testPosition;
      TestMove testMove;
      TestBoard testBoard;
      TestPiece testPiece;
      TestPawn testPawn;
      TestKing testKing;
      
      
      testPosition.run();
      testMove.run();
      testBoard.run();
      testPiece.run();
      testPawn.run();
      testKing.run();
      
      
      cout << "Test Runner Completed" << endl;
   }
};
