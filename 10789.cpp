#include "pch.h"

/*
문제 제목 : 토마토
카테고리 : 그래프 이론
풀이 :
	N 세로, M 가로, H 높이, 1 익은토마토, 0익지않은토마토, -1토마토가 없는칸
	하루가 지나면, 하나의 익은 토마토에 인접한(위, 아래, 왼, 오, 앞, 뒤) 익지 않은
	토마토는 익게 된다. 창고에 보관된 토마토들이 며칠이 지나면 다 익는지 '최소 일수'
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{

	deque<string> charArr;
	int maxL = 0;
	for (int h = 0; h < 5; h++)
	{
		string tmp;
		cin >> tmp;
		charArr.push_back(tmp);
		maxL = max(maxL, int(tmp.length()));
	}
	for (int h = 0; h < 5; h++)
	{
		string tmp = charArr.front();
		charArr.pop_front();
		int L = tmp.length();
		tmp.append(maxL - L, '*');
		charArr.push_back(tmp);
	}
	for(int l=0;l<maxL;l++)
		for (int h = 0; h < 5; h++)
		{
			string tmp = charArr.front();
			charArr.pop_front();
			if (tmp[l] != '*') cout << tmp[l];
			charArr.push_back(tmp);
		}

	return 0;
}
