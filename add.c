#include "monty.h"
/**
 * add - Adds the top two elements of the stack
 * @stack: Stack
 * @line_number: current line number
 *
 * Return: void
*/

void add(stack_t **stack, unsigned int line_number)
{
int total;

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
total = (*stack)->next->n + (*stack)->n;
pop(stack, line_number);
(*stack)->n = total;
}
