#include <iostream>
#include <fstream>
#include <string>

#include "waveheader.h"

int WaveHeader::readWaveHeader() {
    // declare struct
    Wav_Header wh;

    // vars
    int headerSize = sizeof(Wav_Header),
        fileLength = 0;

    return 0;
}

int WaveHeader::openFile(int argc, char *argv[]) {
    const char *filePath;
    std::string input;

    if (argc <= 1) {
        std::cout << "Input wave file name: ";
        std::cin >> input;
        std::cin.get();
        filePath = input.c_str();
    }
    else {
        filePath = argv[1];
        std::cout << "Input wave file name: " << filePath << std::endl;
    }

    FILE *wavFile = fopen(filePath, "r");
    if (wavFile == nullptr) {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
        return 1;
    }
}

int WaveHeader::getFileSize(FILE *inFile) {
    int fileSize = 0;
    fseek(inFile, 0, SEEK_END);

    fileSize = ftell(inFile);

    fseek(inFile, 0, SEEK_SET);
    return fileSize;
}