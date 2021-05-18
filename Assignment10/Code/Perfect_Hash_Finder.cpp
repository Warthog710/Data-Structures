#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

//Global Data
string keywords[28];
char alphabet[26];
int keys[28];
int lookUp[26] = {0};

//Function prototypes.
void genKey();
bool duplicates();

int main()
{
    cout << "Perfect Hash started (Mod 30)..." << endl;
    srand(time(NULL));
    string line;
    char cTemp = 'a';

    //Grabbing keywords from file.
    ifstream myfile;
    myfile.open("keyWordsUnique.txt", ios::in);

    for (int count = 0; count < 28; count++)
    {
        getline(myfile, line);
        keywords[count] = line;
    }

    //Intilizing the alphabet
    for (int count = 0; count < 26; count++)
    {
        alphabet[count] = cTemp;
        cTemp++;
    }

    //Trying random value until a solution is found.
    while (true)
    {
        for (int count = 0; count < 26; count++)
        {
            lookUp[count] = rand() % 30;
        }
        genKey();
        duplicates();
    }
}

//This algorithm generates the keys for an array of strings.
void genKey()
{
    string word;
    int size = 0;
    char firstLetter;
    char lastLetter;
    int placeFirst = 0;
    int placeLast = 0;

    for (int count = 0; count < 28; count++)
    {
        word = keywords[count];
        size = word.length();
        firstLetter = word[0];
        lastLetter = word[size - 1];
        placeFirst = 0;
        placeLast = 0;

        //This loops grabs the correct value from the look up table for the first letter.
        for (int index = 0; index < 26; index++)
        {
            if (firstLetter == alphabet[index])
            {
                placeFirst = lookUp[index];
                break;
            }
        }

        //This loops grabs the correct value from the look up table for the last letter.
        for (int index = 0; index < 26; index++)
        {
            if (lastLetter == alphabet[index])
            {
                placeLast = lookUp[index];
                break;
            }
        }

        //Storing the key in the keys array.
        keys[count] = ((placeFirst + placeLast + size) % 30);
    }
}

//This function looks for duplicates in the keys array.
bool duplicates()
{
    bool dupe = false;
    string answer;

    //Looking for duplicates.
    for (int count = 0; count < 28; count++)
    {
        for (int index = 0; index < 28; index++)
        {
            if (index == count)
            {
                continue;
            }
            if (keys[index] == keys[count])
            {
                dupe = true;
                break;
            }
        }

        //If a duplicate is found this code executes.
        if (dupe == true)
        {
            break;
        }
    }

    //If no duplicates are found this code executes.
    if (dupe == false)
    {
        cout << "Solution found!" << endl;
        cout << "Look Up Table: " << endl;
        //Printing look up table.
        for (int count = 0; count < 26; count++)
        {
            cout << lookUp[count] << " ";
        }
        cout << endl << endl;
        cout << "Keys:" << endl;

        //Printing keys.
        for (int count = 0; count < 28; count++)
        {
            cout << keywords[count] << endl
                 << keys[count] << endl;
        }

        cout << endl;

        //Prompting the user.
        cout << "Enter anything to find another solution." << endl;
        cin >> answer;
    }
    
    //Returning to caller.
    return dupe;
}