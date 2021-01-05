#include "pch.h"

/*
문제 제목 : 거스름돈
카테고리 : 그리디 (1/30)
풀이 :
	10 => 10
	10,15 => 20
	15 => 15
	15,20 => 30
	20 => 20
	10,15,20 => 30
	5,15,20 => 30 (5를 제외)
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
int N;

int main()
{
	int ans = -1;
	cin >> N;
	vector<int> rope_w;
	while (N--) {
		int w;
		cin >> w;
		rope_w.push_back(w);
	}
	sort(rope_w.begin(), rope_w.end(), greater<>());
	int cnt = 1;
	vector<int>::iterator it;
	for (it = rope_w.begin(); it < rope_w.end(); it++) {
		ans = max(ans, (*it)*cnt);
		cnt++;
	}
	cout << ans;
	return 0;
}
