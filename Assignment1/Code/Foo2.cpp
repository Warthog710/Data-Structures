//Original code written by Professor Ross. Modified by Quinn Roemer.
#include <iostream>

using namespace std;

int foo2(int);

int main()
{
    int answer;
    cout << "Please enter desired iterations." << endl;
    cin >> answer;
    answer = foo2(answer);
    cout << "Counter: " << answer << endl;
}

int foo2(int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            counter++;
        }
    }
    
    return counter;
}
