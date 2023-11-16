//
// Created by kumaraswamy on 14/11/23.
//
#include <iostream>
#include <sstream>

#include "Base64.h"
#include "ByteInput.h"
#include "StringInput.h"

using namespace std;

void Base64::fill() {
    if (cursor >= 0) {
        return;
    }
    curr_char = input.get();
    if (input.eof()) {
        reached_eof = true;
        return;
    }
    cursor = 7;
}

bool Base64::read_bit() {
    bool bit = (curr_char >> cursor--) & 1;
    fill();
    return bit;
}

unsigned char Base64::read_bits() {
    unsigned char res;
    char n = 6;
    while (n--) {
        res = (res << 1) | read_bit();
        if (reached_eof) {
            while (n--) {
                res = (res << 1) | 0;
            }
            return res;
        }
    }
    return res;
}

unsigned char Base64::next_char() {
    unsigned char bits = read_bits();
    if (bits < 26) return bits + 65;
    else if (bits < 52) return bits + 71;
    else if (bits < 62) return bits - 4;
    return bits == 62 ? '+' : '/';
}

void Base64::read_all() {
    int bytes_written = 0;
    while (!reached_eof) {
        output << next_char();
        bytes_written++;
    }
    while (bytes_written % 4 != 0) {
        output << '=';
        bytes_written++;
    }
}

Base64::Base64(ByteInput& input, ostream& output) : input(input), output(output) {
    fill();
    read_all();
}

string Base64::to_base_64_string(string &input) {
    stringstream output;
    StringInput strinput(input);

    Base64(strinput, output);
    return output.str();
}

