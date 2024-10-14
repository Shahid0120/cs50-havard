// Modifies the volume of an audio file - Shahid Hussain
// fread / fwrite 

#include <cstdio>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <iostream>
#include <stdio.h>

using namespace std;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// Number of byters in .wav sample
const int SAMPLE_SIZE = 2; 

// Prototypes
int read_head(FILE *input,FILE *output);
int amplify_sound(FILE *input, FILE *output, float factor);

int main(int argc, char *argv[])
{
    // takes 3 inputs + \0 end of line argument!
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files from input -> array of uint8_t in header of 44 bytes and -> samples of 2byttes each of int16_t
    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    } 
    

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    int result = read_head(input, output);

    if (result == 0)
    {
        printf("We completed Copying Header file into the output files!\n");
    }

    // TODO: Read samples from input file and write updated data to output file
    int results = amplify_sound(input, output, factor);
    if (result == 0)
    {
        printf("We complated Amplifying sounds from input into output!");
    }
    // Close files
    fclose(input);
    fclose(output);
}

int read_head(FILE *input,FILE *output)
{   
    // create a memory adress to hold header file from input file, of uint8_t, type and length HEADER_SIZE 
    int8_t buffer[HEADER_SIZE];

    size_t elementsRead = fread(buffer, sizeof(uint8_t), HEADER_SIZE , input);
    if(elementsRead != HEADER_SIZE)
    {
        printf("Failed to copy input file into headerMemory");
        return 2;
    }

    // headerMemory contrain now 44 byte long head file we want to write into output file!
    size_t elementsWritten = fwrite(buffer, sizeof(uint8_t), HEADER_SIZE, output);

    if (elementsWritten != HEADER_SIZE)
    {
        printf("Failed to write into output code!");
        return 3; 
    }
    
    return 0;
}

int amplify_sound(FILE *input, FILE *output, float factor)
{
    int16_t buffer; 

    while(fread(&buffer, sizeof(int16_t), 1,input) != 0)
    {

        buffer *= factor;

        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    /*

    // get everyelemnder after HEADER_SIZE
    // then get 2 byters each time 
    // new pointer pointing to when 

    FILE *noHeader = &input[HEADER_SIZE];
    cout << "Adress of noHeader : " << &noHeader << endl;
    cout << "Adress of input file: " << &input << endl;




    // iterated 2 bytes of 16-bit samples
    int *temp = (int*)malloc(2 * sizeof(uint16_t));

    for(int i = 0; *noHeader[i * 2 * sizeof(uint16_t)] != EOF; i++)
    {
        // holding values of sample 2 bytes long
        *temp = noHeader[i * 2 * sizeof(uint16_t) : ((i + 1) * 2 * sizeof(uint16_t))];

        // improve volume!
        *temp = factor * (*temp);

        // fwrite into output file
        size_t elementsWritten = fwrite(temp, sizeof(uint16_t), ???, output);

    }
    free(temp);
    return 0;
    */
    return 0;
}