#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct arrayElement
{
    string protein;
    int count = 0;
};
//Global Variables
char alphabet[26];
char lookUp[26];
arrayElement proteins[40];
//Function Prototypes
void readHash();
int createKey(string);
int secondKey(int);
void printProteins();
void search(string);
int main()
{
    char cTemp = 'A';
    string searchTerm;

    //Fills the alphabet array with the alphabet.
    for (int count = 0; count < 26; count++)
    {
        alphabet[count] = cTemp;
        cTemp++;
    }

    //Fills the lookUp array with the numbers 1-25.
    for (int count = 0; count < 26; count++)
    {
        lookUp[count] = count;
    }

    readHash();
    printProteins();

    //Searching loop.
    while (true)
    {
        cout << "Please enter a sequence: ";
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
    myfile.open("proteins.txt", ios::in);
    getline(myfile, line);

    while (myfile.peek() != EOF)
    {
        getline(myfile, line);
        key = createKey(line);

        //If the place is empty this code executes.
        if (proteins[key].count == 0)
        {
            proteins[key].protein = line;
            proteins[key].count++;
        }

        //If the place has the same data this code executes.
        if (line == proteins[key].protein)
        {
            proteins[key].count++;
        }

        //If there is a collision this code executes.
        else
        {
            int doubleKey = secondKey(key);

            while (true)
            {
                key = key + doubleKey;

                //If the key is greater than 40 this code executes.
                if (key >= 40)
                {
                    key = key - 39;
                }

                //If the new location is empty this code executes.
                if (proteins[key].count == 0)
                {
                    proteins[key].protein = line;
                    proteins[key].count++;
                    break;
                }

                //If the new location is the same as the current protein this code executes.
                if (line == proteins[key].protein)
                {
                    proteins[key].count++;
                    break;
                }
            }
        }
    }
}

//This function creates a key for a given string.
int createKey(string protein)
{
    int size = protein.length();
    char firstLetter = protein[0];
    char lastLetter = protein[size - 1];
    int key = 0;

    //Looking up the value of the first letter.
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
            key = key + (2 * lookUp[count]);
            break;
        }
    }

    //Returning the key.
    return key % 40;
}

//This function creates the second key if a collision occurs.
int secondKey(int key)
{
    int iTemp = key % 5;

    //Prevents the return of an even number.
    if (iTemp % 2 == 0)
    {
        iTemp++;
    }

    //Returning the second key.
    return iTemp;
}

//This function prints the data.
void printProteins()
{
    int indent = 0;
    cout << "Protein\t\t\t\t\t\t\tCount" << endl;

    for (int count = 0; count < 40; count++)
    {
        //Making sure all lines print evenly.
        if (proteins[count].count != 0)
        {
            if (proteins[count].protein.length() <= 23)
            {
                cout << proteins[count].protein << "\t\t\t\t\t" << proteins[count].count << endl;
            }
            else
            {
                cout << proteins[count].protein << "\t\t\t\t" << proteins[count].count
                     << endl;
            }
        }
    }

    cout << endl;
}

//This function searches for a certain piece of data.
void search(string searchTerm)
{
    //Uppercasing the search term.
    for (int count = 0; count < searchTerm.length(); count++)
    {
        searchTerm[count] = toupper(searchTerm[count]);
    }

    //Creating a key for the searchTerm.
    int key = createKey(searchTerm);

    //Looking for the data.
    if (proteins[key].protein == searchTerm)
    {
        cout << proteins[key].count << " FOUND" << endl;
    }

    //If not found this code executes.
    else
    {
        //Creating a second key to find data.
        int doubleKey = secondKey(key);

        while (true)
        {
            key = key + doubleKey;

            //If the key is greater than 40 this code executes.
            if (key >= 40)
            {
                key = key - 39;
            }

            //If an empty location is found this code executes.
            if (proteins[key].count == 0)
            {
                cout << "NOT FOUND" << endl;
                break;
            }
            
            //If the searchTerm is found this code executes.
            if (proteins[key].protein == searchTerm)
            {
                cout << proteins[key].count << " FOUND" << endl;
                break;
            }
        }
    }
}
