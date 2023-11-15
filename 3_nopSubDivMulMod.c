#include "monty.h"

/**
  *get_nop- doesn’t do anything.
  *@head: pointer to head of Stack
  *@lineNumber: number of current line
 */

void get_nop(stack_t **head, unsigned int lineNumber)
{
	(void) lineNumber;
	(void) head;
}

/**
  *get_sub- subtracts the top element of the stack from the second
  *@head: pointer to head of Stack
  *@lineNumber: number of current line
 */

void get_sub(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	int sub;

	if (!(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->n - temp->next->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}

/**
 * get_div - divides the second top element of the stack by the top element
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_div(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	int div;

	if (!(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	div = temp->next->n / temp->n;
	temp->next->n = div;
	*head = temp->next;
	free(temp);
}

/**
 * get_mul - multiplies the second top element of the stack with the top
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_mul(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	int mul;

  if (!(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	mul = temp->next->n * temp->n;
	temp->next->n = mul;
	*head = temp->next;
	free(temp);
}

/**
 * get_mod -  the rest of the div of the second top element by the top element
 * @head: pointer to head of Stack
 * @lineNumber: number of current line
*/

void get_mod(stack_t **head, unsigned int lineNumber)
{
	stack_t *temp;
	int mod;

  if (!(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		free_stack(*head);
		fclose(Inf.file);
		free(Inf.currentLine);
		exit(EXIT_FAILURE);
	}
	mod = temp->next->n % temp->n;
	temp->next->n = mod;
	*head = temp->next;
	free(temp);
}

