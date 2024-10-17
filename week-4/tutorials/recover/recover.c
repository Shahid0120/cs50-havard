#include <stdio.h>
#include <stdlib.h>
 
const int BYTES = 512; 


int main(int argc, char *argv[])
{
    unsigned char buffer[BYTES];

    // declare pointer
    unsigned char *output; 

    // point at output file
    output = &buffer[0]; 
    
    // open memory of file using pointer!
    FILE *f = fopen("./card.raw", "r");

    // loops 512 bytes each of which bytes is stores into buffer, 
    // 1 element = 1 byte!
    int file_number = 0;
    while(fread(output, sizeof(unsigned char), 512, f) > 0)
    {   

        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xf0)== 0xe0)
        {
            printf("JPEG header found!\n");
            // take the block and fwrite into our output file! with naming convention
            char fileName[100]; 
            sprintf(fileName, "%0.3i.jpg", file_number);
            printf("%s\n", fileName);
            file_number += 1;
        
            // write the contents of buffer into the file name!
            FILE *p = fopen(fileName, "w");

            fwrite(buffer, sizeof(unsigned char), 512, p);
            fclose(p);
        }
    }

    fclose(f);
    return 0;
    
}