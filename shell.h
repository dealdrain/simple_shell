#ifndef OUR_SIMPLE_SHELL
#define OUR_SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * struct built_ins - Structure of command and function
 * @cmd: this will be used for comparison
 * @func_cmd: this function is called when command matches
 */

typedef struct built_ins
{
	char *cmd;
	void (*func_cmd)(char **argv, char **environ, char **token_arr);
} built_ins;

/*Global status*/
int status;
int cmd_count;
extern char **environ;

int _atoi(char *s);
void chng_dir(char **argv, char **environ, char **token_arr);
int check_builtins(char **argv, char **environ, char **token_arr);
void check_comment(char *buf);
void cus_err_msg(int fd, int cmd_count, char *s1, char *s2, char *s3);
char **custom_strtok(char *str, char *delim);
char **custom_strtok2(char *str, char delim);
void environ_func(char **argv, char **environ, char **token_arr);
void exit_func(char **argv, char **environ, char **token_arr);
char *check_path(char *cmd, char *path);
char *find_path(char *paths, char *cmd);
char *get_path(char **environ);
void free_array(char **arr_tokens);
char *_getpath(void);
char **tokenize(char *str);
char **process_input(char **argv, int *mode);
void handle_signal(int signum);
char **path_split(char *path_dir);
void handle_mode(char **argv, char **environ, int *cmd_count, int *mode);
void handle_path(char **token_arr, char **environ, char **argv, int mode);
int handle_path_missing(char *in_path, char **token_arr,
                char **environ, int *mode, int *cmd_count, char **argv);
int main(int argc, char **argv, char **environ);
int process_path(char **argv, char **environ, char **token_arr, int *cmd_count);
char **splitter(char *user_input);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
char *_substr(char *haystack, char *needle);
int mul(int a, int b);

#endif /*OUR_SIMPLE_SHELL*/
