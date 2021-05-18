#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct arrayElement
{
    string keyword;
    int count = 0;
};

//Global Variables
char alphabet[26];
char lookUp[26] = {17, 16, 21, 29, 7, 5, 22, 15, 0, 21, 14, 22, 9, 23, 16, 2, 10, 25, 18, 28,
                   6, 27, 29, 2, 27, 19};

arrayElement keywords[30];

//Function Prototypes
void readHash();
int createKey(string);
void printKeywords();
void search(string);

int main()
{
    char cTemp = 'a';
    string searchTerm;

    //Fills the alphabet array with the alphabet.
    for (int count = 0; count < 26; count++)
    {
        alphabet[count] = cTemp;
        cTemp++;
    }

    readHash();
    printKeywords();

    //Searching loop.
    while (true)
    {
        cout << "Please enter a keyword: ";
        cin >> searchTerm;

        if (searchTerm == "done" || searchTerm == "DONE")
        {
            break;
        }

        search(searchTerm);
    }
}

//This function reads the list of data and hashes it.
void readHash()
{
    string line;
    int key = 0;
    ifstream myfile;
    myfile.open("keywords.txt", ios::in);
    getline(myfile, line);

    while (myfile.peek() != EOF)
    {
        getline(myfile, line);
        key = createKey(line);

        //If the place is empty this code executes.
        if (keywords[key].count == 0)
        {
            keywords[key].keyword = line;
            keywords[key].count++;
        }

        //If the place has the same data this code executes.
        else
        {
            keywords[key].count++;
        }
    }
}

//This function creates a key for a given string.
int createKey(string keyword)
{
    int size = keyword.length();
    char firstLetter = keyword[0];
    char lastLetter = keyword[size - 1];
    int key = 0;

    for (int count = 0; count < 26; count++)
    {
        if (firstLetter == alphabet[count])
        {
            key = lookUp[count];
            break;
        }
    }

    //Looking up the value of the second letter.
    for (int count = 0; count < 26; count++)
    {
        if (lastLetter == alphabet[count])
        {
            key = key + (lookUp[count]);
            break;
        }
    }

    //Returning the key.
    return ((key + size) % 30);
}

//This function prints the data.
void printKeywords()
{
    cout << "Keyword\t\t\t\tCount" << endl;

    //Printing data evenly.
    for (int count = 0; count < 30; count++)
    {
        if (keywords[count].count == 0)
        {
            continue;
        }

        if (keywords[count].keyword.length() >= 8)
        {
            cout << keywords[count].keyword << "\t\t\t" << keywords[count].count << endl;
            continue;
        }

        else
        {
            cout << keywords[count].keyword << "\t\t\t\t" << keywords[count].count << endl;
        }
    }

    cout << endl;
}

//This function searches for a certain piece of data.
void search(string searchTerm)
{
    //Lowercasing the search term.
    for (int count = 0; count < searchTerm.length(); count++)
    {
        searchTerm[count] = tolower(searchTerm[count]);
    }

    //Creating a key for the searchTerm.
    int key = createKey(searchTerm);

    //Looking for the data.
    if (keywords[key].keyword == searchTerm)
    {
        cout << keywords[key].count << " FOUND" << endl;
    }    
    else
    {
        cout << "NOT FOUND" << endl;
    }
}
