#pragma once
#include <string>

class BitString {
    unsigned long head = 0, tail = 0;
public:
    BitString();
    BitString(unsigned long, unsigned long);
    unsigned long get_head();
    unsigned long get_tail();
    void set_head(unsigned long);
    void set_tail(unsigned long);
    void negation();
    BitString disjunction(BitString);
    BitString conjunction(BitString);
    BitString exclusive_or(BitString);
    void shift_left(int);
    void shift_right(int);
    std::string to_string();
};
