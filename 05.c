#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node** findMaxPointer(Node **head) {
    Node **max = head;
    int maxVal = (*max)->data;
    
    for (Node **curr = &(*head)->next; *curr; curr = &(*curr)->next) {
        if ((*curr)->data > maxVal) {
            maxVal = (*curr)->data;
            max = curr;
        }
    }
    return max;
}

Node* deleteMaxNode(Node* head) {
    if (!head) return NULL;
    
    Node **maxPtr = findMaxPointer(&head);
    Node *toDelete = *maxPtr;
    *maxPtr = toDelete->next;
    free(toDelete);
    return head;
}

Node* createList(int a[], int n) { /* 同方式一 */ }
void printList(Node* head) { /* 同方式一 */ }
void freeList(Node* head) { /* 同方式一 */ }

int main() { /* 同方式一 */ }