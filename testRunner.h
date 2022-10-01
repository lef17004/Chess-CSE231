//
//  testRunner.h
//  Lab01
//
//  Created by Michael LeFevre on 9/28/22.
//
#pragma once
#include "testPawn.h"
#include "testKing.h"
#include <iostream>
using namespace std;

class TestRunner // Runs all of the tests.
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
