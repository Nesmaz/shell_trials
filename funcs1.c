#include "shell.h"

/**
 * _strncmp - Compare two strings up to a specified length.
 * @s1: the first string
 * @s2: the secound string
 * @n: number of characters to compare.
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char str1, str2;

	while (n-- > 0)
	{
		str1 = (unsigned char) *s1++;
		str2 = (unsigned char) *s2++;

		if (str1 != str2)
			return (str1 - str2);
		if (str1 == '\0')
			break;
	}
	return (0);
}

/**
 * _atoi - Converts a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer value of the string.
 */

int _atoi(const char *str)
{
	int i, sign;
	unsigned int num;

	i = 0;
	sign = 1;
	num = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i] - '0');
		else
			break;
		i++;
	}
	return (num * sign);
}

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _memcpy - function that copies memory area
 *
 * @dest: buffer where we will copy to
 * @src: what we are to copy
 * @n: n bytes of @src
 *
 * Return: Always 0 (Success)
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (!ptr)
		return malloc(new_size);

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return ptr;
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	_memcpy(new_ptr, ptr, (old_size < new_size) ? old_size : new_size);

	free(ptr);
	return (new_ptr);
}
