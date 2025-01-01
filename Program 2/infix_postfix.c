#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For isdigit() function

// Define a maximum size for the stack
#define MAX 100

// Stack structure to hold operators
char stack[MAX];
int top = -1;

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// Function to check if the character is an operand (alphanumeric)
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

// Function to push an element onto the stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        return -1;  // Return -1 if stack is empty
    }
    return stack[top--];
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char currentChar;

    // Traverse through the infix expression
    while ((currentChar = infix[i++]) != '\0') {
        // If the current character is an operand, add it directly to postfix
        if (isOperand(currentChar)) {
            postfix[j++] = currentChar;
        }
        // If the current character is an opening parenthesis, push it to stack
        else if (currentChar == '(') {
            push(currentChar);
        }
        // If the current character is a closing parenthesis, pop until opening parenthesis is found
        else if (currentChar == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop the opening parenthesis '('
        }
        // If the current character is an operator
        else if (isOperator(currentChar)) {
            while (top != -1 && precedence(stack[top]) >= precedence(currentChar)) {
                postfix[j++] = pop();
            }
            push(currentChar);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    // Input the infix expression
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    // Convert the infix expression to postfix
    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
