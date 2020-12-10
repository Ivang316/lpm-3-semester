#include <iostream>
#include "BitString.h"
using namespace std;

template<typename T>
void print_bits(T num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--)
        std::cout << ((num >> i) & 1);
}

/* 17 Создать класс BitString для работы с 64-битовыми строками. Битовая строка состоит из двух полей unsigned long. Реализованы операции по работе с битами: and, or, xor, not. Также сдвиг влево shiftLeft и вправо shiftRight на заданное количество битов.*/

int main() {
    unsigned long a = 12345678, b = 8765432;
    //cout << "Enter two positive numbers a and b: ";
    //cin >> a >> b;
    BitString bitStr(a, b);

    cout << "Initial bit sting: \n";
    print_bits(bitStr.get_head());
    cout << ' ';
    print_bits(bitStr.get_tail());

    bitStr.shift_right(10);
    cout << "\nString shifted right at 10 bits: \n";
    print_bits(bitStr.get_head());
    cout << ' ';
    print_bits(bitStr.get_tail());
}