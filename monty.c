#include "monty.h"
/**
 * main - main function
 * @argc: Argument count
 * @argv: Argument variable
 * Return: exit code(int)
*/
int main(int argc, char **argv)
{
char *word;
FILE *file;
size_t size = 0;
unsigned int line_number;
stack_t *stack = NULL;
instruction_t *instruction = NULL;

if (argc != 2)
{
fprintf(stderr, "Usage: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (getline(&word, &size, file) != -1)
{
line_number++;
instruction = read_line(word);
if (!(instruction->opcode) || instruction->opcode[0] == '#')
{
free(instruction);
if (word)
free(word);
word = NULL;
continue;
}
if (instruction->f)
instruction->f(&stack, line_number);
else
{
fprintf(stdout, "L%d: unknown instruction %s\n", line_number, instruction->opcode);
if (word)
free(word);
if (stack)
free(stack);
free(instruction);
fclose(file);
exit(EXIT_FAILURE);
}
if (word)
free(word);
word = NULL;
free(instruction);
}
if (word)
free(word);
free(stack);
fclose(file);
return (0);
}
