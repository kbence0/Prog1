//gcc drill.c -o main
#include <stdio.h>

void show(char* p, int x)
{
	printf("p is \"%s\" and x is %d\n", p, x);
}


int main()
{
	//1.
	printf("%s\n", "Hello World!");

	//2.
	char h[] = "Hello";
	char w[] = "World!";

	printf("%s %s\n", h,w);

	char test[] = "PText";
	int value = 311;

	show(test,value);

	return 0;
}