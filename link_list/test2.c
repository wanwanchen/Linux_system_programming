#include <stdio.h>
#include <stdlib.h>

struct Data{
	int data;
};
void rong(struct Data **ptr)
{
	if(*ptr == NULL){
		printf("rong ptr == NULL\n");
	}
	*ptr = (struct Data *)malloc(sizeof(struct Data));
	(*ptr)->data = 30;
}

void rong2(int **p, int *p2)
{
	if(*p == NULL)
	{
		printf("address == NULL\n");
		*p = (int *)malloc(sizeof(int));
	printf("main p address = %p\n", p);
	printf("main *p address = %p\n", *p);
	printf("main **p address = %d\n", **p);
		
	}
	
	*p2 = 20; 
	*p = p2;
	printf("main p address = %p\n", p);
	printf("main *p address = %p\n", *p);
	printf("main **p address = %d\n", **p);
}
int main()
{
	struct Data *p = NULL;
	//p = (struct Data *)malloc(sizeof(struct Data));
	rong(&p);
	
	printf("main p = %d\n", p->data);

	int a = 10;
	int *c = NULL;
	rong2(&c, &a);
	printf("main a = %d\n", a);
	printf("main a address = %p\n", a);
	printf("main c address = %p\n", c);
	printf("main *c address = %p\n", *c);
	printf("main c = %d\n", *c);

}
