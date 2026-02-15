# Reverse Traversal of Linked List Using Recursion in C

## GIVEN QUESTION:
**Write and implement the reverse traversal algorithm in the linked list. Write main() to demonstrate the use of the function.**

This program demonstrates how to perform reverse traversal of a singly linked list using recursion in C. The linked list is created manually in the main() function, and a recursive function is used to print the elements in reverse order.

## Code Description

- A structure ListNode is defined to represent each node of the linked list.
- Each node contains:
  - An integer value
  - A pointer next that points to the next node
- Three nodes are dynamically allocated using malloc().
- The nodes are linked sequentially.
- Reverse traversal is achieved using recursion.
- The program prints the linked list elements in reverse order without modifying the actual list.

## Structure Used
```c
struct ListNode {
    int value;
    struct ListNode* next;
};
```

- `value` → Stores the data of the node.
- `next` → Stores the address of the next node.

## Function Used

### printReverse(struct ListNode* node)
- This function prints the linked list in reverse order using recursion.
- Base condition: If `node == NULL`, return.
- Recursive step:
  - First calls itself with `node->next`
  - Then prints `node->value`
- Because of recursion, printing happens while returning from recursive calls (LIFO concept).

## How Recursion Works Here

If the list is:
```
3 → 5 → 6 → NULL
```

Function calls happen like this:
```
printReverse(3)
    → printReverse(5)
        → printReverse(6)
            → printReverse(NULL)
```

Printing happens while returning:
```
6 5 3
```

## main() Function Explanation

- Three nodes are created:
  - First node → 3
  - Second node → 5
  - Third node → 6
- Nodes are connected manually.
- `printReverse(first);` is called to display reverse traversal.

## Key Concept Used

- Recursion
- Linked List
- Dynamic Memory Allocation (`malloc`)
- LIFO behavior of function call stack

## Sample Output

![O3](../Output/O3.png "Program 3 output")