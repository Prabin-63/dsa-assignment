# Balanced Parentheses Using Stack in c
## GIVEN QUESTION:
** Write a program to check if any given mathematical expression has a balanced number of parentheses or not?
Run the program by testing following expression-
⇒a + (b − c) ∗ (d
⇒m + [a − b ∗ (c + d ∗ {m)]
⇒a + (b − c) **

### This program checks whether a given mathematical expression has balanced parentheses using a stack implemented with an array in C.

** Code Description **

- A character array stack[MAX] is used to store opening brackets.
- An integer variable top keeps track of the top of the stack.
- The stack follows the LIFO (Last In First Out) principle.

### Functions Used

** isFull() **
- Checks whether the stack is full.

** isEmpty() **
- Checks whether the stack is empty.

** push(char ch) **
- Inserts an opening bracket ((, {, [) into the stack.

** pop() **
- Removes and returns the top element from the stack.

** checkBalance(char expr[]) **
- Scans the expression character by character:
    - Pushes opening brackets onto the stack
    - Pops and matches brackets when a closing bracket is found
    - Returns balanced if all brackets match and the stack is empty

### Sample Output
<p align="center">
  <img src="O1.png" alt="Alt text" width="500">
</p>