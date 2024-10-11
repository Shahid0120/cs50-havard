/*
Implements a reability scores for a given input setences by user.

Calculates score using Coleman-Liau index:
    index = 0.0588 * L - 0.296 * S - 15.8
    where 
        L : Average numbers of letters per 100 words
        S : Average number of sentences per 100 words

Coleman-Liau Index grading Map 
Index   Grade Level
    1	1st Grade
    2	2nd Grade
    3	3rd Grade
    4	4th Grade
    5	5th Grade
    6	6th Grade
    7	7th Grade
    8	8th Grade
    9	9th Grade (Freshman)
    10	10th Grade (Sophomore)
    11	11th Grade (Junior)
    12	12th Grade (Senior)
    13	College (1st Year)
    14	College (2nd Year)
    15	College (3rd Year)
    16	College (4th Year)
    17+	Graduate Level
*/
#include <stdio.h>
#include <string>
#include <iostream> 
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

void initialiseColemanLiauIndex(unordered_map<int, string>& colemanLiauIndex);
float calculateAverageNumberLetterPer100Words(const string& inputString);
float calculateAverageNumberSetencesPer100Words(const string& inputString);

int main()
{
    string inputString = "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.";
    float colemanLiauScore; 
    string grade; 

    // Initialize Map
    unordered_map<int, string> colemanLiauIndex;
    initialiseColemanLiauIndex(colemanLiauIndex);
    
    // Takes a input from user
    //cout << "Text : ";
    //cin >> inputString;
    

    // Calculate Average numbers of letter per 100 words
    float averageLetterPer100Words = calculateAverageNumberLetterPer100Words(inputString);

    // Calculate Average number of sentences per 100 words
    float averageSentencesPer100Words = calculateAverageNumberSetencesPer100Words(inputString);

    // Combine both metric into a score
    colemanLiauScore = (0.0588 * averageLetterPer100Words) - (0.296 * averageSentencesPer100Words) - 15.8;

    // Round for map 
    int closestWholeNumber = round(colemanLiauScore);
    
    if (closestWholeNumber > 17) // only rounded score not in map is over 17
    {
        grade = "Graduate Level";
    } else if (closestWholeNumber <= 1)
    {
        grade = "1st Grade";
    } else // inside of map
    {
        grade = colemanLiauIndex[closestWholeNumber];
    }

    cout << grade << endl;
    
    return 0;
}


void initialiseColemanLiauIndex(unordered_map<int, string>& colemanLiauIndex)
{
    colemanLiauIndex[1] = "1st Grade";
    colemanLiauIndex[2] = "2nd Grade";
    colemanLiauIndex[3] = "3rd Grade";
    colemanLiauIndex[4] = "4th Grade";
    colemanLiauIndex[5] = "5th Grade";
    colemanLiauIndex[6] = "6th Grade";
    colemanLiauIndex[7] = "7th Grade";
    colemanLiauIndex[8] = "8th Grade";
    colemanLiauIndex[9] = "9th Grade (Freshman)";
    colemanLiauIndex[10] = "10th Grade (Sophomore)";
    colemanLiauIndex[11] = "11th Grade (Junior)";
    colemanLiauIndex[12] = "12th Grade (Senior)";
    colemanLiauIndex[13] = "College (1st Year)";
    colemanLiauIndex[14] = "College (2nd Year)";
    colemanLiauIndex[15] = "College (3rd Year)";
    colemanLiauIndex[16] = "College (4th Year)";
    colemanLiauIndex[17] = "Graduate Level";
}

float calculateAverageNumberLetterPer100Words(const string& inputString)
{
    int totalLetterCount = 0, totalSpacesCount = 0, numberOfTimeHit100 = 1;
    float average = 0.0;
    
    for (int idx = 0; idx < inputString.length(); idx++)
    {
        if (( inputString[idx] >= 'A' && inputString[idx] <= 'Z')|| (inputString[idx] >=  'a' && inputString[idx] <=  'z'))  // Calculate a total number of letter
        {
            totalLetterCount += 1;
        } else if (inputString[idx] == ' ') // Add total number of spaces 
        {
            totalSpacesCount += 1;
        }

        // There is 99 spaces in 100 words including end and start 
        if (totalSpacesCount - 1 == 100)
        {
            average = (float)totalLetterCount / ((float)totalSpacesCount + 1 );
            numberOfTimeHit100 += 1;

            // We want to restart since we calulate average over 100 words
            totalLetterCount = 0;
            totalSpacesCount = 0;
        }
    }

    if (numberOfTimeHit100 == 1)
    {
        average = (float)totalLetterCount / ((float)totalSpacesCount + 1); 
    }

    // Using Expecation per 100 words
    float score = (float)average / (float)numberOfTimeHit100;
    return  score;
}

float calculateAverageNumberSetencesPer100Words(const string& inputString)
{
    int wordCount = 1, fullStopCount = 0, numberOfTimeHit100 = 1;
    float average = 0.0;

    // Calculates Expectation
    for (int idx = 0; idx < inputString.length(); idx++)
    {
        // Counter for hittig 100 words
        if (inputString[idx] == ' ')
        {
            wordCount += 1;
        } else if (inputString[idx] == '.') // Counts sentences
        {   
            fullStopCount += 1;
        }

        // check if words if 100 
        if (wordCount == 100)
        {
            average = (float)wordCount / (float)fullStopCount;
            numberOfTimeHit100 += 1;

            // We want to restart since we calulate average over 100 words
            wordCount = 0;
            fullStopCount = 0;
        }
    }
    
    if (numberOfTimeHit100 == 1)
    {
        average = (float)wordCount / (float)fullStopCount;
    }


    float score = average / numberOfTimeHit100;
    return score;
}
