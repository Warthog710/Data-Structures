//Code written by Quinn Roemer

#include <iostream>

using namespace std;

void sort(int iArray[10]);
void print(int iArray[10]);

int main()
{
	int iArray[10] = { 40, 90, 20, 10, 60, 70, 50, 30, 80, 0 };
	sort(iArray);
}
void sort(int iArray[10])
{

	int biggest = 0;
	int temp;
	int counter = 9;

	bool swapNeeded = false;

	for (int index = 0; index < 10; index++)
	{
		print(iArray);

		for (int count = 0; count <= counter; count++)
		{
			if (iArray[biggest] < iArray[count])
			{
				biggest = count;
				swapNeeded = true;

			}
		}

		if (swapNeeded = true)
		{
			temp = iArray[counter];
			iArray[counter] = iArray[biggest];
			iArray[biggest] = temp;
			counter--;
			biggest = 0;
			print(iArray);

		}

		swapNeeded = false;

	}
}
void print(int iArray[10])
{
	for (int count = 0; count < 10; count++)
	{
		cout << iArray[count] << " ";
	}

	cout << endl;
}