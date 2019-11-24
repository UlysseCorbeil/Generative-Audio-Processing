#ifndef FILE_H
#define FILE_H
#include <iostream>

class File {
public:
    int getFileSize(FILE *inFile);
    FILE * getInput(int argc, char const *argv);
};

#endif