#include "monty.h"

static instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}
};

/**
 * free_memory - free stack memory
 * @temp: current stack
 * Return: void
*/
void free_memory(stack_t *temp)
{
	while (temp != NULL)
	{
		stack_t *current = temp;

		temp = current->next;
		free(current);
	}
}

/**
 * execute_instructions - Execute monty bytecodes
 * @file: File pointer
 * Return: void
*/
void execute_instructions(FILE *file)
{
	char buffer[1024];
	int line_number = 1, i, flag = 0;
	stack_t *temp;
	stack_t *stack = NULL;

	while (fgets(buffer, sizeof(buffer), file))
	{
		char *opcode;

		opcode = strtok(buffer, " \n\t");
		/*printf("opcode is %s\n", opcode);*/
		if (opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			fprintf(stderr, "L%u: unknown instruction\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	temp = stack;
	free_memory(temp);
}
