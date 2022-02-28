#include <iostream>
using namespace std;
void Initialization(int n, int*** x);
void Destruction(int n, int** x);
bool Queen(int n, int** x);
void Placement(int n, int** a, int* p, int* h, int* du,
	int* dd, int i = 0, int j = 0);

int main() {
	setlocale(LC_ALL, "ru");
	int n, i, j;
	bool otv;
	int** mas;
	cout << "Введите размер шахматной доски n : ";
	cin >> n;
	Initialization(n, &mas);
	otv = Queen(n, mas);
	if (otv) cout<< "Правильное размещение найдено\n";
	else cout<<"Правильного размещения не найдено\n";
	Destruction(n, mas);
	return 0;
}

//инициализация поля шахматной доски
void Initialization(int n, int*** x) {
	*x = new int* [n];
	for (int i = 0; i < n; i++) {
		(*x)[i] = new int[n];
		for (int j = 0; j < n; j++)
			(*x)[i][j] = 0;
	}
}

//вывод найденной расстановки в файл
void Destruction(int n, int** x) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << x[i][j] << " ";
			cout << endl;
		}
	for (int i = 0; i < n; i++)
		delete[] x[i];
	delete[] x;
}

//проверка возможности постановки ферзя
bool Queen(int n, int** x) {
	bool rez = false;
	int* p, * h, * du, * dd;
	p = new int[n];
	h = new int[n];
	du = new int[2 * n - 1];
	dd = new int[2 * n - 1];
	for (int i = 0; i < n; i++)
		p[i] = h[i] = 0;
	for (int i = 0; i < (2 * n - 1); i++)
		du[i] = dd[i] = 0;
	Placement(n, x, p, h, du, dd);
	if (h[0] != 0) rez = true;
	delete[] dd, du, h, p;
	return rez;
}

//описание функции расстановки ферзей
void Placement(int n, int** a, int* p, int* h, int* du,
	int* dd, int i, int j) {
	if (j >= 0 && j < n)
		if (i < n)
			if (h[i] == 0 && du[i + j] == 0 && dd[n + i - j - 1] == 0) {
				h[i] = 1;
				du[i + j] = 1;
				dd[n + i - j - 1] = 1;
				p[j] = i;
				a[i][j] = 1;
				Placement(n, a, p, h, du, dd, 0, j + 1);
			}
			else
				Placement(n, a, p, h, du, dd, i + 1, j);
		else
			if (j > 0) {
				h[p[j - 1]] = 0;
				du[p[j - 1] + j - 1] = 0;
				dd[n + p[j - 1] - (j - 1) - 1] = 0;
				a[p[j - 1]][j - 1] = 0;
				Placement(n, a, p, h, du, dd, p[j - 1] + 1, j - 1);
			}
}