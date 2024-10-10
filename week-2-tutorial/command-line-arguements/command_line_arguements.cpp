#include <stdio.h>
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
    for(int idx = 1; idx < argc; idx++)
    {
        printf("Hello, %s\n", argv[idx]);
    }
    return 0;
}

