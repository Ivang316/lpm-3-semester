// PLM_5(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
using namespace std;

class Queue {
    deque<int> queue, minQueue;
public:
    void push(int x) {
        queue.push_back(x);
        while (!minQueue.empty() && x < minQueue.back()) {
            minQueue.pop_back();
        }
        minQueue.push_back(x);
    }

    void pop() {
        if (!queue.empty()) {
            if (queue.front() == minQueue.front()) {
                minQueue.pop_front();
            }
            queue.pop_front();
        }
    }

    int getMin() {
        if (!minQueue.empty()) {
            return minQueue.front();
        }
        else return 0;
    }
};
int main() {
    int numbersCount, consecutiveCount;
    cout << "Enter the count of numbers: ";
    cin >> numbersCount;
    cout << "Enter the count of consecutive numbers: ";
    cin >> consecutiveCount;

    Queue queue;
    int numbers;

    cout << "\nEnter the numbers: ";
    for (int i = 0; i < consecutiveCount; i++) {
        cin >> numbers;
        queue.push(numbers);
    }

    cout << "\nMinimum of consecuive numbers: ";
    for (int i = 0; i < numbersCount - consecutiveCount; i++) {
        cout << queue.getMin() << " ";
        cin >> numbers;
        queue.pop();
        queue.push(numbers);
    }
    cout << queue.getMin() << "\n\n";

    return 0;
}
