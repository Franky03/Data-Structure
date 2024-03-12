#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    double *items;
    int top;
    int size;
} Stack;

Stack* createStack(int capacity){
    Stack *newStack = (Stack*) malloc(sizeof(Stack));
    newStack->size = capacity;
    newStack->top = -1;
    newStack->items = (double*) malloc(sizeof(double) * capacity);
    return newStack;
}

int isFull(Stack *stack){
    return stack->top == stack->size - 1;
}

int isEmpty(Stack *stack){
    return stack->top == -1;
}

void push(Stack *stack, double item){
    if(isFull(stack)){
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

double pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--]; // return and decrement top 
}

double evalueateRPN(char *expression){
    Stack *stack = createStack(100);
    while(*expression){
        if(isdigit(*expression) || (*expression == '.' && isdigit(*(expression + 1)))){
            push(stack, strtod(expression, &expression));
        } else if(*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/'){
            double a = pop(stack);
            double b = pop(stack);

            switch(*expression){
                case '+':
                    push(stack, b + a);
                    break;
                case '-':
                    push(stack, b - a);
                    break;
                case '*':
                    push(stack, b * a);
                    break;
                case '/':
                    if(a == 0){
                        printf("Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(stack, b / a);
                    break;
            }
    }
    expression++;
    }

    double result = pop(stack);
    free(stack->items);
    free(stack);
    return result;
}

int main(){
    char expression[] = "4 2 + 6 *";
    printf("Result: %.2f\n", evalueateRPN(expression));
    return 0;
}