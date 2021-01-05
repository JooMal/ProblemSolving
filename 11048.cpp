#include "pch.h"

/*
11048 이동하기
풀이 :
	(1,1)에서 (N,M)까지 이동할 때 가져올 수 있는 사탕 갯수의 최대값
	단, 준규는 (x+1,y), (x,y+1), (x+1,y+1)로만 이동할 수 있다. 
*/
#include <iostream>	
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int dir[3][2] = { {-1,0},{0,-1},{-1,-1} };

bool isValidate(int x, int y)
{
	return (x >= 0) && (y >= 0);
}
int main()
{
	int map[1001][1001];
	int DP[1001][1001];

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (i == 0 && j == 0) {
				cin >> map[0][0];
				DP[0][0] = map[0][0];
				continue;
			}

			cin >> map[i][j];

			int max_v = 0;
			for (int d = 0; d < 3; d++) {
				int next_x = j + dir[d][0];
				int next_y = i + dir[d][1];
				if (isValidate(next_y, next_x)) {
					max_v = max(max_v, DP[next_y][next_x]);
				}
			}
			DP[i][j] = map[i][j] + max_v;
		}
	}

	cout << DP[N - 1][M - 1];
	return 0;

}
