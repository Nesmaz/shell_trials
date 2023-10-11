#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int i, len = 0;
	char *string;

	if (str == NULL)
		return (NULL);

	while (str[len])
	{
		len++;
	}
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		string[i] = str[i];
	return (string);
}

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *str = dest;

	while (*str)
	{
		str++;
	}
	while (*src)
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';
	return (str);
}

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	int compare = 0;

	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
	{
		compare = (*s1 > *s2) ? 1 : -1;
	}

	return (compare);
}
