
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int N;
int cnt = 0;
int MAP[101][101];
bool visited[101][101];

void clearVisited()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
		}
	return;
}

bool isBounded(int y, int x)
{
	return ((x >= 0) && (x < N)) && ((y >= 0) && (y < N));
}

int Dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void dfs(int y, int x, int h)
{
	visited[y][x] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int dx = x + Dir[dir][0];
		int dy = y + Dir[dir][1];

		if (isBounded(dy, dx) && !visited[dy][dx])
		{
			if (MAP[dy][dx] > h)
			{
				dfs(dy, dx, h);
			}
		}
	}
	return;
}
int main()
{
	cin >> N;
	int hMax = -1;
	int cntMax = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int k;
			cin >> k;
			MAP[i][j] = k;
			if (hMax < k) hMax = k;
		}
	}

	for (int h = 0; h <= hMax; h++)
	{
		//cout << "-----" << endl;
		clearVisited();
		cnt = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (!visited[y][x] && (MAP[y][x] > h)) {
					dfs(y, x, h); cnt++;
					//cout << x << ", " << y << " : " << MAP[y][x] << " cnt : " << cnt << endl;
				}	
			}
		}
		if (cnt > cntMax) cntMax = cnt;
		//cout << cntMax << endl;
	}

	cout << cntMax << endl;
	return 0;
}

