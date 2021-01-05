#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


int main()
{
	int N;
	cin >> N;
	for (int i = N; i > 0; i--) {
		for (int k = 0; k < i; k++) cout << "*";
		cout << endl;
	}
	return 0;
}
