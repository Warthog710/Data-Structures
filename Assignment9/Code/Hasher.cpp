//Code written by Quinn Roemer 4/12/2018.
#include <iostream>
#include <string>

using namespace std;

//Global variables.
int value[26] = {6, 2, 5, 4, 5, 6, 7, 7, 9, 10, 12, 12, 13, 14, 15, 16, 17, 18, 19, 6, 21,
                 22, 23, 24, 25, 26};
char alphabet[26];

int keygen(string);

//Main function to execute.
int main()
{
    string words[10] = {"auto", "break", "case", "const", "for", "switch", "struct", "while",
                        "static", "continue"};

    int keys[10];

    char test = 'a';

    //Loop used to insert a - z into the alphabet array.
    for (int count = 0; count < 26; count++)
    {
        alphabet[count] = test;
        test++;
    }

    //Loop used to call the keygen function for every data string.
    for (int count = 0; count < 10; count++)
    {
        keys[count] = keygen(words[count]);
    }

    //Loop used to output keys.
    for (int count = 0; count < 10; count++)
    {
        cout << words[count] << endl;
        cout << "Key: " << keys[count];
        cout << endl << endl;
    }
}

//This function looks at a string and creates the hashing key.
int keygen(string word)
{
    int size = word.length();
    char firstLetter = word[0];
    char lastLetter = word[size - 1];
    int placeFirst = 0;
    int placeLast = 0;

    //This loop grabs the correct value from the look up table for the first letter.
    for (int count = 0; count < 26; count++)
    {
        if (firstLetter == alphabet[count])
        {
            placeFirst = value[count];
        }
    }

    //This loops grabs the correct value from the look up table for the last letter.
    for (int count = 0; count < 26; count++)
    {
        if (lastLetter == alphabet[count])
        {
            placeLast = value[count];
        }
    }

    //Returning the key.
    return ((placeFirst + placeLast + size) % 10);
}
