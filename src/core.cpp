#include <iostream>
#include "waveheader.h"
#include "file.h"

int main() {

    WaveHeader wh;

    wh.readWaveHeader(1, "sample.wav");

    return 0;
}