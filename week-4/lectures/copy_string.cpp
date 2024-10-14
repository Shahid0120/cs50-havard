#include <stdio.h>
#include <ctype.h>
#include <iostream>


int main(void)
{
    // s contrain adress of H 
    char *s = "Hi!";

    // now moth s and t are point ot H adress
    char *t = s;

    // if i change using t vairables then im changing s too 
    printf("Adress of s: %p", s);
    printf("Adress of t: %p", t);
    t[0] = toupper(t[0]);
    printf("S: %s", s);
    printf("t: %s", t);
}