#include <iostream>

using namespace std;


//Найти в графе вершину, для которой сумма минимальных расстояний до остальных вершин минимальна
/* 5
0 10 30 50 10
0 0 0 0 0
0 0 0 0 10
0 40 20 0 0
10 0 10 30 0

5
0 40 0 0 18
40 0 22 6 15
0 22 0 14 0
0 6 14 0 20
18 15 0 20 0
*/
int alghorithm(int tops, int** graph, int st)
{
	int sum = 0;
	int* distance = new int[tops], index;
	bool* visited = new bool[tops];
	for (int i = 0; i < tops; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (int count = 0; count < tops - 1; count++)
	{
		int min = INT_MAX;
		for (int i = 0; i < tops; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		visited[index] = true;
		for (int i = 0; i < tops; i++)
			if (!visited[i] && graph[index][i] && distance[index] != INT_MAX &&
				distance[index] + graph[index][i] < distance[i])
				distance[i] = distance[index] + graph[index][i];
	}
	for (int i = 0; i < tops; i++)
		if (distance[i] != INT_MAX)
			sum += distance[i];
	return sum;
}

pair<int, int> countOfMinimal(int tops, int** graph)
{
	int index = -1;
	int* sum = new int[tops];
	for (int i = 1; i <= tops; i++)
		sum[i - 1] = alghorithm(tops, graph, i-1);
	int minSum = INT_MAX;
	for (int i = 0; i < tops; i++)
	{
		cout << sum[i] << endl;
		if (sum[i] < minSum && sum[i] != 0)
		{
			minSum = sum[i];
			index = i;
		}
	}
	pair<int, int> result;
	result.first = index;
	result.second = minSum;
	return result;
}

int main()
{
	int tops;
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество вершин -> ";
	cin >> tops;
	int** graph = new int* [tops];
	for (int i = 0; i < tops; i++)
		graph[i] = new int[tops];
	for (int i = 0; i < tops; i++)
		for (int j = 0; j < tops; j++)
			cin >> graph[i][j];
	pair<int, int> result = countOfMinimal(tops, graph);
	cout << "Сумма минимальных расстояний минимальна у " << result.first + 1 << " и равна " << result.second;
	cout << endl;
	for (int i = 0; i < tops; i++)
		delete[]graph[i];
	delete[]graph;
	return 0;
}