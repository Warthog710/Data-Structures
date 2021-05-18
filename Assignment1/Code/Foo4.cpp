//Original code written by Professor Ross. Modified by Quinn Roemer.
#include <iostream>

using namespace std;

long long int foo4(int);

int main()
{
    int answer = 0;
    long long int counter;
    
    while (answer <= 64)
    {
        counter = foo4(answer);

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

long long int foo4(int n)
{
    static long long int counter = 0;
    counter++;

    if (n > 0)
    {
        foo4(n - 1);
        foo4(n - 1);
    }
}
