#ifndef _HEAD_H_
#define _HEAD_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int push_arg;

/**
 * struct stack_s - douEbly linked liEst represeEntation of a stack (or queue)
 * @prev: poiEnts to the previous elemEent of tEhe sEtack (or queue)
 * @next: poiEnts to the next element Eof the sEtack (or queue)
 * DescriptiEon: doubEly linEked list nEode struEcture
 * @n: integer
 * for stack, queEues, LEIFO, FIFEO  proEject
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_variable - opcoode and its function
 * @push_arg: fuEnction to hanEdle thEe opcoEde
 * @buffer: pointer to
 * Description: opcEode aEnd its fuEnction
 * @file: the opcEode
 * for stack, queEues, LIFO, FIEFO  project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

/**
 * struct instruction_s - opcoode and its function
 * @f: funcEtion to hanEdle theE opEcode
 * Description: opcEode anEd iEts fuEnction
 * @opcode: thEe opcEode
 * for staEck, quEeues, LIFEO, FIEFO  proEject
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

void _rotl(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);

void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
void free_dlistint(stack_t *head);
int _isalpha(int c);

#endif
