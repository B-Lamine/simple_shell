#ifndef MAIN
#define MAIN

#define TOK_MAXN 10
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define PROMPT "$ "
#define DELIM "\n "
#define EXIT_CMD "exit"

int _strlen(char *s);
unsigned int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int parse(char **ar, char *s, char *delim);
void print_error(char *process, int exit_st, char*cmd);

#endif /* #ifndef MAIN */
