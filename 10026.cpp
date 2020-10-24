
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> map;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool visited[301][301] = { false, };

void printMap()
{
	cout << "-----------------------" << endl;
	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r < M; r++)
		{
			cout << map[c][r];
		}
		cout << endl;
	}
	cout << "-----------------------" << endl;
}

void arrangeMap()
{
	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r < M; r++)
		{
			if (map[c][r] < 0) map[c][r] = 0;
		}
	}
}

void clearVisit(int op)
{
	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r < M; r++)
		{
			if (op == 0)
			{
				if (map[c][r] == 0) visited[c][r] = true;
				else visited[c][r] = false;
			}
			else visited[c][r] = false;
		}
	}
}

bool isBounded(int y, int x)
{
	return (y >= 0 && y < N) && (x >= 0 && x < M);
}

void yearPassed(int y, int x)
{
	visited[y][x] = true;
	for (int d = 0; d < 4; d++)
	{
		int dy = y + dir[d][0];
		int dx = x + dir[d][1];

		if (isBounded(dy, dx) && !visited[dy][dx])
		{
			if (map[dy][dx] != 0)
			{
				map[dy][dx]--;
				if (map[dy][dx] <= 0) map[dy][dx] = -1;
			}
		}
	}
}

void getNumDivided(int y, int x)
{
	visited[y][x] = true;
	if (map[y][x] == 0) return;
	for (int d = 0; d < 4; d++)
	{
		int dy = y + dir[d][0];
		int dx = x + dir[d][1];

		if (isBounded(dy, dx) && !visited[dy][dx])
		{
			getNumDivided(dy, dx);
		}
	}
}

bool allZero()
{
	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r < M; r++)
		{
			if (map[c][r] != 0) return false;
		}
	}
	return true;
}
int main()
{
	cin >> N >> M;

	for (int c = 0; c < N; c++)
	{
		vector<int> tmp;
		for (int r = 0; r < M; r++) {
			int n;
			cin >> n;
			tmp.push_back(n);
		}
		map.push_back(tmp);
		tmp.clear();
	}


	int year = 0;
	while (1)
	{
		year++;
		for (int c = 0; c < N; c++)
		{
			for (int r = 0; r < M; r++)
			{
				if (!visited[c][r] && map[c][r] == 0)
				{
					yearPassed(c, r);
				}
			}
		}
		//printMap();
		arrangeMap();
		//printMap();

		clearVisit(0);

		int numDivided = 0;
		for (int c = 0; c < N; c++)
		{
			for (int r = 0; r < M; r++)
			{
				if (!visited[c][r])
				{
					numDivided++;
					getNumDivided(c, r);
				}
			}
		}
		clearVisit(1);

		//cout << "numDivided: " << numDivided << endl;
		if (numDivided >= 2)
		{
			cout << year;
			break;
		}
		if (allZero())
		{
			cout << "0";
			return 0;
		}
	}

	return 0;
}

