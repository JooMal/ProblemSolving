#include "pch.h"

/*
풀이 :
	1/1
	1/2, 2/1
	3/1, 2/2, 1/3
	1/4, 2/3, 3/2, 4/1,
	5/1, 4/2, 3/3, 2/4, 1/5

	분자는 (1,i)로 증가, 분모는 (i,1)로 감소
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		string str;
		cin >> N >> str;

		for (int i = 0; i<int(str.length()); i++) {
			for (int j = 0; j < N; j++) {
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}
