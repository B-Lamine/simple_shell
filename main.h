#ifndef MAIN
#define MAIN

#define TOK_MAXN 10
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define PROMPT "$ "
#define DELIM "\n "
#define EXIT_CMD "exit"

int _strlen(const char *s);
unsigned int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int parse(char **ar, char *s, char *delim);
void print_error(char *process, int exit_st, char*cmd);
char *_getenv(const char *name, char **env);

/**
  * struct list_s - singly linked list
  * @str: string,
  * @len: length of the string,
  * @next: pointer to the next node.
  * Description: singly linked list node structure.
  */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
list_t *linked_path(list_t **head, char **env);
void free_list(list_t *head);
int _strncmp(const char *s1, const char *s2, int len);
char *_strdup(const char *str);
char *_which(char **filename, const char *path, int *nst);
#endif /* #ifndef MAIN */
