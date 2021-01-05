#include "pch.h"

/*
2442 별 찍기 - 5
풀이 :
	첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ...
	N번째 줄에는 별 2*(N-1)을 찍되,
	가운데를 기준으로 대칭이어야 한다. (공백)
*/
#include <iostream>	
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int tot = 2 * N - 1;

	for (int i = 1; i <= N; i++)
	{
		int star = i * 2 - 1;
		int space = (tot - star)/2;
		for (int s = 0; s < space; s++) {
			cout << " ";
		}
		for (int st = 0; st < star; st++) cout << "*";
		cout << endl;
	}

	return 0;
}
