#include "arrayqueue.h"
#include <stdio.h>

int main()
{
    ArrayQueue *AQ;
    AQ = createArrayQueue(10);
    ArrayQueueNode Node;
    Node.data = 'a';
    enqueueAQ(AQ,Node);
    Node.data = 'b';
    enqueueAQ(AQ,Node);
    int i =0;
    while(AQ->pElement[i].data)
    {
        printf("%c\n",AQ->pElement[i].data);
        i++;
    }
}