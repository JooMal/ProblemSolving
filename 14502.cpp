/*
카테고리 : 그래프
문제명 : 연구소
풀이 :
	연구소는 크기가 N*M인 직사각형, 벽은 칸 하나를 가득 차지한다.
	바이러스는 __상하좌우__ 인접한 빈 칸으로 퍼져나간다.
	새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
	0은 빈칸, 1은 벽, 2는 바이러스이다.
	벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다.

	1. 벽 생성의 모든 경우의 수 만들기
	2. BFS로 바이러스 퍼뜨리기
	3. 안전영역의 갯수 세기
	4. 가장 큰 안전 영역 구하기
*/

#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 8;
int res;
int N, M;
int MAP[MAX][MAX];
int tmp_MAP[MAX][MAX];
void Print(int(*)[MAX]);

void copy(int (*target)[MAX], int (*dest)[MAX])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			target[i][j] = dest[i][j];
}

bool isIn(int y, int x)
{
	return (y >= 0 && y < N) && (x >= 0 && x < M);
}

int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void BFS()
{
	queue<pair<int, int>> q;
	
	int virus_MAP[MAX][MAX];
	copy(virus_MAP, tmp_MAP);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (virus_MAP[i][j] == 2) q.push(make_pair(i, j));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			if (isIn(dy, dx) && virus_MAP[dy][dx] == 0) {
				virus_MAP[dy][dx] = 2;
				q.push(make_pair(dy, dx));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (virus_MAP[i][j] == 0) ans++;

	res = max(res, ans);
	return;
}

void make_wall(int cnt)
{
	if (cnt == 3)
	{
		BFS();
		return;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (tmp_MAP[i][j] == 0)
			{
				tmp_MAP[i][j] = 1;
				make_wall(cnt + 1);
				tmp_MAP[i][j] = 0;
			}
		}
}

void Print(int(*arr)[MAX])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	return;
}
int main()
{
	res = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (MAP[i][j] == 0) {
				copy(tmp_MAP, MAP);

				tmp_MAP[i][j] = 1; //make wall
				make_wall(1);
				tmp_MAP[i][j] = 0;
			}
		}
	}

	cout << res;
	return 0;
}