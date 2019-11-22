#ifndef WAVEHEADER_H
#define WAVEHEADER_H

class WaveHeader
{
public:
    typedef struct WAV_HEADER
    {
        /* RIFF Chunk Descriptor */
        uint8_t RIFF[4];
        uint32_t ChunkSize;
        uint8_t WAVE[4];

        // "fmt" sub-chunk //
        uint8_t fmt[4];
        uint32_t Subchunk1Size;
        uint16_t AudioFormat;
        uint16_t NumOfChan;
        uint32_t SamplesPerSec;
        uint32_t bytesPerSec;
        uint16_t blockAlign;
        uint16_t bitsPerSample;

        // "data" sub-chunk //
        uint8_t Subchunk2ID[4];
        uint32_t Subchunk2Size;
    } Wav_Header;
    int readWaveHeader();
    int openFile(int argc, char *argv[]);
    int getFileSize(FILE *inFile);
};

#endif