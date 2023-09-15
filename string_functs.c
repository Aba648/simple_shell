#include "main.h"
/**
 * _strdup - This function duplicate a string
 * @str: input string
 * Return: Pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	const char *lineptr_cpy = str;
	char *duplicate;
	int i;

	if (str == NULL)
		return (NULL);
	while (*lineptr_cpy++)
		length++;
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];
	return (duplicate);
}
/**
 * _strcmp - Performs lexicographic comparison of two strings.
 * @s1: string1
 * @s2: string2
 * Return: Negative,positive or zero
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strlen - give us the length of a string
 * @s: the length of string that we check
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * Return: A pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	int a, c;

	for (a = 0; dest[a] != '\0'; a += 1)
	{}

	for (c = 0; src[c] != '\0'; c += 1)
	{
		dest[a] = src[c];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
/**
 * _strcpy - the function that copies the string pointed to by src
 * @dest: pointer1
 * @src: ponter2
 * Return: return dest
 */
char *_strcpy(char *dest, char *src)
{
	char *s = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
