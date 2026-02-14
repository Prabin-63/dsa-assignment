#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAfter(struct Node* p, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = p->next;
    newNode->prev = p;

    if (p->next != NULL)
        p->next->prev = newNode;

    p->next = newNode;
}

void deleteNode(struct Node** head, struct Node* del) {
    if (*head == NULL || del == NULL)
        return;

    if (*head == del)
        *head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head, *second, *third;

    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    head->data = 2;
    head->prev = NULL;
    head->next = second;

    second->data = 3;
    second->prev = head;
    second->next = third;

    third->data = 4;
    third->prev = second;
    third->next = NULL;

    display(head);

    insertAfter(second, 25);
    display(head);

    deleteNode(&head, second);
    display(head);

    return 0;
}
