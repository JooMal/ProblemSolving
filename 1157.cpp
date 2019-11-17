#include <iostream>
#include <cstring>

#define ASCII_a 97
#define ASCII_z 122
#define ASCII_A 65
#define ASCII_Z 90
#define DIF (ASCII_a - ASCII_A)

using namespace std;

int main(void)
{
	char str[1000000];
	int check[26] = { 0, };
	int i;

	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	
	int len = strlen(str); // DO NOT put strlen function in for loop!!
	for (i = 0; i < len; i++)
	{
		int ascii = (int)str[i];
		if (ascii >= ASCII_a && ascii <= ASCII_z) ascii = ascii - DIF;
		int index = ascii - ASCII_A;
		check[index]++;
	}

	int max_value = check[0];
	int max_index = 0;
	int mul_flag = 0;

	for (i = 1; i < 26; i++)
	{
		if (check[i] > max_value)
		{
			max_value = check[i];
			max_index = i;
		}
	}
	for (i = 0; i < 26; i++) if (max_value == check[i]) mul_flag++;
	
	if (mul_flag > 1) cout << "?" << endl;
	else cout << (char)(max_index + ASCII_A) << endl;

	return 0;
}