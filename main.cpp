#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>

#include "Base64.h"
#include "Input.h"

using namespace std;

int file_process() {
    string path = filesystem::current_path().parent_path();

    ifstream inputFile(path + "/input.txt", ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Unable to open file input.txt " << strerror(errno) << endl;
        return 1;
    }
    ofstream outputFile(path + "/output.txt", ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Unable to open file output.txt " << strerror(errno) << endl;
        return 1;
    }
    Input input(inputFile);
    Base64(input, outputFile);

    return 0;
}

int string_process() {
    cout << "Type text to encode to base 64" << endl;
    while (true) {
        string input;
        getline(cin, input);
        if (input == "end") {
            return 0;
        }
        if (input.empty()) {
            continue;
        }
        cout << "Encoded Base64: " << Base64::to_base_64_string(input) << endl;
    }
}

int main() {
    cout << "File conversion type `file`, string conversion type `string`: ";
    string action;
    cin >> action;
    return action == "string" ? string_process() : file_process();
}
