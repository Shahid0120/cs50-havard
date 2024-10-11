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
float calculateAverageNumberSentencesPer100Words(const string& inputString);
void runTest();

int main()
{
    string inputString;
    float colemanLiauScore; 
    string grade; 

    // Initialize Map
    unordered_map<int, string> colemanLiauIndex;
    initialiseColemanLiauIndex(colemanLiauIndex);
    
    // Takes a input from user
    cout << "Text : ";
    getline(cin, inputString);

    // Calculate Average numbers of letter per 100 words
    float L = calculateAverageNumberLetterPer100Words(inputString);

    // Calculate Average number of sentences per 100 words
    float S = calculateAverageNumberSentencesPer100Words(inputString);

    // Combine both metric into a score
    colemanLiauScore = (0.0588 * L) - (0.296 * S) - 15.8;

    // Round for map 
    int closestWholeNumber = round(colemanLiauScore);
    
    if (closestWholeNumber >= 17) // only rounded score not in map is over 17
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
    int totalLetterCount = 0, totalWordCount = 0, count100 = 0;
    float averageLetters;
    // Calculate letter count and word count
    for (int i = 0; i < inputString.length(); i++)
    {
        if ((inputString[i] >= 'A' && inputString[i] <= 'Z') || (inputString[i] >= 'a' && inputString[i] <= 'z')) // Count letters
        {
            totalLetterCount++;
        }
        if (inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\t') // Count words by spaces/newlines/tabs
        {
            totalWordCount++;
        }
    }

    // did we hit 100 words check, +1 since we started with 0 word count, count end word.
    averageLetters = (totalLetterCount > 0) ? 
                    (static_cast<float>(totalLetterCount) / static_cast<float>(totalWordCount + 1)) * 100: 
                    0;

    return averageLetters;
}

float calculateAverageNumberSentencesPer100Words(const string& inputString)
{
    int sentenceCount = 0, wordCount = 0;
    float averageWord;
    // Calculate word count and sentence count
    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\t') // Count words by spaces/newlines/tabs
        {
            wordCount++;
        } else if (inputString[i] == '.' || inputString[i] == '?' || inputString[i] == '!') // Counts sentences
        {
            sentenceCount++;
        }

       
    }


    // Calculate average sentences per 100 words
    averageWord = (sentenceCount > 0) ? 
                (static_cast<float>(sentenceCount) / static_cast<float>(wordCount + 1)) * 100: 
                static_cast<float>(wordCount) * 100;

    return averageWord;
}
