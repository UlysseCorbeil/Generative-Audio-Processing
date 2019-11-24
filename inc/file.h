#ifndef FILE_H
#define FILE_H
#include <iostream>

class File {
public:
    int getFileSize(FILE *inFile);
    FILE * getInput();
};

#endif