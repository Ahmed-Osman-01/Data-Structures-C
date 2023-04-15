#include<stdio.h>
#include "../Headers/stack.h"

int main()
{
    stack stack1;
    init_fixed_stack(&stack1);
    int x;
    push_fixed_stack(&stack1, 3);
    pop_fixed_stack(&stack1, &x);
    printf("%d\n", x);

    return 0;
}
