#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 递归查找最大值前驱
void findMax(Node *current, Node *prev, Node **maxNode, Node **preMaxNode, int *maxVal) {
    if (!current) return;
    if (current->data > *maxVal) {
        *maxVal = current->data;
        *maxNode = current;
        *preMaxNode = prev;
    }
    findMax(current->next, current, maxNode, preMaxNode, maxVal);
}

Node* deleteMaxNode(Node* head) {
    if (!head) return NULL;
    
    Node *maxNode = head, *preMaxNode = NULL;
    int maxVal = head->data;
    findMax(head->next, head, &maxNode, &preMaxNode, &maxVal);
    
    if (maxNode == head) {
        head = head->next;
    } else {
        preMaxNode->next = maxNode->next;
    }
    free(maxNode);
    return head;
}

Node* createList(int a[], int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = a[i];
        newNode->next = NULL;
        if (!head) head = tail = newNode;
        else tail = tail->next = newNode;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    int a[] = {1,3,2,9,0,4,7,6,5,8};
    int n = sizeof(a)/sizeof(a[0]);
    
    Node* head = createList(a, n);
    printf("原链表：");
    printList(head);
    
    head = deleteMaxNode(head);
    printf("删除后：");
    printList(head);
    
    freeList(head);
    return 0;
}