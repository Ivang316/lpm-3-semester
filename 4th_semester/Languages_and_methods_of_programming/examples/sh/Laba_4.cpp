#include <iostream>
#include <queue>

using namespace std;

int countOf = 0;
int** combination;

int bfs(int** matrix)
{
	bool check = true;
	int* direction = new int[countOf];
	for (int i = 0; i < countOf; i++)
	{
		direction[i] = -1;
	}
	direction[0] = 0;
	queue<int> points;
	points.push(0);
	while (!points.empty() && check)
	{
		int top = points.front();
		points.pop();
		for (int i = 0; i < countOf; i++)
		{
			if (matrix[top][i] == 1 && direction[i] == -1 && i != top)
			{
				direction[i] = 1 - direction[top];
				points.push(i);
			}
			if (direction[i] == direction[top] && i != top && matrix[top][i] == 1)
			{
				check = false;
			}
		}
	}
	int gears = 0;
	if (check)
	{
		for (int i = 0; i < countOf; i++)
		{
			if (direction[i] != -1)
			{
				gears++;
			}
		}
	}

	delete[]direction;
	return gears;
}

void combinOfArray(int countOf)
{
	combination = new int* [pow(2, countOf)];
	for (int i = 0; i < pow(2, countOf); i++)
	{
		combination[i] = new int[countOf];
	}
	for (int j = 0; j < countOf; j++)
	{
		int period = pow(2, countOf) / pow(2,j+1);
		int k = period;
		bool digit = false;
		for (int i = 0; i < pow(2, countOf); i++)
		{
			if (!digit)
			{
				combination[i][j] = 0;
			}
			else if (digit)
			{
				combination[i][j] = 1;
			}
			k--;
			if (k == 0)
			{
				digit = !digit;
				k = period;
			}
		}
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите количество шестерёнок -> ";
	cin >> countOf;
	int **matrix = new int* [countOf];
	for (int i = 0; i < countOf; i++)
	{
		matrix[i] = new int[countOf];
	}
	cout << "Введите матрицу смежности -> \n";
	for (int i = 0; i <countOf; i++)
	{
		for (int j = 0; j < countOf; j++)
		{
			cin >> matrix[i][j];
		}
	}
	int gears = bfs(matrix);
	if (gears)
	{
		cout << "------------------------------------------------------------\n";
		cout << "Количество вращающихся шестерёнок: "<<gears << endl;
	}
	else
	{
		cout << "------------------------------------------------------------\n";
		cout << "Шестерёнки вращаться не смогут!\n";
		combinOfArray(countOf - 1);
		int** copyMatrix = new int* [countOf];
		for (int i = 0; i < countOf; i++)
		{
			copyMatrix[i] = new int[countOf];
		}

		int max = 0;
		int iMax = -1;

		for (int i = 0; i < pow(2, countOf - 1); i++)
		{
			for (int k = 0; k < countOf; k++)
			{
				for (int j = 0; j < countOf; j++)
				{
					copyMatrix[k][j] = matrix[k][j];
				}
			}
			for (int j = 0; j < countOf - 1; j++)
			{
				if (!combination[i][j])
				{
					for (int k = 0; k < countOf; k++)
					{
						copyMatrix[k][j + 1] = 0;
						copyMatrix[j + 1][k] = 0;
					}
				}
			}
			int k = bfs(copyMatrix);
			if (k > max)
			{
				max = k;
				iMax = i;
			}
		}
		cout << "------------------------------------------------------------\n";
		cout << "Максимальное количество возможных вращающихся шестерёнок: " << max << endl;
		cout << "Для этого оптимальнее всего убрать шестерёнки: ";
		for (int j = 0; j < countOf - 1; j++)
		{
			if (!combination[iMax][j])
			{
				cout << j + 2 << " ";
			}
		}
		cout << "\n------------------------------------------------------------\n";
		for (int i = 0; i < countOf; i++)
		{
			delete[]copyMatrix[i];
		}
		delete[]copyMatrix;

		for (int i = 0; i < pow(2, countOf - 1); i++)
		{
			delete[]combination[i];
		}
		delete[]combination;

	}


	for (int i = 0; i < countOf; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
	return 0;
}

/*
6
0 1 0 0 0 0
1 0 1 1 0 0
0 1 0 0 0 0
0 1 0 0 1 0
0 0 0 1 0 1
0 0 0 0 1 0
*/

/*
8
0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0
1 1 0 1 0 0 0 0
0 0 1 0 1 0 0 0
0 0 0 1 0 1 0 0
0 0 0 0 1 0 1 1
0 0 0 0 0 1 0 1
0 0 0 0 0 1 1 0
*/

/*
4
0 1 0 0
1 0 0 1
0 0 0 0
0 1 0 0
*/