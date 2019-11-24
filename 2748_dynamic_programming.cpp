
#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

long long int fibo(int num)
{
	if (num == 0) return 0;
	else if (num == 1) return 1;
	if (dp[num] != -1) return dp[num];
	dp[num] = fibo(num - 1) + fibo(num - 2);
	return dp[num];
}

int main()
{
	int num = 0;
	
	cin >> num;
	dp.resize(num + 1, -1);
	long long int res = fibo(num);
	cout << res << endl;
	return 0;
}