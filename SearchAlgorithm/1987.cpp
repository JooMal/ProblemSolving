
#include "pch.h"
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

int MAP[21][21] = { 0, };
bool visited[21][21] = { false, };
queue<pair<int, int>> q;
int R, C;
bool isBounded(int y, int x)
{
	return (y >= 0 && y < R) && (x >= 0 && x < C);
}

bool isOver[int('Z' - 'A')] = { false, };
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int maxCnt = 0;
int DFS(int y, int x, int cnt)
{
	if (cnt > maxCnt) maxCnt = cnt;
	isOver[MAP[y][x]] = true;

	for (int d = 0; d < 4; d++)
	{
		int dy = y + dir[d][0];
		int dx = x + dir[d][1];

		if (isBounded(dy, dx))
		{
			if (!isOver[MAP[dy][dx]])
			{
				DFS(dy, dx, cnt + 1);
				isOver[MAP[dy][dx]] = false;
			}
		}
	}
	return maxCnt;
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char C;
			cin >> C;
			MAP[i][j] = int(int(C) - 'A');
		}
	}

	cout << DFS(0, 0, 1);
	return 0;
}

