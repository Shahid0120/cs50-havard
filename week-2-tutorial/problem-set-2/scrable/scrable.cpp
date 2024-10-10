#include <stdio.h>
#include <iostream> 
#include <string> 
#include <map>

using namespace std; 

string check_correct_characters(string s);
string point_system(string player_one_string, string player_two_string);

int main(void)
{

    string Player1String; 
    string Player2String;

    cout << "Player 1: ";
    cin >> Player1String;

    cout << "Player 2: ";
    cin >> Player2String;
    
    string Player1StringCleaned = check_correct_characters(Player1String); 
    string Player2StringCleaned = check_correct_characters(Player2String) ;

    string winner = point_system(Player1StringCleaned, Player2StringCleaned);

    cout << winner << endl;

}   

string check_correct_characters(string s)
{
    // Checks each character in string for conditions
    for(int i = 0; i < s.length(); i++)
    {
        // Ensure not number or special syumsol
        if (s[i] >= 'Z')
        {
            s.erase(i);
        }

        // changing to lower character
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 20;

        }
    }

    return s;
}

string point_system(string player_one_string, string player_two_string)
{
    int points_one = 0;
    int points_two = 0;
    string winner;
    // Create an unordered_map to store the letter-value pairs
    unordered_map<char, int> letterValues;

    // Manually populating the map with letter-value pairs
    letterValues['A'] = 1;
    letterValues['B'] = 3;
    letterValues['C'] = 3;
    letterValues['D'] = 2;
    letterValues['E'] = 1;
    letterValues['F'] = 4;
    letterValues['G'] = 2;
    letterValues['H'] = 4;
    letterValues['I'] = 1;
    letterValues['J'] = 8;
    letterValues['K'] = 5;
    letterValues['L'] = 1;
    letterValues['M'] = 3;
    letterValues['N'] = 1;
    letterValues['O'] = 1;
    letterValues['P'] = 3;
    letterValues['Q'] = 10;
    letterValues['R'] = 1;
    letterValues['S'] = 1;
    letterValues['T'] = 1;
    letterValues['U'] = 1;
    letterValues['V'] = 4;
    letterValues['W'] = 4;
    letterValues['X'] = 8;
    letterValues['Y'] = 4;
    letterValues['Z'] = 10;

    for (int i = 0; i < player_one_string.length(); i++)
    {
        points_one += (int) letterValues[player_one_string[i]];
    }

    for (int i = 0; i < player_two_string.length(); i++)
    {
        points_two += (int) letterValues[player_one_string[i]];
    }

    // Checker Winner by points
    if (points_one > points_two)
    {
        winner = "Player One wins!";
    } else if (points_two < points_one)
    {
        winner = "Player Two wins!";
    } else
    {
        winner = "Tie!";
    }

    return winner; 
}

