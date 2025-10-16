#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
	int data;
	struct Link* next;
}Link;

void link_add(Link **head, int data)
{
	Link *new = (Link *)malloc(sizeof(Link));
	new->data = data;
	new->next = NULL;
	
	if(*head == NULL){
		*head = new;
		printf("第一個node\n");
	}else{
	
		Link *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		printf("第n個node\n");
		temp->next = new;
	}

}

void link_printf(Link *head)
{
	Link *temp = head;
	int i =0;
	while(temp != NULL)
	{
		printf("node[%d] = %d\n", i, temp->data);
		i++;
		temp = temp->next;
	}
}

int main()
{

	Link *head = NULL;
	link_add(&head, 1);
	link_add(&head, 2);
	link_add(&head, 3);	
	
	link_printf(head);
	
//	Link L1;
//	Link L2;
//	Link L3;
//
//	L1.data = 1;
//	L1.next = &L2;
//	L2.data = 2;
//	L2.next = &L3;
//	L3.data = 3;
//	L3.next = NULL;
//	
//	link_printf(&L1);

}
