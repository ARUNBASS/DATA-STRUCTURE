#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[k++] = pop();
            if (!isEmpty()) pop(); // Remove '('
        }
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (!isEmpty())
        postfix[k++] = pop();
    postfix[k] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

