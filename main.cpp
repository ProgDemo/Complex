#include <iostream>
#include "Complex.h"
#include "Infile.h"
#include <vector>

#define NORMAL
#ifdef NORMAL
int main()
{
    try {
        std::vector<Complex> numbers = readFile("input.txt");
        for (int i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << std::endl;
        }
    } catch (InFileExceptions ex) {
        if (ex == FileNotFoundException) {
            std::cout << "File not found!!\n";
        } else {
            std::cout << "Invalid numbers!!\n";
        }
    }

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Constructor without parameters", "re,im")
{
    Complex c;
    bool result = 0 == c.getRe() && 0 == c.getIm();
    CHECK(result == 1);
}

TEST_CASE("Add method", "re,im")
{
    Complex left;
    Complex right(1,1);
    left + right;
    bool result = 1 == left.getRe() && 1 == left.getIm();
    CHECK(result == 1);
}

TEST_CASE("readFile method", "exception")
{
    CHECK_THROWS(readFile("notexists"));
}

TEST_CASE("readFile method, invalid numbers", "exception")
{
    CHECK_THROWS(readFile("input_bad.txt"));
}

#endif
