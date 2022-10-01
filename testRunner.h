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
#include "testKing.h"
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
      TestPawn pawnTests;
      pawnTests.run();
      
      TestKing pawnKing;
      pawnKing.run();
      
      cout << "Test Runner Completed" << endl;
   }
};
