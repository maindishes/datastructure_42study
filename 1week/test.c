#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
	int data;
	struct	NODE* next;
}node;



//자기 참조 구조체 포인터 변수 

int	main()
{
	node *head = (node *)malloc(sizeof(node));
	head->next = NULL;

	node *node1 = (node *)malloc(sizeof(node));

	node1->next = head->next; // head가 다음걸 가리키던걸 저장. node1->next 가 head->next 보던걸 저장
	node1->data = 10;

	head->next = node1;

	node *node2 = (node *)malloc(sizeof(node));
	node2->next = node1->next;
	node2->data = 20;
	node1->next = node2;


	//
	node *curr = head->next;
	while(curr != NULL)
	{
		printf("%d\n",curr->data);
		curr = curr->next;
	}

	free(head);
	free(node1);
	free(node2);
	return 0;
}

