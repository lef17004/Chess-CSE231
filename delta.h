//
//  delta.h
//  ChessUnitTests
//
//  Created by Michael LeFevre on 10/7/22.
//

#pragma once
struct Delta
{
public:
   int x;
   int y;
   Delta(int x, int y): x(x), y(y) {}
   Delta(): x(0), y(0) {}
};
