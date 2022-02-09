#include "linkedlist.h"
// typedef struct ListNodeType
// {
// 	int data;
// 	struct ListNodeType* pLink;
// } ListNode;

// typedef struct LinkedListType
// {
// 	int currentElementCount;	// ���� ����� ������ ����
// 	ListNode headerNode;		// ��� ���(Header Node)
// } LinkedList;
LinkedList*	createLinkedList()
{
	LinkedList*	linkedlist;

	linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
	if (linkedlist == NULL)
		return (NULL);
	linkedlist->currentElementCount = 0;
	linkedlist->headerNode.pLink = NULL;
	return (linkedlist);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*curr;
	ListNode	*addNode;
	int			i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (ListNode *)malloc(sizeof(ListNode));
	if (addNode == NULL)
		return (FALSE);
	*addNode = element;
	if (pList->currentElementCount == 0)	// node가 하나도 없을때
	{
		pList->headerNode.pLink = addNode;
		addNode->pLink = NULL;
		pList->currentElementCount++;
	}
	else if (position == 0)	// 첫 번째 노드에 추가
	{
		addNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = addNode;
		pList->currentElementCount++;
	}
	else
	{
		curr = pList->headerNode.pLink;
		for (i = 0; i < position - 1; i++)	// position 이전 노드까지 이동
			curr = curr->pLink;
		if (position == pList->currentElementCount)
			addNode->pLink = NULL;
		else
			addNode->pLink = curr->pLink;
		curr->pLink = addNode;
		pList->currentElementCount++;
	}
	return (TRUE);
}

int	removeLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;
	ListNode	*temp;
	int			i;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (FALSE);
	curr = pList->headerNode.pLink;
	if (position == 0)
	{
		temp = curr;
		pList->headerNode.pLink = curr->pLink;
	}
	else
	{
		for (i = 0; i < position - 1; i++)	// position 이전 노드까지 이동
			curr = curr->pLink;
		temp = curr->pLink;
		curr->pLink = curr->pLink->pLink;
	}
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	pList->currentElementCount--;
	return (TRUE);
}

ListNode*	getLLElement(LinkedList* pList, int position)
{
	int			i;
	ListNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)	// position 노드까지 이동
		curr = curr->pLink;
	return (curr);
}

void	clearLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount)
		removeLLElement(pList, 0);
}

int	getLinkedListLength(LinkedList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		return ;
	clearLinkedList(pList);
	if (pList)
	{
		free(pList);
		pList = NULL;
	}
}

/**
 * a b
 * tmp = a;
 * a = b;
 * b = tmp;
 */
void	reverseLinkedList(LinkedList* pList)
{
	ListNode*	prev;
	ListNode*	curr;
	ListNode*	pnode;
	int			i;

	if (pList == NULL)
		return ;
	curr = NULL;
	pnode = pList->headerNode.pLink;
	for (i = 0; i < getLinkedListLength(pList); i++)
	{
		prev = curr;
		curr = pnode;
		pnode = curr->pLink;
		curr->pLink = prev;
	}
	pList->headerNode.pLink = curr;
}


void	list_print(LinkedList *lst)
{
	ListNode	*curr;

	curr = lst->headerNode.pLink;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->pLink;
	}
	printf("\n");
}

int	func1()
{
	LinkedList	*linkedlist;
	linkedlist = createLinkedList();

	ListNode	node;
	node.pLink = NULL;

	node.data = 10;
	addLLElement(linkedlist, 0, node);
	list_print(linkedlist);

	node.data = 11;
	addLLElement(linkedlist, 1, node);
	list_print(linkedlist);

	node.data = 12;
	addLLElement(linkedlist, 2, node);
	list_print(linkedlist);

	node.data = 13;
	addLLElement(linkedlist, 3, node);
	list_print(linkedlist);

	node.data = 14;
	addLLElement(linkedlist, 4, node);
	list_print(linkedlist);

	removeLLElement(linkedlist, 4);
	list_print(linkedlist);

	removeLLElement(linkedlist, 0);
	list_print(linkedlist);

	removeLLElement(linkedlist, 1);
	list_print(linkedlist);

	clearLinkedList(linkedlist);
	list_print(linkedlist);

	deleteLinkedList(linkedlist);
	return 0;
}

void func2(void)
{
	LinkedList*	list;
	ListNode	node;

	list = createLinkedList();
	node.data = 10;
	addLLElement(list, 0, node);
	node.data = 11;
	addLLElement(list, 1, node);
	node.data = 12;
	addLLElement(list, 2, node);

	reverseLinkedList(list);
	list_print(list);
}

int main(void)
{
	// func1();
	func2();
	// system("leaks a.out");
	return (0);
}