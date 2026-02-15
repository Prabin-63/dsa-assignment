/*Write a program to convert an infix mathematical expression to postfix and evaluate it.*/

#include <stdio.h>
#include <ctype.h>
#define MAX 50

char stack[MAX];
int top = -1;

// Stack operations 
//Push
void push(char x) {
    stack[++top] = x;
}
//Pop
char pop() {
    return stack[top--];
}

// Operator precedence
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char x;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                postfix[k++] = x;
        }
        else {
            while (priority(stack[top]) >= priority(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Postfix Evaluation
int evaluatePostfix(char postfix[]) {
    int stack2[MAX];
    int top2 = -1;
    int i, a, b;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            stack2[++top2] = postfix[i] - '0';
        } else {
            b = stack2[top2--];
            a = stack2[top2--];

            switch (postfix[i]) {
                case '+': stack2[++top2] = a + b; break;
                case '-': stack2[++top2] = a - b; break;
                case '*': stack2[++top2] = a * b; break;
                case '/': stack2[++top2] = a / b; break;
            }
        }
    }
    return stack2[top2];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
