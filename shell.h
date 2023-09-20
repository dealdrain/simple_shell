#ifndef OUR_SIMPLE_SHELL
#define OUR_SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char **argv);
int process_input(char *entry_buffer, char **argv, int error_code);
int print_string(char *str);
char **tokenize(char *str);
int check_builtins(char **args, char *unused, char *entry_buffer);
char *find_path(char *paths, char *cmd);
char *_getpath(void);
void _puts(char *str);
int _putchar(char ch);
void custom_error(char *prog, int counter, char *cmd);
int exec_cmd(char **args, char **argv);
int check_delim(char c, char *delim);
char **custom_strtok(char *str, char *delim);
char **custom_strtok2(char *str, char delim);
void check_comment(char *buf);
int main1(void);

extern char **environ;

#endif /*OUR_SIMPLE_SHELL*/

