#include <iostream>

int main()
{
    int n = 3;
    int* p = &n;
    printf("This pointer should point at the same address as n: %p\n", p);
    printf("The address of n which is an int starts at: %p\n", &n);

    // Find all 4 bytes where int n = 50 is stored
    char* bytePointer = reinterpret_cast<char*>(p);  // Use a char* pointer to move byte by byte
    for(int i = 0; i < sizeof(int); i++)
    {
        printf("Byte %d of n is stored at address: %p\n", i, (bytePointer + i));
        printf("Values at this adress is : %i\n", *bytePointer);
    }

    return 0;
}
