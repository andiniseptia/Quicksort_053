#include<iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movement
int n;

void input() {
	while (true)
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMasukkan panjang array adalah 0" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
//swap the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high) //Langkah 1
		return;

	//Partition the list into two parts;
	//One containing elements less that or equal to pivot
	//Outher containing elements grather than pivot

	pivot = arr[low]; //Langkah 2

	i = low + 1; //Langkah 3 
	j = high; //Langkah 4

	while (i <= j) //Langkah 10
	{
		//Search for an element greater than pivot 
		while ((arr[i] <= pivot) && (i <= high)) //Langkah 6
		{
			i++; //Langkah 6
			cmp_count++;
		}
		cmp_count++;
		//Search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low)) //Langkah 7
		{
			j--; //Langkah 8
			cmp_count++;
		}
		cmp_count++;
		if (i < j) //Langkah 9
			//If the greater element is on the left of the element
		{
			//Swap the element at index i with the element at index j
			swap(i, j);
			mov_count++;
		}
	}
}