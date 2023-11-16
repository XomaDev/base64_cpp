
#include <fstream>
#include "ByteInput.h"

using namespace std;

class Base64 {
private:
    ByteInput &input;
    ostream &output;

    int curr_char = -1;
    char cursor = -1; // must be initially -1

    bool reached_eof = false;

    void fill();

    bool read_bit();

    unsigned char read_bits();

    unsigned char next_char();

    void read_all();

public:
    explicit Base64(ByteInput &input, ostream &output);

    static string to_base_64_string(string &input);
};