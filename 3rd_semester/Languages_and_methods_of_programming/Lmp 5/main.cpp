
#include <iostream>
#include <chrono>
using namespace std;

/*Сравнить сортировки по возрастанию — шейкерная и выбором на трех массивах: 
	1 упорядоченный по убыванию 
	2 первая половина по возрастанию, вторая во убыванию
	3 со случайными числами
  Сравнить как зависит количиство перестановок и время от количества элементов*/

void shaker_sort(int* arr, int length, int& swaps);
void selection_sort(int* arr, int length, int& swaps);
int* arr_descending(int length);
int* arr_asc_desc(int length);
int* arr_random(int length);
void timing_swaps(void sort(int*, int, int&), int* create_array(int), int len, int& swaps, double& time);


int main() {
	int len; int swaps; int* arr; double time;
	cout << "Enter the length of arrays: ";
	cin >> len;
	system("cls");
	cout << "array length is " << len << "\n";
	cout << "sorting algoritm\tarray type\t time in milliseconds \t swaps count\n\n";
	timing_swaps(shaker_sort, arr_descending, len, swaps, time);
	cout << "shaker\t\t\tdescending\t\t" << time << "\t\t   " << swaps << "\n";

	timing_swaps(shaker_sort, arr_asc_desc, len, swaps, time);
	cout << "shaker\t\t\tascending-descending\t" << time << "\t\t   " << swaps << "\n";

	timing_swaps(shaker_sort, arr_random, len, swaps, time);
	cout << "shaker\t\t\trandom\t\t\t" << time << "\t\t   " << swaps << "\n\n";

	timing_swaps(selection_sort, arr_descending, len, swaps, time);
	cout << "selection\t\tdescending\t\t" << time << "\t\t   " << swaps << "\n";

	timing_swaps(selection_sort, arr_asc_desc, len, swaps, time);
	cout << "selection\t\tascinding-descending\t" << time << "\t\t   " << swaps << "\n";

	timing_swaps(selection_sort, arr_random, len, swaps, time);
	cout << "selection\t\trandom\t\t\t" << time << "\t\t   " << swaps << "\n";
}

void shaker_sort(int* a, int len, int& swaps) {
	swaps = 0;
	bool swapped = true;
	int lEnd = 0, rEnd = len - 1;
	while (swapped) {
		for (int i = lEnd; i < rEnd; i++)
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
				swaps++;
			}
		if (!swapped)
			break;
		rEnd--;
		swapped = false;
		for (int i = rEnd - 1; i >= lEnd; i--) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		lEnd++;
	}
}
void selection_sort(int* a, int len, int& swaps) {
	swaps = 0;
	for (int i = 0; i < len - 1; i++)	{ 
		int idxMin = i;
		for (int k = i + 1; k < len; k++)
			if (a[k] < a[idxMin])
				idxMin = k;
		swap(a[idxMin], a[i]);
		swaps++;
	}
}
int* arr_descending(int len) {
	int* arr = new int[len];
	for (int val = len, i = 0; i < len; i++, val--)
		arr[i] = val;
	return arr;
}							   
int* arr_asc_desc(int len) {
	int* arr = new int[len];
	for (int i = 0; i < len / 2; i++)
		arr[i] = i;
	for (int val = len / 2, i = len / 2; i < len; i++, val--)
		arr[i] = val;
	return arr;
}			
int* arr_random(int len) {
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand();
	return arr;
}
void timing_swaps(void sort(int*, int, int&), int* create_array(int), int len, int& swaps, double& time) {
	int* arr = create_array(len);
	auto t1 = chrono::steady_clock::now();
	sort(arr, len, swaps);
	auto t2 = chrono::steady_clock::now();
	time = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	delete[] arr;
}


