#include <stdio.h>
#define MAX 32

// Structure definition for Stack
struct Stack {
    int data[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Push an element onto the stack
void push(struct Stack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = val;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = s->data[s->top];
    s->top--;
    return val;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int main() {
    struct Stack s;
    initStack(&s);
    
    int decimalNum;

    // Prompt user for input
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    // Handle the special case where input is 0
    if (decimalNum == 0) {
        printf("Binary equivalent: 0\n");
        return 0;
    }

    // Push remainders onto the stack
    int temp = decimalNum;
    while (temp > 0) {
        push(&s, temp % 2);
        temp = temp / 2;
    }

    // Pop and print elements from the stack to reverse the order
    printf("Binary equivalent: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");

    return 0;
}
