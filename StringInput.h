//
// Created by kumaraswamy on 16/11/23.
//

#ifndef BASE64_STRINGINPUT_H
#define BASE64_STRINGINPUT_H


#include <string>
#include "ByteInput.h"

using namespace std;

class StringInput : public ByteInput {
private:
    int index = 0;
    string& input;
public:
    explicit StringInput(string& input);
    int get() override;
    bool eof() override;
};


#endif //BASE64_STRINGINPUT_H
