#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int X)
{
	vector<int> dp;
	dp.resize(1000001);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= X; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	return dp[X];
}

int main()
{
	int X;
	cin >> X;
	cout << solution(X);
	return 0;
}
