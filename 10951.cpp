#include <stdio.h>

int main()
{
	int A, B;
	while (scanf_s("%d %d", &A, &B) != EOF)
	{
		printf("%d", A + B);
	}
	return 0;
}