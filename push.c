#include "monty.h"

/**
 * push - push elements into stack
 * @stack: The stack to push to
 * @line_number: the line number
 *
 * Return: void
*/

void push(__attribute__((unused))stack_t **stack, unsigned int line_number)
{
stack_t *new;
char *push_arg;
int new_value;

push_arg = strtok(NULL, "\n\t");

if (!is_int(push_arg))
{
fprintf(stdout, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
new_value = atoi(push_arg);
new = malloc(sizeof(stack_t));
if (new == NULL)
{
fprintf(stdout, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new->n = new_value;
new->prev = NULL;
new->next = NULL;
/**Check if stack is empty*/
}