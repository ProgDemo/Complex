#include "Infile.h"
#include<stdlib.h>
#include<iostream>

std::vector<Complex> readFile(std::string fileName) {
    std::ifstream infile;
    std::vector<Complex> result;

    infile.open(fileName.c_str());
    if (infile.fail()) {
        throw FileNotFoundException;
    }

    while (!infile.fail()) {
        std::string tmp;

        getline(infile, tmp);
        if(!infile.fail()) {
            std::stringstream line;
            line << tmp;
            int re, im;

            line >> re;
            if (line.fail()) {throw NumberFormatException; }
            line >> im;
            if (line.fail()) {throw NumberFormatException; }

            Complex c(re, im);
            result.push_back(c);
        }
    }
    infile.close();
    return result;
}
