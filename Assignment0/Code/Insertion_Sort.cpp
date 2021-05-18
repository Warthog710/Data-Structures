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
	int sort, temp;

	for (int count = 0; count < 10; count++)
	{
		sort = count;
		print(iArray);

		while (sort > 0 && iArray[sort] < iArray[sort - 1])
		{
			temp = iArray[sort];
			iArray[sort] = iArray[sort - 1];
			iArray[sort - 1] = temp;
			sort--;
			print(iArray);
		}
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