// Asssignment_8_MergeSort.cpp : Defines the entry point for the console application.
//Author Timos Mukoko k00203438

#include "stdafx.h"

using namespace std;

struct Student
{
	string name;
	int kNum;
};

// Functions Prototypes
void MergeSort(Student[], int, int);
void Merge(Student[], int, int, int);

int Menu();
void Exit();
void MergeSortList();
bool quitFlag = false;
Student list[10];


void MergeSort(Student a[], int low, int high)
{
	int mid = 0;

	if (low == high)
	{
		return;
	}
	else
	{
		mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}// end merge_sort()

void Merge(Student a[], int low, int mid, int high)
{
	int i;
	int left_index = low;
	int right_index = mid + 1;
	int combined_index = low;
	Student tempA[10];

	while (left_index <= mid && right_index <= high)
	{
		if (a[left_index].kNum >= a[right_index].kNum)
		{
			tempA[combined_index++] = a[left_index++];
		}
		else
		{
			tempA[combined_index++] = a[right_index++];
		}
	}

	if (left_index == mid + 1)
	{
		while (right_index <= high)
		{
			tempA[combined_index++] = a[right_index++];
		}
	}
	else
	{
		while (left_index <= mid)
		{
			tempA[combined_index++] = a[left_index++];
		}
	}

	for (i = low; i <= high; i++)
	{
		a[i] = tempA[i];
	}
}// end merge() 

int main()
{
	int option;
	do
	{
		option = Menu();

		switch (option)
		{
		case 1:
			MergeSortList();
			break;
		case 2:
			Exit();
			break;
		default:
			cout << "WRONG OPTION";
			break;
		}

	} while (!quitFlag);

	return 0;
}

int Menu()
{
	int option;
	cout << "\n\n\n\t\t\t USING MERGE SORT" << endl;
	cout << "\t\t\t ----------------" << endl;
	cout << "\n\t\t\t1. Input Data ";
	cout << "\n\t\t\t2. Exit ";
	cout << "\n\t\t\tOption: ";
	cin >> option;
	system("cls");
	return option;
}


void SetupList()
{
	
}

void MergeSortList()
{
	int low = 0, high = 9;
	int i;

	cout << " \n\n\t~~~ Please Enter Number randomly and no repeating ~~~ \n" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << "\tEnter Knum : ";
		cin >> list[i].kNum;
		cout << "\tEnter Name : ";
		cin >> list[i].name;
		cout << endl;
	}

	cout << "\n\t------ Unsorted array -------\n" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << "\t " << left << setw(9) << list[i].name << right << setw(9) << list[i].kNum << endl;
	}

	MergeSort(list, low, high);
	cout << "\n\n\t------ MergeSort complete -------" << endl;
	cout << " \n\t------ Print Sorted array -------\n\n" << endl;

	cout << left << setw(13) << "\t Name" << right << setw(9) << " KNumber\n" << endl;

	for (i = 0; i < 10; i++)
	{
		cout <<"\t "<< left << setw(9)<< list[i].name << right << setw(9) << list[i].kNum << endl;
	}
}

void Exit()
{
	quitFlag = true;
}