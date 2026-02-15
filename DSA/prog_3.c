/*Write and Implement the reverse traversal algorithm in the linked list. Write main() to
demonstrate the use of the function.*/

#include <stdio.h>
#include <stdlib.h>

//defining structure for linked list
struct ListNode {
    int value;
    struct ListNode* next;
};

//Using recursion for reverse transversal
void printReverse(struct ListNode* node) {
    if (node == NULL)
        return;

    printReverse(node->next);  //Yo chai recursion function
    printf("%d ", node->value);
}

int main() {
    struct ListNode *first, *second, *third;

    first = malloc(sizeof(struct ListNode));
    second = malloc(sizeof(struct ListNode));
    third = malloc(sizeof(struct ListNode));

    first->value = 3;
    first->next = second;

    second->value = 5;
    second->next = third;

    third->value = 6;
    third->next = NULL;

    printf("Reverse Traversal: ");
    printReverse(first);

    return 0;
}
