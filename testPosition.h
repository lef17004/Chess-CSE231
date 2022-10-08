//
//  testPosition.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/6/22.
//

#pragma once
#include <iostream>
using namespace std;
class TestPosition
{
public:
   // TODO: Tests need better names.
   void run()
   {
      test_defaultConstructor();
      test_nonDefaultConstructor();
      test_NonDefaultConstructor2();
      test_getLocation();
      test_getRow1();
      test_getRow2();
      test_getRow3();
      test_getCol1();
      test_getCol2();
      test_getCol3();
      test_getX();
      test_getY();
      test_isValidTrue();
      test_isValidFalse();
      test_set1();
      test_lessThan1();
      test_lessThan2();
      cout << "TestPosition Complete" << endl;
   }
   
   // Test the default constructor
   void test_defaultConstructor()
   {
      // Set up
      Position testPosition;
      
      // Verify
      assert(testPosition.location == 56);
      
      // Teardown
   }
   
   // Test the non default constructor.
   void test_nonDefaultConstructor()
   {
      // Set Up
      Position position(4, 1);
      
      // Verify
      assert(position.location == 25);
   }
   
   // Tests the non default constructor in 0, 0 position.
   void test_NonDefaultConstructor2()
   {
      // Set Up
      Position position(0, 0);
      
      // Verify
      assert(position.location == 56);
   }
   
   // Tests getLocation
   void test_getLocation()
   {
      // Setup
      Position testPosition;
      testPosition.location = 55;
      
      // Exercise
      char location = testPosition.getLocation();
      
      // Verify
      assert(location == 55);
   }
   
   // Test Get Row
   void test_getRow1()
   {
      // Setup
      Position testPosition;
      testPosition.location = 44;
      
      // Exercise
      char row = testPosition.getRow();
      
      // Verify
      assert(row == 2);
   }
   
   
   // Test Get Row Cornor
   void test_getRow2()
   {
      // Setup
      Position testPosition;
      testPosition.location = 0;
      
      // Exercise
      char row = testPosition.getRow();
      
      // Verify
      assert(row == 7);
   }
   
   // Test Get Row Other Cornor
   void test_getRow3()
   {
      // Setup
      Position testPosition;
      testPosition.location = 63;
      
      // Exercise
      char row = testPosition.getRow();
      
      // Verify
      assert(row == 0);
   }
   
   // Test get col works.
   void test_getCol1()
   {
      // Setup
      Position testPosition;
      testPosition.location = 44;
      
      // Exercise
      char col = testPosition.getCol();
      
      // Verify
      assert(col == 4);
   }
   
   // Test get col works on edge case.
   void test_getCol2()
   {
      // Setup
      Position testPosition;
      testPosition.location = 0;
      
      // Exercise
      char col = testPosition.getCol();
      
      // Verify
      assert(col == 0);
   }
   
   // Test get col works on edge case.
   void test_getCol3()
   {
      // Setup
      Position testPosition;
      testPosition.location = 63;
      
      // Exercise
      char col = testPosition.getCol();
      
      // Verify
      assert(col == 7);
   }
   
   // Tests that get x works.
   void test_getX()
   {
      // Setup
      Position testPosition;
      testPosition.location = 43;
      
      // Exercise
      int x = testPosition.getX();
      
      // Verify
      assert(x == 96);
   }
   
   // Tests that get y works.
   void test_getY()
   {
      // Setup
      Position testPosition;
      testPosition.location = 43;
      
      // Exercise
      int y = testPosition.getY();
      
      // Verify
      assert(y == 160);
   }
   
   // Tests is valid works when position is valid.
   void test_isValidTrue()
   {
      // Setup
      Position testPosition;
      testPosition.location = 18;
      
      // Exercise
      bool isPosValid = testPosition.isValid();
      
      // Verify
      assert(isPosValid);
   }
   
   // Tests is valid works when position is not valid.
   void test_isValidFalse()
   {
      // Setup
      Position testPosition;
      testPosition.location = 90;
      
      // Exercise
      bool isPosValid = testPosition.isValid();
      
      // Verify
      assert(!isPosValid);
   }
   
   // Tests set works. Edge case.
   void test_set1()
   {
      // Verify
      int row = 0;
      int col = 0;
      Position testPosition;
      testPosition.location = 36;
      
      // Exercise
      testPosition.set(row, col);
      
      // Verify
      assert(testPosition.location == 56);
      
   }
   
   // Tests set works. In middle.
   void test_set2()
   {
      // Verify
      int row = 3;
      int col = 4;
      Position testPosition;
      testPosition.location = 0;
      
      // Exercise
      testPosition.set(row, col);
      
      // Verify
      assert(testPosition.location == 36);
      
   }
   
   // Tests set works. Other cornor.
   void test_set3()
   {
      // Setup
      int row = 0;
      int col = 7;
      Position testPosition;
      testPosition.location = 36;
      
      // Exercise
      testPosition.set(row, col);
      
      // Verify
      assert(testPosition.location == 63);
      
   }
   
   // Less than left hand side smaller.
   void test_lessThan1()
   {
      // Setup
      Position testPos1;
      testPos1.location = 53;
      
      Position testPos2;
      testPos2.location = 55;
      
      // Exercise
      bool isLessThan = testPos1 < testPos2;
      
      // Verify
      assert(isLessThan);
   }
   
   // Less than right hand side smaller. 
   void test_lessThan2()
   {
      // Setup
      Position testPos1;
      testPos1.location = 53;
      
      Position testPos2;
      testPos2.location = 55;
      
      // Exercise
      bool isLessThan = testPos2 < testPos1;
      
      // Verify
      assert(!isLessThan);
   }
};
