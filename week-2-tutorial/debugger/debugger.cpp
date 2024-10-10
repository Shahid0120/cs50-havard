#include <stdio.h>
#include <iostream>

using namespace std;

void print_height(int height);

int main(void) 
{
    // Declaring Variable 
    int integerInput;
    
    integerInput = 3;

    print_height(integerInput);
}

void print_height(int height)
{
    for(int i = 0; i < height; i++)
    {
        printf("Index : %i ", i);
        printf("#\n");
    }
}
