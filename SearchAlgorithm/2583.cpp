
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int MAP[101][101];
int visited[101][101];
int cnt;
int tmp_cnt = 0;
vector<int> n_arr;
int N, M, K;

bool isBounded(int y, int x)
{
	return (x >= 0 && x < N) && (y >= 0 && y < M);
}

int Dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void dfs(int y, int x)
{
	tmp_cnt++;
	visited[y][x] = true;
	for (int d = 0; d < 4; d++)
	{
		int dx = x + Dir[d][0];
		int dy = y + Dir[d][1];

		if (isBounded(dy, dx) && !visited[dy][dx])
		{
			if (MAP[dy][dx] == 0) {
				dfs(dy, dx);
			}
		}
	}

}
int main()
{
	memset(visited, false, sizeof(visited));
	memset(MAP, 0, sizeof(MAP));

	cin >> M >> N >> K;
	for (int k = 0; k < K; k++)
	{
		int sx, sy, fx, fy;
		cin >> sx >> sy >> fx >> fy;
		for (int y = sy; y < fy; y++)
		{
			for (int x = sx; x < fx; x++)
			{
				MAP[y][x] = 1;
			}
		}
	}

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			tmp_cnt = 0;
			if (!visited[y][x] && MAP[y][x]==0)
			{
				//cout << x << ", " << y << " : " << MAP[y][x] << endl;
				dfs(y, x);
				cnt++;
			}
			if(tmp_cnt!=0) n_arr.push_back(tmp_cnt);
		}
	}

	sort(n_arr.begin(), n_arr.end());
	cout << cnt << endl;
	for (int i = 0; i < n_arr.size(); i++) cout << n_arr[i] << ' ';
	return 0;
}

