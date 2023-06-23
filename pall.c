#include "monty.h"

/**
 * pall - prints all the values on stack starting from top
 * @stack: The stack to print
 * @line_number: line number
 *
 * Return: void
*/

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
stack_t *temp;

temp = *stack;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
