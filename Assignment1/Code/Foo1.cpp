//Original code written by Professor Ross. Modified by Quinn Roemer.
#include <iostream>

using namespace std;

int foo1(int);

int main()
{
	int answer;
	cout << "Please enter desired iterations." << endl;
	cin >> answer;
	answer = foo1(answer);
	cout << "Counter: " << answer << endl;
}

int foo1(int n)
{
	int counter = 0;
	
	for (int i = 0; i < n; i++)
	{
		counter++;
	}

	return counter;
}
