#include "pch.h"

/*
10250 ACM 호텔
풀이 :
	호텔 정문으로부터 가장 최단거리 방을 선호한다.
	각 층에 W개의 방이 있는 H층 건물,
	엘리베이터는 가장 왼쪽, 엘리베이터를 타는 이동거리는 신경x
	호텔 정문은 일층 엘리베이터 바로 앞에 있고, 정문에서 엘리베이터까지의 거리는 무시
	걷는 거리가 같을 때에는 아래층의 방을 더 선호한다.
*/
#include <iostream>	
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T, H, W, N;
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;
		
		int x = 1;
		while (N > H) {
			x++;
			N -= H;
		}
		cout << N*100 + x << endl;
	}

	return 0;
}
