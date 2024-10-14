#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;

int main()
{   
    const char *wordOne = "Hi";
    const char *wordTwo = "Bye";

    if (strcmp(wordOne, wordTwo) == 0)
    {
        printf("Same!\n");
        return 1;
    } else 
    {
        printf("Correct both words cant be the same!");
        printf("Word one adress %p", &wordOne);
        printf("Word one adress %p", &wordTwo);
    }
}