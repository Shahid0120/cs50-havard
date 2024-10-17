#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    char *blood_idx[] = {"AA", "AB", "AO", "BB", "BO", "OO"};   
    printf("%c", blood_idx[1][1]);
    char *ptr;

    ptr = blood_idx[1];

    printf("%s", ptr);
}