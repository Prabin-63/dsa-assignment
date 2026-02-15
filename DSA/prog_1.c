/* 
Write a program to check if any given mathematical expression has a balanced number of
parentheses or not?
Run the program by testing following expression-
⇒a + (b − c) ∗ (d
⇒m + [a − b ∗ (c + d ∗ {m)]
⇒a + (b − c)
Hint: Use stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// To check if stack is full 
int isFull() {
    return top == MAX - 1;
}

// To check if stack is empty
int isEmpty() {
    return top == -1;
}

//To push an element to stack
void push(char ch) {
    if (!isFull()) {
        stack[++top] = ch;
    }
}

//To pop an element to stack
char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return '\0';
}

//The function which check if the 
int checkBalance(char expr[]) {
    top = -1;
    for (int i = 0; i < strlen(expr); i++) {

        // To check opening brackets
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        }

        // To check closing brackets
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {

            if (top == -1)
                return 0;   // Stack empty

            char ch = pop();

            if ((expr[i] == ')' && ch != '(') ||
                (expr[i] == '}' && ch != '{') ||
                (expr[i] == ']' && ch != '['))
                return 0;
        }
    }

    // If stack is empty i.e. it is balanced
    return (top == -1);
}


int main() {
    char expr1[] = "a + (b − c) ∗ (d";
    char expr2[] = "m + [a − b ∗ (c + d ∗ {m)]";
    char expr3[] = "a + (b − c)";

    printf("%s -> %s\n", expr1, checkBalance(expr1) ? "Balanced" : "Not Balanced"); //Using ternary operator to check
    printf("%s -> %s\n", expr2, checkBalance(expr2) ? "Balanced" : "Not Balanced");
    printf("%s -> %s\n", expr3, checkBalance(expr3) ? "Balanced" : "Not Balanced");

    return 0;
}
