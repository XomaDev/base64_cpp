//
// Created by kumaraswamy on 16/11/23.
//

#ifndef BASE64_BYTEINPUT_H
#define BASE64_BYTEINPUT_H


class ByteInput {

public:
    virtual int get() = 0;

    virtual bool eof() = 0;
};


#endif //BASE64_BYTEINPUT_H
