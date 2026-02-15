# Infix to Postfix Conversion and Evaluation Using Stack in C

## GIVEN QUESTION:
**Write a program to convert an infix mathematical expression to postfix and evaluate it.**

This program converts a given infix expression into postfix notation and evaluates the postfix expression using stack implementation in C.

## Code Description

- A character array `stack[MAX]` is used to store operators and parentheses.
- An integer variable `top` is used to track the top of the stack.
- Operator precedence is handled using a priority function.
- Another integer stack is used to evaluate the postfix expression.
- The stack follows the LIFO (Last In First Out) principle.

## Functions Used

### push(char x)
- Pushes an operator or parenthesis onto the stack.

### pop()
- Removes and returns the top element from the stack.

### priority(char x)
- Returns the precedence of operators:
  - `(` = lowest
  - `+ , -` = medium
  - `* , /` = highest

### infixToPostfix(char infix[], char postfix[])
- Converts infix expression to postfix:
  - Operands are directly added to postfix
  - Operators are pushed or popped based on precedence
  - Parentheses are handled correctly

### evaluatePostfix(char postfix[])
- Evaluates the postfix expression:
  - Operands are pushed onto an integer stack
  - Operators pop two operands, perform operation, and push result
  - Final value is the result

## Sample Output
![O2](output/O2.png "Program 2 output")