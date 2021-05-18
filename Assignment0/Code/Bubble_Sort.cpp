//Code written by Quinn Roemer

#include <iostream>

using namespace std;

void sort(int iArray[10]);
void print(int iArray[10]);

int main()
{
	int iArray[10] = { 40, 90, 20, 10, 60, 70, 50, 30, 80, 0 };
	sort(iArray);
	return 0;
}
void sort(int iArray[10])
{
	int counter = 9;    
	int temp;
	bool isSort = false;

	for (int count = 0; count < 10; count++)
	{
		print(iArray);

		if (counter == 0)
		{
			break;
		}

		for (int index = 0; index < counter; index++)
		{
			if (iArray[index] > iArray[index + 1])
			{
				temp = iArray[index];
				iArray[index] = iArray[index + 1];
				iArray[index + 1] = temp;
				isSort = true;
				print(iArray);
			}
		}
		counter--;

		if (isSort == false)
		{
			break;
		}
		isSort = false;
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
