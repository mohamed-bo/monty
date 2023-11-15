#include "monty.h"

/**
 * get_pop - removes the top element of the stack.
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_pop(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}

/**
 * get_swap - swaps the top two elements of the stack.
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_swap(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	int headNumber, size = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	headNumber = temp->n;
	temp->n = temp->next->n;
	temp->next->n = headNumber;
}

/**
 * get_add - adds the top two elements of the stack.
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_add(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	int sum;

	if (!(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*head = temp->next;
	free(temp);
}

