
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

LinkedList	*createLinkedList(void)
{
	LinkedList	*ret = NULL;
	ret = (LinkedList *)malloc(sizeof(LinkedList));
	if (!ret)
		return (0);
	memset(ret, 0, sizeof(LinkedList));
	return (ret);
}
int	addLLElement(LinkedList	*pList, int position, ListNode element)
{
	int	i = 0;
	int	ret = FALSE;
	ListNode	*PreNode = NULL;
	ListNode	*NewNode = NULL;
	if (!pList)
		return (ret);
	if (position >= 0 && position <= pList->currentElementCount)
	{
		NewNode = (ListNode *)malloc(sizeof(ListNode));
		if (!NewNode)
			return (ret);
		*NewNode = element;
		NewNode->pLink = NULL;
		PreNode = &(pList->headerNode);
		while (i < position)
		{
			PreNode = PreNode->pLink;
			i++;
		}
		NewNode->pLink = PreNode->pLink;
		PreNode->pLink = NewNode;
		pList->currentElementCount++;
		ret = TRUE;
	}
	return (ret);
}
int removeLLElement(LinkedList* pList, int position)
{
	int	i = 0;
	int	ret = FALSE;
	int	arrayCount = 0;
	ListNode	*pNode = NULL;
	ListNode	*DelNode = NULL;
	if (!pList)
		return (ret);
	arrayCount = getLinkedListLength(pList);
	if (position >= 0 && position < arrayCount)
	{
		pNode = &(pList->headerNode);
		while (i < position)
		{
			pNode = pNode->pLink;
			i++;
		}
		DelNode = pNode->pLink;
		pNode->pLink = DelNode->pLink;
		free(DelNode);
		pList->currentElementCount--;
		ret = TRUE;
	}
	return (ret);
}
ListNode* getLLElement(LinkedList* pList, int position)
{
	int	i = 0;
	ListNode	*ret = NULL;
	ListNode	*pNode = NULL;
	if (!pList)
		return (ret);
	if (position >= 0 && position < pList->currentElementCount)
	{
		pNode = &(pList->headerNode);
		while (i <= position)
		{
			pNode = pNode->pLink;
			i++;
		}
		ret = pNode;
	}
	return (ret);
}
void	clearLinkedList(LinkedList *pList)
{
	if (pList)
	{
		if (pList->currentElementCount > 0)
			removeLLElement(pList, 0);
	}
}
int	getLinkedListLength(LinkedList *pList)
{
	int	ret = 0;
	if (pList)
		ret = pList->currentElementCount;
	return (ret);
}
void	deleteLinkedList(LinkedList *pList)
{
	if (pList)
	{
		clearLinkedList(pList);
		free(pList);
	}
}
