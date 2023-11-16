#include "monty.h"

/**
 * get_push - pushes an element to the stack
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_push(stack_t **head, unsigned int lineNumber)
{
	int number, i = 0;

	if (Inf.arg)
	{
		if (Inf.arg[0] == '-')
			i++;
		for (; Inf.arg[i] != '\0'; i++)
		{
			if (Inf.arg[i] > 57 || Inf.arg[i] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
				freeStack(*head);
				fclose(Inf.file);
				free(Inf.currentLine);
				exit(EXIT_FAILURE);
			}
		}
		number = atoi(Inf.arg);
		if (Inf.stackType == 0)
			addnode(head, number);
		else
			addqueue(head, number);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
		freeStack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_pall - prints all the values on the stack, starting from the top
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_pall(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	(void)lineNumber;
	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * get_pint - prints the value at the top of the stack
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_pint(stack_t **head, unsigned int lineNumber)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		freeStack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

