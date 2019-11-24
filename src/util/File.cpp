#include <iostream>
#include <fstream>
#include <string>

#include "file.h"

int File::getFileSize(FILE *inFile) {
    int fileSize = 0;
    fseek(inFile, 0, SEEK_END);

    fileSize = ftell(inFile);

    fseek(inFile, 0, SEEK_SET);
    return fileSize;
}

FILE * File::getInput() {
    const char *filePath;
    std::string input;

    std::cout << "Input wave file name: ";
    std::cin >> input;
    std::cin.get();
    filePath = input.c_str();

    FILE *wavFile = fopen(filePath, "r");
    if (wavFile == nullptr) {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
    }
    return wavFile;
}