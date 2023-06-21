#include "monty.h"

/**
 * stack_add - Adds the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void stack_add(stack_t **stack_pointer, unsigned int num)
{
	int add;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	/* Calculate the sum of the top two elements */
	add = (*stack_pointer)->next->n + (*stack_pointer)->n;

	/* Remove the top element */
	pop(stack_pointer, num);

	/* Update the new top element with the sum */
	(*stack_pointer)->n = add;
}


/**
 * stack_div - Divides the top two elements of the stack.
 * @stack_pointer: Pointer to the stack
 * @num: Current line number
 *
 * Return: void
 */
void stack_div(stack_t **stack_pointer, unsigned int num)
{
	int division;

	if (*stack_pointer == NULL || (*stack_pointer)->next == NULL)
	{
		fprintf(stdout, "L%d: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	if ((*stack_pointer)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}

	/* Calculate the division of the top two elements */
	division = (*stack_pointer)->next->n / (*stack_pointer)->n;

	/* Remove the top element */
	pop(stack_pointer, num);

	/* Update the new top element with the division result */
	(*stack_pointer)->n = division;
}


/**
 * is_int - checks if a string is valid for atoi
 * @str: the string
 *
 * Return: 1 for true, 0 for false
 */
int is_int(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (*str == '-')
		i++;
	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * multiply - multiplies the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	int mul;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = mul;
}

/**
 * sub - subtracts the top two elements of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
}
