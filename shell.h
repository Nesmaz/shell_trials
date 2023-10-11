#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* functions */
void print_prompt(void);
void *get_line(void);
char *get_input(void);
int execute(char **argv);
char *get_path(void);

/* strings function */
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* more functions */
int _atoi(const char *str);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* Printing functions*/
int _putchar(char ch);
void _puts(char *str);
void _puterror(char *err_msg);

/* tokenizers*/
char **tokenize(char *str, const char *delim);
char **tokenize_input(char *str);

/* Free functions*/
void free_tokens(char **ptr);

/* Signal handlers*/
void _sigint(int signal);
void _sigquit(int signal);
void _sigstp(int signal);

#endif
