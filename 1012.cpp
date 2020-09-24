
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int T, N, M, K = 0;
int arr[51][51];
bool visited[51][51];
vector<pair<int, int>> baechu;

void arrZeroSet(int M, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	return;
}

bool isBounded(int X, int Y)
{
	return (X >= 0 && X < M) && (Y >= 0 && Y < N);
}

int DirXY[4][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
void dfs(int x, int y)
{
	visited[y][x] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int nextX = x + DirXY[dir][0];
		int nextY = y + DirXY[dir][1];

		if (isBounded(nextX, nextY) && arr[nextY][nextX] == 1 && !visited[nextY][nextX]) dfs(nextX, nextY);
	}

	return;
}

int main()
{
	cin >> T;
	if (T == 0) {
		cout << 0; return 0;
	}

	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		arrZeroSet(M, N);
		baechu.clear();
		int cnt = 0;
		for (int k = 0; k < K; k++)
		{
			int X, Y = 0;
			cin >> X >> Y;
			arr[Y][X] = 1;
			baechu.push_back(make_pair(X, Y));
		}

		for (int k = 0; k < K; k++)
		{
			int X = baechu[k].first;
			int Y = baechu[k].second;

			if (!visited[Y][X]) {
				dfs(X, Y); cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
