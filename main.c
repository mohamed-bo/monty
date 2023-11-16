#include "monty.h"

InfoMfile Inf = {NULL, NULL, NULL, 0};

/**
* runCommand - run specefic function
* @head: pointer to head of Stack
* @lineNumber: number of current line
* @file: m file
* @currentLine: current line
*/

int runCommand(stack_t **head, char *currentLine,
		unsigned int lineNumber, FILE *file)
{
	instruction_t function_table[] = {
				{"push", get_push}, {"pall", get_pall}, {"pint", get_pint},
				{"pop", get_pop}, {"swap", get_swap}, {"add", get_add},
				{"nop", get_nop}, {"sub", get_sub}, {"div", get_div},
				{"mul", get_mul}, {"mod", get_mod},
				{"pchar", get_pchar}, {"pstr", get_pstr},
				{"rotl", get_rotl}, {"rotr", get_rotr},
				{"head", get_stack}, {"queue", get_queue},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *cmdName;

	cmdName = strtok(currentLine, " \n\t");
	if (cmdName && cmdName[0] == '#')
		return (0);
	Inf.arg = strtok(NULL, " \n\t");
	while (function_table[i].opcode && cmdName)
	{
		if (strcmp(cmdName, function_table[i].opcode) == 0)
		{
			function_table[i].f(head, lineNumber);
			return (0);
		}
		i++;
	}
	if (cmdName && function_table[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, cmdName);
		fclose(file);
		free_stack(*head);
		free(currentLine);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
* main - main function
* @argc: size of argv
* @argv: argv
* Return: 0
*/

int main(int argc, char *argv[])
{
	FILE *file;
	char *currentLine;
	stack_t *head = NULL;
	ssize_t isValidLine = 1;
	size_t size = 0;
	unsigned int lineNumber = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	Inf.file = file;
	while (isValidLine > 0)
	{
		currentLine = NULL;
		isValidLine = getline(&currentLine, &size, file);
		Inf.currentLine = currentLine;
		lineNumber++;
		if (isValidLine > 0)
		{
			runCommand(&head, currentLine, lineNumber, file);
		}
		free(currentLine);
	}
	free_stack(head);
	fclose(file);
	return (0);
}

