#include "monty.h"
/**
 * get_pchar - prints the char at the top of the stack
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_pchar(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	temp = *head;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
 * get_pstr - prints the string starting at the top of the stack
 * followed by a new
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
 * Return: no return
*/

void get_pstr(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	(void)lineNumber;

	temp = *head;
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
