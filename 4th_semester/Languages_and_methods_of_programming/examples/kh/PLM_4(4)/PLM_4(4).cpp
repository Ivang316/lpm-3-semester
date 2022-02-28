// PLM_4(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Point {
	int x, y;
};

void filePrint(string fileName, Point* arr, int n) {
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "Enable to open the file!\n";
	}
	else {
		int i = 0;
		while (!file.eof() && i < n) {
			file >> arr[i].x >> arr[i].y;
			cout << "(" << arr[i].x << "," << arr[i].y << ")\n";
			i++;
		}
	}
	file.close();
}

void nullArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
}

int nullCount(int* arr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			count++;
		}
	}
	return count;
}

int minimumCountOfLines(Point* arr, int pointsCount, int* status, int& linesCount, int& minCount, int& lineNumber) {
	bool uncheckedPoint = false, flag = false;
	int firstPoint = 0, secondPoint = 0;
	for (int i = 0; i < pointsCount; i++) {
		if (status[i] == 0) {
			uncheckedPoint = true;
		}
	}

	if (uncheckedPoint) {
		if (nullCount(status, pointsCount) == 1) {
			linesCount++;
		}
		else {
			for (int i = 0; i < pointsCount; i++) {
				int j = 0;
				for (int i = 0; i < pointsCount && !flag; i++) {
					if (status[i] == 0) {
						firstPoint = i;
						flag = true;
						j = i + 1;
					}
				}
				flag = false;
				for (j; j < pointsCount && !flag; j++) {
					if (status[j] == 0) {
						secondPoint = j;
						flag = true;
					}
				}
				status[firstPoint] = status[secondPoint] = lineNumber;
				for (int k = 0; k < pointsCount; k++) {
					if ((status[k] == 0) && (arr[firstPoint].y - arr[secondPoint].y != 0) && (arr[firstPoint].x - arr[secondPoint].x != 0) &&
						(arr[k].y - arr[secondPoint].y) * (arr[firstPoint].x - arr[secondPoint].x) == (arr[k].x - arr[secondPoint].x) * (arr[firstPoint].y - arr[secondPoint].y))
						status[k] = lineNumber;
				}
				linesCount++;
				lineNumber++;
				minimumCountOfLines(arr, pointsCount, status, linesCount, minCount, lineNumber);
				if (linesCount < minCount) {
					minCount = linesCount;
				}
				status[secondPoint] = status[firstPoint] = 0;
			}
		}
	}
	return minCount;
}

int main() {
	int pointsCount;
	cout << "Enter the count of points: ";
	cin >> pointsCount;

	Point* arr = new Point[pointsCount];
	filePrint("points.txt", arr, pointsCount);

	int* status = new int[pointsCount];
	nullArr(status, pointsCount);
	int linesCount = 0, minCount = pointsCount, lineNumber = 1;
	cout << "\nMinimum count of lines: " << minimumCountOfLines(arr, pointsCount, status, linesCount, minCount, lineNumber) << "\n";

	return 0;
}
