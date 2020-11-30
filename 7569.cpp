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
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 101;
int N, M, H;
int res;
int MAP[MAX][MAX][MAX]; // 10^6개

queue < pair<int, pair<int, int>>> q;

bool isIn(int h, int n, int m)
{
	return (h >= 0 && h < H) && (n >= 0 && n < N) && (m >= 0 && m < M);
}

int dir[6][3] = { {0,-1,0},{0,1,0},{0,0,1},{0,0,-1},{-1,0,0},{1,0,0} };

void BFS()
{
	
	while (!q.empty())
	{
		int h = q.front().first;
		int n = q.front().second.first;
		int m = q.front().second.second;
		q.pop();
		for (int d = 0; d < 6; d++)
		{
			int dh = h + dir[d][0];
			int dn = n + dir[d][1];
			int dm = m + dir[d][2];

			if (isIn(dh, dn, dm) && MAP[dh][dn][dm] == 0) {
				MAP[dh][dn][dm] = MAP[h][n][m] + 1;
				res = max(res, MAP[h][n][m]);
				//cout << res << endl;
				q.push(make_pair(dh, make_pair(dn, dm)));
			}
		}
	}
	return;
}
int main()
{
	res = 0;
	int tomato_n = 0;
	cin >> M >> N >> H;
	for(int h=0; h<H; h++)
		for(int n=0;n<N;n++)
			for (int m = 0; m < M; m++) {
				cin >> MAP[h][n][m];
				if (MAP[h][n][m] == 1) q.push(make_pair(h, make_pair(n, m)));
				if (MAP[h][n][m] != -1) tomato_n++;
			}

	if ( (!q.empty()) && (q.size() == tomato_n))
	{
		cout << 0;
		return 0;
	}
	if (q.empty())
	{
		cout << -1;
		return 0;
	}
	BFS();
	
	for (int h = 0; h < H; h++)
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++) {
				if (MAP[h][n][m] == 0) {
					cout << -1; return 0;
				}
			}

	cout << res;
	return 0;
}
