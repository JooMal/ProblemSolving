#include "pch.h"

/*
풀이 :
	그룹 단어란, 단어에 존재하는 모든 문자에 대해서, 각 문자에 연속해서
	나타나는 경우만을 말한다. 가령, 
	ccazzzzbb는 cazb가 연속해서 나타난다.
	kin도 연속해서 나타난다.
	aabbccb는 abc에 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
	
	그룹단어 판별은 어떻게?
	boolean 배열이면 될 것 같음, 각 알파벳(26) 별 부울 배열에서
	연속 구간이 나오면 true로 바꾸고,
	true인데 또 true로 바꾸게 되면 false가 된다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool alpha[26] = { false, };

int main()
{
	int T;
	cin >> T;

	int cnt = 0;
	while (T--) {
		for (int i = 0; i < 26; i++) alpha[i] = false;
		string str;
		cin >> str;
		bool group_word = true;
		for (int i = 0; i< int(str.length());i++) {
			int idx = int(str[i] - 'a');
			if (alpha[idx] == false)
			{
				alpha[idx] = true;
				while (str[i + 1] == str[i]) i++;
			}
			else group_word = false;
		}
		if (group_word) cnt++;

	}
	cout << cnt;
	return 0;
}
