#include <stdio.h>
#include <stdlib.h>

void rong(int **p1, int *p2)
{
	*p1 = (int *)malloc(sizeof(int));
	//*p1 = p2;
	**p1 = *p2; 
}

int main()
{
	int a = 10;
	int b = 20;
	int *p = NULL;
	printf("a address = %p\n", &a);
	printf("b address = %p\n", &b);
	printf("p address = %p\n", &p);
	printf("p value = %p\n", p);
	//printf("*p value = %d\n", *p);

	rong(&p, &b);
	printf("Change After\n");
	printf("p address = %p\n", &p);
	printf("p value = %p\n", p);
	printf("*p value = %d\n", *p);
	return 0;
}
