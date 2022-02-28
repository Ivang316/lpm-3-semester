#include "Graph.h"

bool Graph::isSafe(int matrix[ROW][COL], int row, int col, bool visit[ROW][COL]) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (matrix[row][col] && !visit[row][col]);
}

void Graph::depthFirstSearch(int matrix[ROW][COL], int row, int col, bool visit[ROW][COL]) {
    int rowNeighbors[] = { -1, 0, 0, 1 };
    int colNeighbors[] = { 0, -1, 1, 0 };
    int countOfNeighbors = 4;

    visit[row][col] = true;

    for (int i = 0; i < countOfNeighbors; i++) {
        if (isSafe(matrix, row + rowNeighbors[i], col + colNeighbors[i], visit)) {
            depthFirstSearch(matrix, row + rowNeighbors[i], col + colNeighbors[i], visit);
        }
    }
}

int Graph::connectingComponentsCount(int matrix[ROW][COL]) {
    int count = 0;
    bool visit[ROW][COL];
    memset(visit, false, SIZE);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (matrix[i][j] && !visit[i][j]) {
                depthFirstSearch(matrix, i, j, visit);
                count++;
            }
        }
    }

    return count;
}
