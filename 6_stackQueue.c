#include "monty.h"

/**
 * get_stack - sets the format of the data to a stack (LIFO)
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_stack(stack_t **head, unsigned int lineNumber)
{
	(void)head;
	(void)lineNumber;
	Inf.stackType = 0;
}

/**
 * get_queue - ets the format of the data to a queue (FIFO).
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_queue(stack_t **head, unsigned int lineNumber)
{
	(void)head;
	(void)lineNumber;
	Inf.stackType = 1;
}
