#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    char ch;
    
    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');  // convert char digit to int
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[SIZE];
    
    printf("Enter postfix expression (single digit numbers only): ");
    gets(postfix);

    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}

