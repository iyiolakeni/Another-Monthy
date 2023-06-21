#include "monty.h"

/**
 * parse_line - Parses a line and returns the corresponding instruction.
 * @line: The line to parse
 *
 * Return: A pointer to the proper instruction
 */
instruction_t *parse_line(char *line)
{
	char *opcode;
	instruction_t *instruction;

	opcode = get_opcode(line);
	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = opcode;
	instruction->f = NULL;

	/* Set the function pointer based on the opcode */

	if (instruction->opcode)
	{
		if (strcmp(instruction->opcode, "push") == 0)
			instruction->f = push;
		else if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = pall;
		else if (strcmp(instruction->opcode, "pint") == 0)
			instruction->f = pint;
		else if (strcmp(instruction->opcode, "pop") == 0)
			instruction->f = pop;
		else if (strcmp(instruction->opcode, "swap") == 0)
			instruction->f = swap;
		else if (strcmp(instruction->opcode, "add") == 0)
			instruction->f = add;
		else if (strcmp(instruction->opcode, "nop") == 0)
			instruction->f = nop;
		else if (strcmp(instruction->opcode, "sub") == 0)
			instruction->f = sub;
		else if (strcmp(instruction->opcode, "div") == 0)
			instruction->f = divide;
		else if (strcmp(instruction->opcode, "mul") == 0)
			instruction->f = multiply;
		else if (strcmp(instruction->opcode, "mod") == 0)
			instruction->f = moddy;
		else if (strcmp(instruction->opcode, "pchar") == 0)
			instruction->f = pchar;
		else if (strcmp(instruction->opcode, "pstr") == 0)
			instruction->f = pstr;
		else if (strcmp(instruction->opcode, "rotl") == 0)
			instruction->f = rotl;
		else if (strcmp(instruction->opcode, "rotr") == 0)
			instruction->f = rotr;
		else if (strcmp(instruction->opcode, "stack") == 0)
			instruction->f = stack;
		else if (strcmp(instruction->opcode, "queue") == 0)
			instruction->f = queue;
	}

	return (instruction);
}
