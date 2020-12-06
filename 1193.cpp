#include "pch.h"

/*
풀이 :
	1 : 1/1
	2 : 1/2, 2/1
	3 : 3/1, 2/2, 1/3
	4 : 1/4, 2/3, 3/2, 4/1
	5 : 5/1, 4/2, 3/3, 2/4, 1/5
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int X;
	cin >> X;
	int cnt = 1;
	for (int i = 1; i < 10000000; i++)
	{
		for (int j = 1; j <= i; j++) {
			if (cnt == X) {
				int bunja, bunmo;
				if (i % 2 == 0) {
					bunja = j;
					bunmo = i - j + 1;
				}
				else {
					bunja = i - j + 1;
					bunmo = j;
				}
				cout << bunja << "/" << bunmo;
				return 0;
			}
			cnt++;
		}
	}
	return 0;
}
