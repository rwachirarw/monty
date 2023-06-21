#include "monty.h"

char *data = NULL;

/**
 * main - starting point of the program
 * @ac: number of arguments passed to main
 * @av: pointer to string of arguments passed
 * Return: always 0
 */
int main(int ac, char **av)
{
	FILE *fd;
	instruction_t instruct[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", div_stack},
		{"mul", mul}, {"mod", mod},
		{NULL, NULL}
	};
	struct stat sb;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stat(av[1], &sb);
	if (!(S_ISREG(sb.st_mode)) || access(av[1], R_OK) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	read_line(instruct, fd);
	fclose(fd);
	return (0);
}

/**
 * read_line - reads the lines in the file
 * @instruct: a struct of functions
 * @fd: file descriptor
 */
void read_line(instruction_t *instruct, FILE *fd)
{
	char *instruction = NULL;
	unsigned int not_instr, i, line_number = 0;
	stack_t *head = NULL;
	char line[256];


	while (fgets(line, sizeof(line), fd))
	{
		line_number++;
		i = 0;
		instruction = strtok(line, " \n\t");
		not_instr = 1;
		if (*instruction == '#')
			continue;
		while (instruct[i].opcode && instruction)
		{
			if (strcmp(instruction, instruct[i].opcode) == 0)
			{
				not_instr = 0;
				data = strtok(NULL, " \n\t");
				instruct[i].f(&head, line_number);
				break;
			}
			i++;
		}
		if (instruction && not_instr)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
					line_number, instruction);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&head);
}
