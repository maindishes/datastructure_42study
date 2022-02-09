//#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode {
	struct	LinkedNode *next;
	int 	data;
} LinkedNode;

typedef struct LinkedList {
	LinkedNode headerNode;
	int currentElementCount;
} LinkedList;

LinkedList *createLinkedList()
{
	LinkedList *emptyList;
	emptyList = (LinkedList *)malloc(sizeof(LinkedList));
	if (!emptyList)
		return NULL;
	emptyList->currentElementCount = 0;
	emptyList->headerNode.next = NULL;
	return emptyList;
}


void insertFirst(LinkedList *list, int elem)
{
	if (list == NULL)
		return ;

	if (list->headerNode.next == NULL)
	{
		LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
		if (!newNode)
			return ;
		newNode->next = NULL;
		newNode->data = elem;
		list->headerNode.next = newNode;
		list->currentElementCount++;
		return ;
	}
	LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	LinkedNode *oldHead = list->headerNode.next;
	newNode->data = elem;
	newNode->next = oldHead;
	list->headerNode.next = newNode;
	list->currentElementCount++;
}
void insertLast(LinkedList *list, int elem)
{
	if (list == NULL)
		return ;
	
	if (list->headerNode.next == NULL)
	{
		LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
		newNode->next = NULL;
		newNode->data = elem;
		list->headerNode.next = newNode;
		list->currentElementCount++;
		return ;
	}

	LinkedNode *search;
	search = (list->headerNode.next);
	while(search->next != NULL)
	{
		search = search->next;
	}

	LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	newNode->data = elem;
	newNode->next = NULL;
	search->next = newNode;
	list->currentElementCount++;
}

LinkedNode  Nodereturn(int element)
{
	LinkedNode list;
	list.data = element;
	return list;
}

int addLLElement(LinkedList* list, int position, LinkedNode element)
{
	LinkedNode *addnode;
	*addnode = element;
	if (list == NULL)
		return -1;
	if (position > list->currentElementCount)
	{
		return -1;
	}
	if (position < 0)
		return -1;

	if (position == 0)
	{
		insertFirst(list,);
		return 1;
	}
	if (position == list->currentElementCount)
	{
		insertLast(list,ele);
		return 1;
	}
	LinkedNode *search = list->headerNode.next;
    int i;
    for(i = 0 ; i < position-1 ; i++){
        search = search->next;
    }
 
    LinkedNode *newNode = (LinkedNode*)malloc(sizeof(LinkedNode));
    newNode->data = ele;
    newNode->next = search->next;
    search->next = newNode;
    list->currentElementCount++;
	return 0;

}

//int removeLLElement(LinkedList* pList, int position)

//ListNode* getLLElement(LinkedList* pList, int position)

int size(LinkedList *list)
{
	if (list == NULL)
		return -1;
	return list->currentElementCount;
}

int isEmpty(LinkedList *list)
{
	if (list ==NULL)
		return -1;
	return size(list) == 0 ? 1 : 0;
}

void clearLinkedList(LinkedList* pList)
{
	if (pList == NULL)
	{
		return ;
	}

	LinkedNode *head = pList->headerNode.next;
	while(head != NULL)
	{
		LinkedNode *remove = head;
		head = head->next;
		free(remove);
	}
	free(pList);
}


int getLinkedListLength(LinkedList* pList)
{
	if (pList == NULL)
		return -1;
	return pList->currentElementCount;
}



//void deleteLinkedList(LinkedList* pList)


void printList(LinkedList *pList)
{
	if (pList == NULL)
		return ;

	int count = getLinkedListLength(pList);
	int i;

	LinkedNode *search = pList->headerNode.next;
	if(search == NULL)
	{
		printf("List is Empty");
		return ;
	}

	printf( "list = [");
	for( i = 0; i < count; i++)
	{
		printf("%d",search->data);
		search = search->next;
		if( i != count -1)
		{
			printf(" , ");
		}
	}
	printf("]\n");
}



/////////////main


int main() 
{
    LinkedList *list = createLinkedList();
    insertLast(list, 1); // [1]
    insertLast(list, 2); // [1, 2]
    insertLast(list, 3); // [1, 2, 3]
    insertFirst(list, 4); // [4, 1, 2, 3]
    insertFirst(list, 5);; // [5, 4, 1, 2, 3]
    addLLElement(list, 6, Nodereturn(3)); // [5, 4, 1, 6, 2, 3]
    addLLElement(list, 7, Nodereturn(0)); // [7, 5, 4, 1, 6, 2, 3]
//    insert(list, 8, 7);; // [7, 5, 4, 1, 6, 2, 3, 8]
//    removeFirst(list); // [5, 4, 1, 6, 2, 3, 8]
//    removeFirst(list); // [4, 1, 6, 2, 3, 8]
//    removeLast(list); // [4, 1, 6, 2, 3]
//    removeLast(list); // [4, 1, 6, 2]
//    removeIndex(list, 2); // [4, 1, 2]
//
    printList(list);
//    printf("list[0] = %d\n", get(list, 0)); // 4
//    printf("list[1] = %d\n", get(list, 1)); // 1
//    printf("list[2] = %d\n", get(list, 2)); // 2
//    printf("is list empty ? {0:NO, 1:YES) => %d\n", isEmpty(list)); // 0
//    printf("size = %d\n", size(list)); // 3
    clearLinkedList(list);
    return 0;
}
