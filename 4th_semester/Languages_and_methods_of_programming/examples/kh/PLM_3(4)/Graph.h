#pragma once
#include <iostream>
using namespace std;

const int ROW = 5;
const int COL = 4;
const int SIZE = ROW * COL;

class Graph {

public:
    bool isSafe(int matrix[ROW][COL], int row, int col, bool visit[ROW][COL]);
    void depthFirstSearch(int matrix[ROW][COL], int row, int col, bool visit[ROW][COL]);
    int connectingComponentsCount(int matrix[ROW][COL]);
};
