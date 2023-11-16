//
// Created by kumaraswamy on 16/11/23.
//

#ifndef BASE64_INPUT_H
#define BASE64_INPUT_H

#include <fstream>

#include "ByteInput.h"

using namespace std;

class Input: public ByteInput {
private:
    istream& input;
public:
    explicit Input(istream& input);
    int get() override;
    bool eof() override;
};


#endif //BASE64_INPUT_H
