#include<stdio.h>
#include "../Headers/stack.h"


void init_fixed_stack(stack *stack_p)
{
    if(stack_p -> initialized == 'y')
    {
        printf("This stack is already initialized\n");
        return;
    }
    stack_p -> top = 0;
    stack_p -> initialized = 'y';
}

char fixed_stack_is_empty(stack *stack_p)
{
    return stack_p -> top == 0;
}

char fixed_stack_is_full(stack *stack_p)
{
    return stack_p -> top == stack_size;
}

void push_fixed_stack(stack* stack_p, int val)
{
    if(fixed_stack_is_full(stack_p))
    {
        printf("This stack is full! can't push any more elements\n");
        return;
    }

    stack_p -> arr[stack_p -> top++] = val;
}

void pop_fixed_stack(stack *stack_p, int *val)
{
    if(fixed_stack_is_empty(stack_p)){
        printf("This stack is empty!! can't pop any more elements\n");
        return;
    }

    *val = stack_p -> arr[--stack_p -> top];
}

void peek_fixed_stack(stack *stack_p, int *val)
{
  
    if(fixed_stack_is_empty(stack_p)){
        printf("This stack is empty!! no elements to peek!\n");
        return;
    }

    *val = stack_p -> arr[stack_p -> top];
}