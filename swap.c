#include "monty.h"
/**
 * swap - swaps top two elements of the stack
 * @stack: The stack
 * @line_number: Line number content
 *
 * Return: void
*/

void swap(stack_t **stack, unsigned int line_number)
{
int x;

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stdout, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
x = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = x;
}
