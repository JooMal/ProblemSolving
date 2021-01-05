#include "pch.h"

/*
시간 : 16:00 ~ 
문제 제목 : OX퀴즈
카테고리 : 구현
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int ans;
	int T;
	cin >> T;
	while (T--) {
		ans = 0;
		string str = "";
		cin >> str;
		int tmp_score = 1;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'X') tmp_score = 1;
			else {
				ans += tmp_score;
				tmp_score++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
