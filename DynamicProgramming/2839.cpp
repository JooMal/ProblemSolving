/*
카테고리 : 다이나믹 프로그래밍
문제명 : 설탕배달
풀이 :
	설탕을 정확하게 N킬로그램 배달, 3kg 봉지와 5kg 봉지가 있다.
	최대한 적은 갯수의 봉지를 가져간다.
	18 = 5*3 + 3
	DP[0] = -1
	DP[1] = -1
	DP[2] = -1
	DP[3] = 1
	DP[4] = -1
	DP[5] = 1
	DP[6] = 2 = min(DP[6-3]+1)
	DP[7] = -1
	DP[8] = 2 = min(DP[8-3]+1, DP[8-5]+1)
	DP[9] = 3 = min(DP[9-3]+1) <- if DP[n] is not -1
	DP[10] = 2 (5*2)
	DP[11] = min(DP[11-5]+1, DP[11-3]+1)
	DP[12] = 12-5(x), 12%3
	DP[18] = 15+3 (4)
*/

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int DP[5001];

int makeN(int sugar)
{
	memset(DP, 0, sizeof(DP));
	DP[3] = DP[5] = 1;
	for (int i = 6; i <= sugar; i++)
	{
		if (DP[i - 3] && DP[i - 5]) DP[i] = min(DP[i - 3] + 1, DP[i - 5] + 1);
		else if (DP[i - 3] && !DP[i - 5]) DP[i] = DP[i - 3]+1;
		else if (!DP[i - 3] && DP[i - 5]) DP[i] = DP[i - 5]+1;
		else DP[i] = 0;
	}
	if (DP[sugar] == 0) DP[sugar] = -1;
	return DP[sugar];
}

int main()
{
	int s;
	cin >> s;
	cout << makeN(s);
}