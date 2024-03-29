#include "main.h"
/**
 * display_error - prints an error message
 * @estr: input
 * @idx: input
 * @cmd: commande
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void display_error(char *estr, char *cmd, int idx)
{
	char *index;
	char error[] = ": not found\n";

	index = _atoi(idx);
	write(STDERR_FILENO, estr, _strlen(estr));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, error, _strlen(error));
	free(index);

}
/**
 * _atoi - converts a integer to an string
 * @i: the intger to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

char *_atoi(int i)
{
	int j = 0;
	char buffer[20];

	if (i == 0)
		buffer[j++] = '0';
	else
	{
		while (i > 0)
		{
			buffer[j++] = (i % 10) + '0';
			i /= 10;
		}
	}

	buffer[j] = '\0';
	convert_string(buffer, j);
	return (_strdup(buffer));
}
/**
 * convert_string - converter function, a clone of itoa
 * @num: number
 * @str: string
 * Return: void
 */
void convert_string(char *str, int num)
{
	char tmp;
	int d = 0;
	int f = num - 1;

	while (d < f)
	{
		tmp = str[d];
		str[d] = str[f];
		str[f] = tmp;
		d++;
		f--;
	}
}
/**
 * positive_num - cheking if number is positive
 * @s: number
 * Return: 1 , 0
 */
int positive_num(char *s)
{
	int i;

	if (!s)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * _atoi1 - cheking if number is positive
 * @str: number
 * Return: 1 , 0
 */
int _atoi1(char *str)
{
	int j;
	int num = 0;

	for (j = 0; str[j]; j++)
	{
		num *= 10;
		num += (str[j] - '0');
	}
	return (num);
}


