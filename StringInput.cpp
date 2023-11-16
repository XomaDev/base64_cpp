//
// Created by kumaraswamy on 16/11/23.
//

#include "StringInput.h"


StringInput::StringInput(string &input) : input(input) {

}

int StringInput::get() {
    return input[index++];
}

bool StringInput::eof() {
    return input[index - 1] == '\0';
}
