#include "pch.h"

#include <iostream>	
#include <vector>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <conio.h>

int MAX_LEN, MAX_RAND, REP, INC;

using namespace std;

void Print(int list[], int len);
void makeArr(int list[]);

inline void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

void quickSort(int A[], int low, int high) {
	if (low >= high) return; // base condition

	// divide process
	int i = low - 1, j = low;
	int&pivot = A[high];
	for (; j < high; ++j) {
		if (A[j] < pivot)
			swap(A[++i], A[j]);
	}
	swap(A[++i], pivot);

	// conquer process
	quickSort(A, low, i - 1);
	quickSort(A, i + 1, high);
}

string test()
{
	clock_t start, end;

	string outStr = "";
	int *list = new int[MAX_LEN];
	makeArr(list);
	int len = MAX_LEN;

	start = clock();
	quickSort(list, 0, len - 1);
	end = clock();
	double res = double(end - start) / double(CLOCKS_PER_SEC);
	printf("Implemented QuickSort : %f\n", res);
	outStr += to_string(res);
	outStr += ",";

	int *list2 = new int[MAX_LEN];
	makeArr(list2);
	int len2 = MAX_LEN;

	clock_t start2, end2;
	start2 = clock();
	sort(list2, list2 + len2);
	end2 = clock();
	double res2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
	printf("C++ Algorithm QuickSort : %f\n", res2);
	outStr += to_string(res2);
	outStr += "\n";
	return outStr;
}
int main()
{
	cout << "##########################################\n";
	cout << "############ Quick Sort Test #############" << endl;
	cout << "##########################################\n" << endl;

	cout << "1) Enter START NUMBER OF ARRAY NODE (recommended value: 10000):";
	cin >> MAX_LEN;
	MAX_RAND = MAX_LEN;

	cout << "2) Enter NUMBER OF ITERATION (recommended value: 1000):";
	cin >> REP;

	cout << "3) Enter THE INCREMENT PER ITERATION (recommended value: 100):";
	cin >> INC;
	cout << endl;

	cout << "############ QUICK SORT START ############" << endl;

	int d = 1000;
	string outStr = "";
	ofstream out("result.txt");
	for (int i = 0; i < REP; i++)
	{
		printf("-------- Array Length [%d] -------\n", d);
		outStr += to_string(d);
		outStr += ",";
		MAX_LEN = MAX_RAND = d;
		outStr += test();
		d += INC;
	}
	out << outStr << endl;

	cout << "############ QUICK SORT END ############" << endl;
	cout << "Press any key to exit";
	_getch();
	return 0;
}

void Print(int list[], int len) {
	for (int i = 0; i < len; i++) {
		cout << list[i] << " ";
	}
}

void makeArr(int list[]) {
	for (int i = 0; i < MAX_LEN; i++) list[i] = rand() % MAX_RAND;
}