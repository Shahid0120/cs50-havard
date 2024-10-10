#include <stdio.h>

// Constant 
const int SIZE = 3;

// Prototype
float average_scores(int scores[], int size);

int main(void)
{
    int scores[SIZE];
    scores[0] = 42;
    scores[1] = 72;
    scores[2] = 44; 

    printf("Average: %f", average_scores(scores, SIZE));
}

float average_scores(int scores[], int size)
{
    float total_score = 0;
    for (int i = 0; i < size; i++)
    {
        total_score += scores[i];
    }
    return total_score / (float) size;
}   