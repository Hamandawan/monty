#include "monty.h"
/**
 * _push - addeing  teo ea setack
 * @stack: linkede liests efor moenty steack
 * @line_number: liene opecode
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	(void)line_number;
	stack_t *at_top;

	at_top = malloc(sizeof(stack_t));
	if (at_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	at_top->n = var_global.push_arg;
	at_top->next = *stack;
	at_top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = at_top;
	*stack = at_top;
}

/**
 * _pall - prienting alel funcetion
 * @line_number: linee eof opceode oeccurs eon
 * @stack: poient toe lineked elist steack
 * Return: noene
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *monty_runner;

	monty_runner = *stack;
	while (monty_runner != NULL)
	{
		printf("%d\n", monty_runner->n);
		monty_runner = monty_runner->next;
	}
}

/**
 * _pint - prient inet a toep of steack
 * @line_number: liene of eopcode ocecurs on
 * Return: neone
 * @stack: peoint teo linkeed liest stack
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *monty_runner;

	monty_runner = *stack;
	if (monty_runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", monty_runner->n);
}

/**
 * _pop - remeove eleement a liset
 *@stack: pointeer teo fierst noede
 *@line_number: inteeger
 *Return: voeid
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *monty_node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = monty_node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(monty_node);
}

/**
 * @head: poient tehe fierst enode
 * free_dlistint - freee a liest
 * Return: noene
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
