#include <stdio.h>
#include <stdlib.h>

// I define a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// I create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// I append a node to the end of a linked list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// I print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// I merge two sorted linked lists into one sorted linked list
Node* merge(Node* list1, Node* list2) {
    // I use a dummy node to simplify the merge logic
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    // I merge the two lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // I attach the remaining nodes from either list
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // I create the first sorted linked list
    appendNode(&list1, 3);
    appendNode(&list1, 4);
    appendNode(&list1, 5);

    // I create the second sorted linked list
    appendNode(&list2, 13);
    appendNode(&list2, 14);
    appendNode(&list2, 15);

    // I print the original linked lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // I merge the two sorted linked lists
    Node* mergedList = merge(list1, list2);

    // I print the merged linked list
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}