// PLM_3(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

void filePrint(string fileName, int arr[ROW][COL]) {
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "Enable to open the file!\n";
	}
	else {
		while (!file.eof()) {
			for (int i = 0; i < ROW; i++) {
				for (int j = 0; j < COL; j++) {
					file >> arr[i][j];
				}
			}
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    cout << arr[i][j] << "\t";
                }
                cout << "\n";
            }
		}
	}
	file.close();
}

int main() {
    Graph graph;
	int matrix[ROW][COL];

	cout << "Matrix " << ROW << "x" << COL << ":\n\n";
	filePrint("matrix.txt", matrix);

    cout << "\nConnecting components count: " << graph.connectingComponentsCount(matrix) << "\n\n";

    system("pause");
	return 0;
}
