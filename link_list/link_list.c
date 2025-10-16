#include <stdio.h>
#include <stdlib.h>

typedef struct link{
	int data;
	struct link *next;

}link;

void link_add(struct link **link_head, int data)
{
	link *new = (link *)malloc(sizeof(link));
	new->data = data;
	new->next = NULL;

//	printf("new = %p\n", new);
//	printf("*new = %d\n", *new);
//	printf("*new next = %p\n", *(new+sizeof(int)));

	if(*link_head == NULL){
		//新節點	
		*link_head = new;
	}else{
		//不是新節點插入在後面
		link *temp = *link_head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new;
	}

}

void link_delet(link **head)
{//從後面節點開始刪除
	link *temp = *head;
	
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	free(temp->next);

}

void link_print(struct link *link_node)
{
	link *ptr = link_node;	
	int i =0;
	while(ptr->next != NULL)
	{
		printf("link[%d] data =%d\n", i, ptr->data);
		printf("link[%d] next =%p\n", i, ptr->next);
		ptr = ptr->next;
		i++;
	}
	printf("link[%d] data =%d\n", i, ptr->data);
	printf("link[%d] next =%p\n", i, ptr->next);
}

int main()
{
//會先創建一個head，後面新增的會加在head後面
link *head = NULL;
link_add(&head, 1);
link_add(&head, 2);
link_add(&head, 3);
link_delet(&head);
//link_add(head, 2);
//link_add(head, 3);
//	link L1;
//	link L2;
//	link L3;
//
//	L1.data = 1;
//	L1.next = &L2;
//
//	L2.data = 2;
//	L2.next = &L3;
//
//	L3.data = 3;
//	L3.next = NULL;

	link_print(head);

}
