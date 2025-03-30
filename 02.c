#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList(int a[], int n) {
    Node *dummy = (Node*)malloc(sizeof(Node)); // 头节点
    dummy->next = NULL;
    Node *tail = dummy;
    
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = a[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    
    Node *realHead = dummy->next;
    free(dummy);
    return realHead;
}

Node* deleteMaxNode(Node* head) {
    if (!head) return NULL;
    
    Node dummy; // 临时头节点
    dummy.next = head;
    
    Node *maxPrev = &dummy; // 最大值节点的前驱节点
    Node *prev = &dummy;    // 当前节点的前驱节点
    Node *curr = head;      // 当前节点
    int maxVal = head->data; // 当前最大值
    
    while (curr) {
        if (curr->data > maxVal) {
            maxVal = curr->data;
            maxPrev = prev; // 更新最大值节点的前驱
        }
        prev = curr;       // 移动前驱节点
        curr = curr->next; // 移动当前节点
    }
    
    // 删除最大值节点
    Node *maxNode = maxPrev->next;
    maxPrev->next = maxNode->next;
    free(maxNode);
    
    return dummy.next;
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
    int a[] = {1, 3, 2, 9, 0, 4, 7, 6, 5, 8};
    int n = sizeof(a) / sizeof(a[0]);
    
    Node* head = createList(a, n);
    printf("原链表：");
    printList(head);
    
    head = deleteMaxNode(head);
    printf("删除后：");
    printList(head);
    
    freeList(head);
    return 0;
}