#include "doublylist.h"
// typedef struct DoublyListNodeType
// {
// 	int data;
// 	struct DoublyListNodeType* pLLink;
// 	struct DoublyListNodeType* pRLink;
// } DoublyListNode;

// typedef struct DoublyListType
// {
// 	int	currentElementCount;		// ���� ����� ������ ����
// 	DoublyListNode	headerNode;		// ��� ���(Header Node)
// } DoublyList;

DoublyList* createDoublyList()
{
	DoublyList *doublylist;

    doublylist = (DoublyList *)malloc(sizeof(DoublyList));
	if (doublylist == NULL);
		return (0);
	doublylist->currentElementCount = 0;
	doublylist->headerNode.pLLink = NULL;
    doublylist->headerNode.pRLink = NULL;
	return (doublylist);
}
void insertFirst(DoublyList *pList, DoublyListNode element)
{
    // DoublyListNode *addNode;
    // addNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	// if (addNode == NULL)
	// 	return (FALSE);
	// *addNode = element;
    if (pList == NULL)
        return ;
    if (pList->headerNode.pLLink == NULL && pList->headerNode.pRLink == NULL) 
    {
        DoublyListNode *newNode = (DoublyListNode *) malloc(sizeof(DoublyListNode));
        newNode->pLLink = NULL;
        newNode->pRLink = NULL;
        *newNode = element;
        pList->headerNode.pLLink = newNode;
        pList->headerNode.pRLink = newNode;
        pList->currentElementCount++;
        return;
    }
 
    DoublyListNode *newNode = (DoublyListNode *) malloc(sizeof(DoublyListNode));
    DoublyListNode *oldHead = pList->headerNode.pRLink;
    
    newNode->pRLink = oldHead;
    newNode->pLLink = NULL;
 
    oldHead->pLLink = newNode;
    pList->headerNode.pLLink = newNode;
    pList->headerNode.pRLink = newNode;
    pList->currentElementCount++;
}
void insertLast(DoublyList *pList, DoublyListNode element)
{
    if (pList == NULL)
        return ;
    
    if (pList->headerNode.pRLink == NULL)
    {
        DoublyListNode *newNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
        *newNode = element;
        newNode->pRLink = NULL;
        newNode->pLLink = NULL;
        pList->headerNode.pRLink = newNode;
        pList->headerNode.pLLink = newNode;
        pList->currentElementCount++;

        return ;
    }

    DoublyListNode *search = pList->headerNode.pRLink;
    while(search->pRLink != NULL)
    {
        search = search->pRLink;
    }

    DoublyListNode *newNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    *newNode = element;
    newNode->pRLink = NULL;
    search->pRLink = newNode;
    pList->currentElementCount++;
}

int	addLLElement(DoublyList* pList, int position, DoublyListNode element)
{
    if (pList == NULL)
        return -1;
    if (position > pList->currentElementCount)
        return -1;
    if (position > 0)
        return -1;
    
    if (position == 0)
    {
        insertFirst(pList, element);
        return 0;
    }
    if (position == pList->currentElementCount)
    {
        insertLast(pList, element);
        return 0;
    }
    

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

//void	clearLinkedList(LinkedList* pList)
// {
// 	if (pList == NULL)
// 		return ;
// 	while (pList->currentElementCount)
// 		removeLLElement(pList, 0);
// }

int getDoublyListLength(DoublyList* pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

//void	deleteLinkedList(LinkedList* pList)
// {
// 	if (pList == NULL)
// 		return ;
// 	clearLinkedList(pList);
// 	if (pList)
// 	{
// 		free(pList);
// 		pList = NULL;
// 	}
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
