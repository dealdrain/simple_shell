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
