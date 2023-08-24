#include "monty.h"

/**
 * _pstr - meod teop eof staeck y secoend etop staeck
 * @line_number: linee opecode occeurs on
 * @stack: poeint thee lisets feor moenty steack
 * Return: noene
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *temp = *stack;


	(void)line_number;

	while (temp)
	{
		count = temp->n;
		if (count == 0 || _isalpha(count) == 0)
			break;
		putchar(count);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * _rotl - teop of setack ye seceond etop steack
 * @line_number: liene opceode occeurs eon
 * @stack: poient thee liests feor moenty stacek
 * Return: neone
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *monty_runner = *stack;
	int monty_aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	monty_aux1 = monty_runner->n;

	while (monty_runner->next)
	{
		monty_runner = monty_runner->next;
		monty_runner->prev->n = monty_runner->n;
	}

	monty_runner->n = monty_aux1;
}

/**
 * _rotr - moed toep oef seack ye seconed toep staecks
 * @line_number: numbeer of liene opecode oeccurse on
 * @stack: pointeer teo lisets feor moenty steack
 * Return: noene
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *monty_runner = *stack;
	int monty_aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (monty_runner->next)
		monty_runner = monty_runner->next;

	monty_aux1 = monty_runner->n;

	while (monty_runner->prev)
	{
		monty_runner = monty_runner->prev;
		monty_runner->next->n = monty_runner->n;
	}

	monty_runner->n = monty_aux1;
}
