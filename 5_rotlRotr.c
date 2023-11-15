#include "monty.h"

/**
  *get_rotl- rotates the stack to the top
  *@head: pointer to head of Stack
  *@lineNumber: number of current line
 */

void get_rotl(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp, *newHead;

	(void)lineNumber;
	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	newHead = (*head)->next;
	newHead->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = newHead;
}

/**
  *get_rotr- rotates the stack to the bottom
  *@head: pointer to head of Stack
  *@lineNumber: number of current line
  *Return: no return
 */

void get_rotr(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;

	(void)lineNumber;
	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}

