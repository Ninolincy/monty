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
int temp;

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
