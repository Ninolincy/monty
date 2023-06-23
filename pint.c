#include "monty.h"

/**
 * pint - prints the value at the top of stack
 * @stack: The stack to print top
 * @line_number: Line number
 *
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (stack == NULL)
{
fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
