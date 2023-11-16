# C++ Base 64

It's my first project in C++ writing a Base 64 encoder!!

## String Conversion

```c++
string text = "Hello, World!";
std::string result = Base64::to_base_64_string(text);
```

## Stream Conversion

You can also convert streams, just pass input and output streams.
```c++
Base64(Input(*istream*), outputFile);

// EXAMPLE:

ifstream inputFile(path + "/input.txt", ios::binary);
ofstream outputFile(path + "/output.txt", ios::binary);

Input input(inputFile);
Base64(input, outputFile);
```

## Terminal

Run the main.cpp class, here's how it goes:

```bash
/home/kumaraswamy/Documents/mlemon/Base64/cmake-build-debug/Base64
File conversion type `file`, string conversion type `string`: string
Type text to encode to base 64
hello world
Encoded Base64: aGVsbG8gd29ybGQ=
hey hello how are you man
Encoded Base64: aGV5IGhlbGxvIGhvdyBhcmUgeW91IG1hbg==
```