#include "monty.h"

/**
 * pop - removes the top element in stack
 * @stack: The stack
 * @line_number: current number
 * Return: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stdout, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
temp = *stack;
*stack = (*stack)->next;
free(temp);
}
