//Original code written by Professor Ross. Modified by Quinn Roemer.
#include <iostream>

using namespace std;

int foo3(int);

int main()
{
    int answer = 0;
    int counter;

    while (answer <= 64)
    {
        counter = foo3(answer);
        cout << "Counter " << answer << ": " << counter << endl;

        if (answer < 16)
        {
            answer++;
        }
        else
        {
            answer = answer * 2;
        }
    }
}

int foo3(int n)
{
    int counter = 0;

    for (int i = n; i > 0; i = i / 2)
    {
        counter++;
    }

    return counter;
}
