#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*func)(stack_t **stack, unsigned int  lineNumber);
} instruction_t;

/**
 * struct InMfilee - args and file and proprietes
 * @arg: stack or pile
 * @file: file
 * @currentLine: number of current line
 * @stackType: type of stack
 * Description: set proprietes and made it puplic throug project
 */

typedef struct InfoMfilee
{
	char *arg;
	FILE *file;
	char *currentLine;
	int stackType;
}  InfoMfile;

extern InfoMfile Inf;
int runCommand(stack_t **head, char *currentLine, unsigned int lineNumber, FILE *file);
void get_push(stack_t **head, unsigned int lineNumber);
void get_pall(stack_t **head, unsigned int lineNumber);
void get_pint(stack_t **head, unsigned int lineNumber);
void get_pop(stack_t **head, unsigned int lineNumber);
void get_swap(stack_t **head, unsigned int lineNumber);
void get_add(stack_t **head, unsigned int lineNumber);
void get_nop(stack_t **head, unsigned int lineNumber);
void get_sub(stack_t **head, unsigned int lineNumber);
void get_div(stack_t **head, unsigned int lineNumber);
void get_mul(stack_t **head, unsigned int lineNumber);
void get_mod(stack_t **head, unsigned int lineNumber);
void get_pchar(stack_t **head, unsigned int lineNumber);
void get_pstr(stack_t **head, unsigned int lineNumber);
void get_rotl(stack_t **head, unsigned int lineNumber);
void get_rotr(stack_t **head, __attribute__((unused)) unsigned int lineNumber);
void get_queue(stack_t **head, unsigned int lineNumber);
void get_stack(stack_t **head, unsigned int lineNumber);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void free_stack(stack_t *head);

#endif

