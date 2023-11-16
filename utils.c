#include "monty.h"

/**
 * addnode - add node
 * @head: pointer to head of Stack
 * @n: value
*/

void addnode(stack_t **head, int n)
{

	stack_t *new;
	stack_t *iter;

	iter = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("malloc error\n");
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	if (iter)
		iter->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

/**
* free_stack - free stack list
* @head: pointer to head of Stac
*/

void free_stack(stack_t *head)
{
	stack_t *iter;

	iter = head;
	while (head)
	{
		iter = head->next;
		free(head);
		head = iter;
	}
}

/**
 * addqueue - add node to the tail stack
 * @n: value
 * @head: pointer to head of Stack
*/

void addqueue(stack_t **head, int n)
{
	stack_t *new, *iter;

	iter = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("malloc error\n");
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (iter)
	{
		while (iter->next)
			iter = iter->next;
	}
	if (!iter)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		iter->next = new;
		new->prev = iter;
	}
}
