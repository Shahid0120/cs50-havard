#include <stdio.h> 

int main()
{
    const char *s = "HELLO!";

    printf("This should print the address of 'H': %p\n", s);
    printf("This is print the values H: %c\n", *s);
    printf("This should print E : %c\n", *(s+1));
    return 0;
}