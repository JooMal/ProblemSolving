#include "pch.h"

/*
상수
풀이 :
	수의 크기를 비교하는 문제
	상수는 수를 거꾸로 읽어서 둘 중 큰 수를 답한다.
*/
#include <iostream>	
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	string strA = to_string(A);
	string strB = to_string(B);
	
	reverse(strA.begin(), strA.end());
	reverse(strB.begin(), strB.end());

	A = atoi(strA.c_str());
	B = atoi(strB.c_str());
	if (A > B) cout << A;
	else cout << B;

	return 0;
}
