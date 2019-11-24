#include <iostream>
#include <fstream>
#include <string>

#include "waveheader.h"
#include "file.h"

int WaveHeader::readWaveHeader() {

    // declare structs
    Wav_Header wh;
    File oFile;

    // vars
    int headerSize = sizeof(Wav_Header),
        fileLength = 0;

    FILE *wavFile = oFile.getInput();

    // fileLength is the number of bytes to offset from origin
    fileLength = oFile.getFileSize(wavFile);

    // data from .wav file
    size_t bytesRead = fread(&wh, 1, headerSize, wavFile);
    std::cout << "Header Read: " << bytesRead << " bytes" << std::endl;
    if(bytesRead > 0){
        std::cout << "File is: " << fileLength << " bytes" << std::endl;
        std::cout << "RIFF header :" << wh.RIFF[0] << wh.RIFF[1] << wh.RIFF[2] << wh.RIFF[3] << std::endl;
        std::cout << "WAVE header :" << wh.WAVE[0] << wh.WAVE[1] << wh.WAVE[2] << wh.WAVE[3] << std::endl;
        std::cout << "FMT :" << wh.fmt[0] << wh.fmt[1] << wh.fmt[2] << wh.fmt[3] << std::endl;
        std::cout << "Data size :" << wh.ChunkSize << std::endl;

        // Display the sampling Rate from the header
        std::cout << "Sampling Rate :" << wh.SamplesPerSec << std::endl;
        std::cout << "Number of bits used :" << wh.bitsPerSample << std::endl;
        std::cout << "Number of channels :" << wh.NumOfChan << std::endl;
        std::cout << "Number of bytes per second :" << wh.bytesPerSec << std::endl;
        std::cout << "Data length :" << wh.Subchunk2Size << std::endl;
        std::cout << "Audio Format :" << wh.AudioFormat << std::endl;
        // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM

        std::cout << "Block align :" << wh.blockAlign << std::endl;
        std::cout << "Data string :" << wh.Subchunk2ID[0] << wh.Subchunk2ID[1] << wh.Subchunk2ID[2] << wh.Subchunk2ID[3] << std::endl;
    }
    fclose(wavFile);
    return 0;
}