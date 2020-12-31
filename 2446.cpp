#include "pch.h"

/*
별 찍기 5
풀이 :
	N*2 > N*2-2 > N*2-2*2 > ... > ? > 0
*/
#include <iostream>	
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n==1) {
		cout << "*";
		return 0;
		}
	vector<string> ans;

	for (int i = 0; i < n; i++)
	{
		string tmp = "";
		int spaceN = i;
		int starN = 2*n - 2*i -1;
		for (int space = 0; space < spaceN; space++) {
			tmp += " ";
		}
		for (int star = 0; star < starN; star++) {
			tmp += "*";
		}
		cout << tmp << endl;
		ans.push_back(tmp);
	}
	vector<string>::iterator it;
	for (it = ans.end() - 2; it > ans.begin(); it--) {
		cout << *it << endl;
	}
	cout << *(ans.begin());
	return 0;
}
