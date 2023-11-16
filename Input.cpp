//
// Created by kumaraswamy on 16/11/23.
//

#include "Input.h"

Input::Input(istream &input): input(input) {
    // hello :)
}

int Input::get() {
    return input.get();
}

bool Input::eof() {
    return input.eof();
}
