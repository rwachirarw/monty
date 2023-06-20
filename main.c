#include "monty.h"

/**
 * main - starting point of the program
 * @ac: number of arguments passed to main
 * @av: pointer to string of arguments passed
 * Return: always 0
 */
int main(int ac, char **av)
{
	FILE *fd;
	char line[256];
	char *instruction = NULL, *str_int = NULL;
	unsigned int i = 0, line_number = 0;
	instructions_t instruct[] = {
		{"push", push}, {"pall", pall}, {"NULL", NULL}
	};
	stack_t *my_stack;

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s \n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fd))
	{
		instruction = strtok(line, " \n");
		i = 0;
		not_instr = 1;
		line_number++;
		while (instruct[i].opcode && instruction)
		{
			if (strcmp(instruction, instruct[i].opcode) == 0)
			{
				not_instr = 0;
				str_int = strtok(NULL, " \n");
				data = atoi(str_int);
				instruct[i].f(&my_stack, line_number);
				break;
			}
			i++;
		}
		if (instruction && not_instr)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s \n",
					line_number, instruction);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fd);
	return (0);
}

