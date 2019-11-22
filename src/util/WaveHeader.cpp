#include <iostream>
#include <string>
#include <fstream>
#include "waveheader.h"

void WaveHeader::createWaveHeaderStruct()
{
    Wav_Header wh;
    std::cout << wh.bitsPerSample;
}