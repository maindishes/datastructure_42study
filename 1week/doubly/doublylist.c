#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//typedef struct LinkedNode {
//    struct LinkedNode *next;
//    struct LinkedNode *prev;
//    int data;
//} LinkedNode;
// 
//typedef struct LinkedList {
//    LinkedNode *head;
//    LinkedNode *tail;
//    int count;
//} LinkedList;

 typedef struct DoublyListNodeType
 {
      int data;
      struct DoublyListNodeType* pLLink;
      struct DoublyListNodeType* pRLink;
 } DoublyListNode;

 typedef struct DoublyListType
 {
      int     currentElementCount;            // ���� ����� ������ ����
      DoublyListNode  headerNode;             // ��� ���(Header Node)
 } DoublyList;

DoublyList * createDoublyList() 
{
    DoublyList *doublylist = (DoublyList *) malloc(sizeof(DoublyList));
    if (doublylist == NULL)
	    return (0);
	doublylist->currentElementCount = 0;
	doublylist->headerNode.pLLink = NULL;
    doublylist->headerNode.pRLink = NULL;
	return (doublylist);
}
 
/**
 * return list's size
 *
 * @param list list to check size
 * @return list's size
 * */
int size(LinkedList *list) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
    return list->count;
}
 
/**
 * check whether list is empty or not
 *
 * @param list list to check
 * @return whether empty or not (0 : not empty , 1 : empty)
 * */
int isEmpty(LinkedList *list) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
    return size(list) == 0 ? 1 : 0;
}
 
/**
 * insert an element at list's front
 *
 * @param list list to insert
 * @param elem element to insert
 * */
void insertFirst(LinkedList *list, int elem) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    if (list->head == NULL) {
        LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->data = elem;
        list->head = newNode;
        list->tail = newNode;
        list->count++;
        return;
    }
 
    LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
    LinkedNode *oldHead = list->head;
    newNode->data = elem;
    newNode->next = oldHead;
    newNode->prev = NULL;
 
    oldHead->prev = newNode;
    list->head = newNode;
    list->count++;
}
 
/**
 * insert an element at list's back
 *
 * @param list list to insert
 * @param elem element to insert
 * */
void insertLast(LinkedList *list, int elem) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    if (list->head == NULL) {
        LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->data = elem;
        list->head = newNode;
        list->tail = newNode;
        list->count++;
        return;
    }
 
    LinkedNode *oldNode = list->tail;
    LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
    newNode->data = elem;
    newNode->next = NULL;
    newNode->prev = oldNode;
 
    oldNode->next = newNode;
    list->tail = newNode;
    list->count++;
}
 
/**
 * insert an element at index that user request
 *
 * @param list list to insert
 * @param elem element to insert
 * @param index index that user request
 * */
void insert(LinkedList *list, int elem, int index) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    if (index > list->count) {
        printf("ArrayIndexOutOfBoundException Occurred. count = %d, index = %d\n", list->count, index);
        exit(1);
    }
 
    if (index < 0) {
        printf("NegativeArrayIndexException Occurred index = %d\n", index);
        exit(1);
    }
 
    if (index == 0) {
        insertFirst(list, elem);
        return;
    }
 
    if (index == list->count) {
        insertLast(list, elem);
        return;
    }
 
    if (index > list->count / 2) { // check whether head is more near or tail is more near
        // case : tail is more near
        LinkedNode *search = list->tail;
        int i;
        for (i = 0; i < index - 1; i++) {
            search = search->prev;
        }
        LinkedNode *next = search->next;
        LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
        newNode->data = elem;
        newNode->prev = search;
        newNode->next = search->next;
 
        search->next = newNode;
        next->prev = newNode;
        list->count++;
 
    } else {
        // case : head is more near
        LinkedNode *search = list->head;
        int i;
        for (i = 0; i < index - 1; i++) {
            search = search->next;
        }
        LinkedNode *next = search->next;
        LinkedNode *newNode = (LinkedNode *) malloc(sizeof(LinkedNode));
        newNode->data = elem;
        newNode->prev = search;
        newNode->next = search->next;
 
        search->next = newNode;
        next->prev = newNode;
        list->count++;
    }
}
 
/**
 * remove an element at list's front
 *
 * @param list list to remove
* */
void removeFirst(LinkedList *list) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    LinkedNode *oldHead = list->head;
    LinkedNode *newHead = oldHead->next;
    newHead->prev = NULL;
    list->head = newHead;
    free(oldHead);
    list->count--;
}
 
/**
 * remove an element at list's back
 *
 * @param list list to remove
* */
void removeLast(LinkedList *list) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    LinkedNode *oldLast = list->tail;
    LinkedNode *newLast = oldLast->prev;
    newLast->next = NULL;
 
    list->tail = newLast;
    free(oldLast);
    list->count--;
}
 
