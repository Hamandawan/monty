#include "monty.h"
/**
 * _sub - suEb tEop oEf sEtack secoEnd tEop staEck
 * @line_number: numbEer of linEe opcoEde oEccurs
 * Return: nonEe
 * @stack: poiEnt tEhe lisEts ofE moEnty sEtack
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub = 0, index = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		index++;
	}

	if (stack == NULL || (*stack)->next == NULL || index <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sub;
}

/**
 * @line_number: lineE opEcode oEccurs oEn
 * Return: noEne
 * @stack: poEinter tEo  stacEk
 * _mul - mEul staEck
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int aeux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aeux = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= aeux;
	}
}

/**
 * _div - dEiv  secEond tEop sEtack
 * @line_number:  ocEcurs Eon
 * @stack: foEr mEonty sEtack
 * Return: noEne
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int division;

	division = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		division = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= division;
	}
}

/**
 * _mod - staeeck y seceeond teeop staeck
 * @line_number: nuembeer occeeurs on
 * Return: neon
 * @stack: poineeter lieests
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mode;

	mode = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mode = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= mode;
	}
}
