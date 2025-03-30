#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node *prev;
    Node *current;
} Iterator;

Iterator next(Iterator it) {
    return (Iterator){it.current, it.current->next};
}

Node* createList(int a[], int n) { /* 同方式一 */ }

Node* deleteMaxNode(Node* head) {
    if (!head) return NULL;
    
    Iterator maxIt = {NULL, head};
    Iterator currIt = {NULL, head};
    int maxVal = head->data;
    
    while (currIt.current) {
        if (currIt.current->data > maxVal) {
            maxVal = currIt.current->data;
            maxIt = currIt;
        }
        currIt = next(currIt);
    }
    
    if (!maxIt.prev) {
        head = head->next;
    } else {
        maxIt.prev->current->next = maxIt.current->next;
    }
    free(maxIt.current);
    return head;
}

void printList(Node* head) { /* 同方式一 */ }
void freeList(Node* head) { /* 同方式一 */ }

int main() { /* 同方式一 */ }