/**
 * remove an element at index that user request
 *
 * @param list list to remove
 * @param index index that user request
* */
void removeIndex(LinkedList *list, int index) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    if (index > list->count) {
        printf("ArrayIndexOutOfBoundException Occurred. count = %d, index = %d\n", list->count, index);
        exit(1);
    }
 
    if (index < 0) {
        printf("NegativeArrayIndexException Occurred index = %d\n", index);
        exit(1);
    }
 
    if (index == 0) {
        removeFirst(list);
        return;
    }
 
    if (index == list->count) {
        removeLast(list);
        return;
    }
 
    if (index > list->count / 2) { // check whether head is more near or tail is more near
        LinkedNode *prev = list->tail;
        int i;
        for (i = 0; i < index - 1; i++) {
            prev = prev->prev;
        }
 
        LinkedNode *remove = prev->next;
        LinkedNode *next = remove->next;
        prev->next = next;
        next->prev = prev;
        free(remove);
        list->count--;
    } else {
        LinkedNode *prev = list->head;
        int i;
        for (i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        LinkedNode *remove = prev->next;
        LinkedNode *next = remove->next;
        prev->next = next;
        next->prev = prev;
        free(remove);
        list->count--;
    }
}
 
/**
 * return an element at index that user request
 *
 * @param list list to search
 * @param index index that user request
 * @return an element located index that user request
* */
int get(LinkedList *list, int index) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    if (index > list->count) {
        printf("ArrayIndexOutOfBoundException Occurred. count = %d, index = %d\n", list->count, index);
        exit(1);
    }
 
    if (index < 0) {
        printf("NegativeArrayIndexException Occurred index = %d\n", index);
        exit(1);
    }
 
    if (index > list->count / 2) {
        LinkedNode *search = list->tail;
        int i;
        for (i = 0; i < list->count - index - 1; i++) {
            search = search->prev;
        }
        return search->data;
    } else {
        LinkedNode *search = list->head;
        int i;
        for (i = 0; i < index; i++) {
            search = search->next;
        }
        return search->data;
    }
}
 
/**
 * print list like below
 * list = [1 , 2 , 3]
 *
 * @param list list to print
 * */
void printList(LinkedList *list) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    int count = size(list);
    int i;
    LinkedNode *search = list->head;
    if (search == NULL) {
        printf("List is Empty");
        return;;
    }
 
    printf("list = [");
    for (i = 0; i < count; i++) {
        printf("%d", search->data);
        search = search->next;
        if (i != count - 1) {
            printf(" , ");
        }
    }
    printf("]\n");
}
 
/**
 * print list like below
 * reverse = [1 , 2 , 3]
 *
 * @param list list to print
 * */
void printReverse(LinkedList *list) {
    if (list == NULL) {
        printf("NullPointerException Occurred\n");
        exit(1);
    }
 
    int count = size(list);
    int i;
    LinkedNode *search = list->tail;
    if (search == NULL) {
        printf("List is Empty");
        return;;
    }
 
    printf("reverse = [");
    for (i = 0; i < count; i++) {
        printf("%d", search->data);
        search = search->prev;
 
        if (i != count - 1) {
            printf(" , ");
        }
    }
 
    printf("]\n");
}
 
/**
 * return memory located wasted list
 *
 * @param list list to return
 * */
void freeList(LinkedList *list) {
    if (list == NULL) {
        printf("NullPointerException Occurred");
        exit(1);
    }
 
    LinkedNode *head = list->head;
    while (head != NULL) {
        LinkedNode *remove = head;
        head = head->next;
        free(remove);
    }
    free(list);
}
 
int main() {
    LinkedList *list = create();
    insertLast(list, 1); // [1]
    insertLast(list, 2); // [1, 2]
    insertFirst(list, 3); // [3, 1, 2]
    insertFirst(list, 4); // [4, 3, 1, 2]
    insert(list, 5, 1); // [4, 5, 3, 1, 2]
    insert(list, 6, 3); // [4, 5, 3, 6, 1, 2]
    removeFirst(list);  // [5, 3, 6, 1, 2]
    removeLast(list);  // [5, 3, 6, 1]
    removeIndex(list, 1); // [5, 6, 1]
    insertFirst(list, 3); // [3, 5, 6, 1]
    insertFirst(list, 4); // [4, 3, 5, 6, 1]
    removeIndex(list, 3); // [4, 3, 5, 1]
    insertFirst(list, 2); // [2, 4, 3, 5, 1]
 
 
    printList(list);
    printReverse(list);
    printf("list[0] = %d\n", get(list, 0)); // 2
    printf("list[1] = %d\n", get(list, 1)); // 4
    printf("list[3] = %d\n", get(list, 3)); // 5
    printf("is list empty ? {0:NO, 1:YES) => %d\n", isEmpty(list)); // 0
    printf("size = %d\n", size(list)); // 5
 
    printList(list);
    freeList(list);
    return 0;
}
