#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED 
#define stack_size 10


typedef struct stack{
    char initialized;
    int top;
    int arr[stack_size];
}stack;


void init_fixed_stack(stack*);
char fixed_stack_is_empty(stack*);
char fixed_stack_is_full(stack*);
void push_fixed_stack(stack*, int);
void pop_fixed_stack(stack *, int *);
void peek_fixed_stack(stack *, int *);


#endif