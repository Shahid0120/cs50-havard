#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BYTES = 512; 


int main(int argc, char *argv[])
{
    /*
    if (argc != 2)
    {
        printf("You inputed too many command Line arguements");
    }
    */

    uint8_t buffer[BYTES];

    // declare pointer
    uint8_t *output; 

    // point at output file
    output = &buffer[0]; 
    
    // open memory of file using pointer!
    FILE *f = fopen("./card.raw", "r");

    // loops 512 bytes each of which bytes is stores into buffer, 
    // 1 element = 1 byte!
    int file_number = 0;  
    int found_file_writing = 1;
    FILE *p = NULL;
    while(fread(output, sizeof(uint8_t), 512, f) > 0)
    {   
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xf0)== 0xe0)
        {
            if(found_file_writing == 0)
            {
                fclose(p);
            }

            // continue writing check
            found_file_writing = 0;

            printf("JPEG header found!\n");
            char fileName[10];
            sprintf(fileName, "%0.3i.jpg", file_number);

            // check file number!
            printf("%s\n", fileName);
            file_number += 1;

            // open new file
            p = fopen(fileName, "w");

            // write the contents of buffer into the file name!
            fwrite(buffer, sizeof(unsigned char), 512, p);

            // one we find it -> we continue writing code into the file
            // until we find the next  
        } else if(found_file_writing == 0) // continue wirting
        {
             fwrite(buffer, sizeof(unsigned char), 512, p);
        }
    }

    fclose(f);
    return 0;
    
}