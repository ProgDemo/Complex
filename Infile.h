#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED

#include "Complex.h"
#include<fstream>
#include<sstream>
#include <vector>

enum InFileExceptions {FileNotFoundException, NumberFormatException};

std::vector<Complex> readFile(std::string fileName);

#endif // INFILE_H_INCLUDED
