#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// ���� ������ ����
	int front;					// front ��ġ
	int rear;					// rear ��ġ
	ArrayQueueNode *pElement;	// ��� ������ ���� 1���� �迭 ������
} ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue *AQ;
    AQ = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    if (!AQ)
        return 0;
    AQ->maxElementCount = maxElementCount;
    AQ->currentElementCount = 0;
    AQ->front = 0;
    AQ->rear = 0;
    AQ->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if (AQ->pElement == NULL)
	{
		free(AQ);
		AQ = NULL;
		return (NULL);
	}
    return (AQ);

}
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
  	int current; 
	int max;
    current = pQueue->currentElementCount;
	max = pQueue->maxElementCount;
    if (pQueue == NULL || pQueue->pElement == NULL)
	{
		printf("(NULL)\n");
		return (FALSE);
	}
	pQueue->pElement[current].data = element.data;
    pQueue->currentElementCount++;

	return (TRUE);
}
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);