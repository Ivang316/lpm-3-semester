#include <iostream>
#include <vector>

using namespace std;

vector<int> fillingVector(vector<int> num, int count)
{
	for (int i = 0; i < count; i++)
		num.push_back(-1);
	return num;
}

void permutationsWithOutput(vector<int> num, vector<int> check, int digit)
{
	vector<int>::const_iterator itNum;
	vector<int>::const_iterator itCheck;

	itNum = num.begin();
	itCheck = num.begin();
	for (int i = 0; i < num.size(); i++)
	{
		if (check.at(i) == -1)
		{
			check.at(i) = 1;
			num.at(digit) = num.size() - i;
			permutationsWithOutput(num, check, digit + 1);
			if (num.size() == digit + 1)
			{
				for (int n : num)
				{
					cout << n;
				}
				cout << endl;
			}
			check.at(i) = -1;
		}
	}
}

int main()
{
	vector <int> number;
	vector <int> check;
	int N;

	cout << "Enter N -> ";
	cin >> N;
	number = fillingVector(number, N);
	check = fillingVector(check, N);

	permutationsWithOutput(number, check, 0);
	return 0;
}