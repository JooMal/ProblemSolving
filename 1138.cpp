#include "pch.h"

/*
문제 제목 : 단어 수학
카테고리 : 코드 구현력 기르기
풀이 :
	사람들은 자기보다 큰 사람이 왼쪽에 몇 명 있었는지 기억,
	N명의 사람이 있고, 사람들의 키는 1부터 N까지 모두 다르다.
	N은 10보다 작거나 같은 자연수, 둘째 줄에는 키가 1인 사람부터 차례대로 자기보다
	키가 큰 사람이 왼쪽에 몇 명이 있었는지 주어진다.

	4
	2 1 1 0
	4명의 사람, 키가 1인사람은 자기보다 큰 사람이 2명 왼쪽에,
	2인 사람은 왼쪽에 1명, 3인 사람은 왼쪽에 1명, 4인 사람은 왼쪽에 0명

	
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
int arr[11];

int main()
{
	for (int i = 0; i < 11; i++) arr[i] = -1;
	int N = 0;
	cin >> N;
	vector<int> p;
	for(int i=0;i<N;i++) {
		int n;
		cin >> n;
		p.push_back(n);
	}
	for (int i = 0; i < N; i++) {
		int left_p = p[i];
		int cnt = 0;
		for (int j = 0; j < N; j++) 
			if (arr[j] == -1) {
				if (cnt == left_p) arr[j] = i + 1;
				cnt++;
			}
	}
	for (int i = 0; i < N; i++) cout << arr[i] << ' ';
	return 0;
}
