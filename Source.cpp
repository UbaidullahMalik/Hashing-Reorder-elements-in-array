#include<iostream>
using namespace std;


void SortArray_Hashtable(int *A, int s1, int *B, int s2)
{
	int min = A[0];
	int max = A[0];
	for (int i = 0; i < s1; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
		if (A[i] < min)
		{
			min = A[i];
		}
	}

	int size = max - min + 1; 
	cout << "Max = " << max << endl;
	int* occurences;
	occurences = new int[size] {0};

	for (int j = 0; j < s1; j++)
	{
		occurences[A[j]-min]++;
	}

	for (int i = 0; i < s2; i++)
	{
		for (int j = 0; j < occurences[B[i] - min];)
		{
			cout << B[i]<<" ";
			occurences[B[i] - min]--;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << i + min << " ";
		occurences[i]--;
	}

	delete[] occurences;
}


int main()
{
	int size1 = 0;
	int size2 = 0;
	int* Array1, * Array2;
	cout << "Please enter size of 1st Array: ";
	cin >> size1;

	Array1 = new int[size1];

	for (int i = 0; i < size1; i++)
	{
		cout << "\nEnter value for index " << i << " of Array 1: ";
		cin >> Array1[i];
	}

	cout << "\nPlease enter size of 2nd Array: ";
	cin >> size2;

	Array2 = new int[size2];

	for (int i = 0; i < size2; i++)
	{
		cout << "\nEnter value for index " << i << " of Array 2: ";
		cin >> Array2[i];
	}
	
	/*
	int first[15] = { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 };
	int second[4] = {3, 5, 7, 2};*/

	SortArray_Hashtable(Array1, size1, Array2, size2);

	delete[] Array1;
	delete[] Array2;
	return 0;
}
