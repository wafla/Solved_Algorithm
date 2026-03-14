#include <stdio.h>
int main()
{
	char a[51] = { 0 };
	int k = 0;
	scanf("%s", &a);
	while (a[k]!=0)
	{
		printf("%c", a[k]);
		k++;
	}
	printf("??!");
}