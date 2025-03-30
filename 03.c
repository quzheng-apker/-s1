#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

LinkedList createList(int a[], int n) {
    LinkedList list = {NULL, NULL};
    for (int i=0; i<n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = a[i];
        newNode->next = NULL;
        
        if (!list.head) list.head = list.tail = newNode;
        else list.tail = list.tail->next = newNode;
    }
    return list;
}

Node* deleteMaxNode(LinkedList *list) {
    if (!list->head) return NULL;
    
    Node *maxNode = list->head, *preMax = NULL;
    Node *curr = list->head->next, *prev = list->head;
    int maxVal = list->head->data;
    
    while (curr) {
        if (curr->data > maxVal) {
            maxVal = curr->data;
            maxNode = curr;
            preMax = prev;
        }
        prev = curr;
        curr = curr->next;
    }
    
    if (!preMax) {
        list->head = maxNode->next;
    } else {
        preMax->next = maxNode->next;
    }
    if (maxNode == list->tail) list->tail = preMax;
    free(maxNode);
    return list->head;
}

void printList(Node* head) { /* 同方式一 */ }
void freeList(Node* head) { /* 同方式一 */ }

int main() {
    int a[] = {1,3,2,9,0,4,7,6,5,8};
    int n = sizeof(a)/sizeof(a[0]);
    
    LinkedList list = createList(a, n);
    printf("原链表：");
    printList(list.head);
    
    deleteMaxNode(&list);
    printf("删除后：");
    printList(list.head);
    
    freeList(list.head);
    return 0;
}