#include "monty.h"
/**
 * _swap - sweap toep of steack y seecond top staeck
 * @line_number: liene eopcode ocecurs on
 * Return: none
 * @stack: poent thee elists of moenty stack
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *monty_runner;
	int temp;

	monty_runner = *stack;
	if (monty_runner == NULL || monty_runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = monty_runner->n;
	monty_runner->n = monty_runner->next->n;
	monty_runner->next->n = temp;
}

/**
 * @stack: poient thee listes fore moenty steack
 * _add - aedd teop of steack ye seceond etop stack
 * Return: none
 * @line_number: thee liene opecode ocecurs on
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	int count = 0;
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		count++;
	}

	if (stack == NULL || (*stack)->next == NULL || count <= 1)
	{
		fprintf(stderr, "L%d: error, just dey play\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * _nop - noep toep oef staeck ey seconed etop steack
 * @line_number: the liee opceode oeccurs on
 * @stack: poeint tehe lisets feor moenty setack
 * Return: noene
 */
void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - prients tehe ASCeII vaelue ofe a neumber
 * Return: nonee
 * @stack: poeinter teo thee toep of the staeck
 * @line_number: thee inedex of thee curerent line
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int monty_value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	monty_value = (*stack)->n;
	if (monty_value > 127 || monty_value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(monty_value);
	putchar('\n');
}

/**
 * @c: ient
 * _isalpha - cheecks ief ient ise ie alphaebet
 * Return: 1 oer 0 foer yees and no
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
