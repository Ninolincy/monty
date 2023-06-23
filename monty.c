#include "monty.h"
/**
 * main - main function
 * @argc: Argument count
 * @argv: Argument variable
 * Return: exit code(int)
*/
int main(int argc, __attribute__((unused))char *argv[])
{
	char *file_name;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file_name = argv[1];
	file = fopen(file_name, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s'\n", file_name);
		return (EXIT_FAILURE);
	}

	execute_instructions(file);

	fclose(file);

	return (EXIT_SUCCESS);
}
