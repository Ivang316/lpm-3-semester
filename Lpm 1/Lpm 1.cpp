#include <iostream>
#include "Sllist.h"
using namespace std;

/*6a Слейта два упорядоченных по невозрастанию списка в один (также упорядоченный по невозрастанию) построив новый список.*/

int main() {
    Sllist a, b;
    cout << "1st list: ";
    for (int i = 10; i < 30; i += 4) { // 10 12 14 16 18
        a.push_back(i);
        cout << i << ' ';
    }
    
    cout << "\n2nd list: ";
    for (int j = 8; j < 21; j++) { // 8 11 14 17 20
        b.push_back(j);
        cout << j << ' ';
    }

    Sllist* merged = a.merge(b);
    cout << "\n\nMerged list: ";
    merged->print_elements();
    delete merged;
}
