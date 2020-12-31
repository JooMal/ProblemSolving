#include "pch.h"

/*
사분면 고르기
풀이 :
	(12,5)인 점 A는 x와 y좌표가 모두 양수이므로 제 1사분면에 속한다.
	점의 좌표를 입력받아 그 점이 어느 사분면에 속하는지 알아내는 프로그램을 작성하시오.
*/
#include <iostream>	

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	
	if (x > 0 && y > 0) cout << 1;
	else if (x < 0 && y > 0) cout << 2;
	else if (x < 0 && y < 0) cout << 3;
	else if (x > 0 && y < 0) cout << 4;

	return 0;
}
