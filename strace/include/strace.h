/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>
#include <syscall.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/resource.h>
#include <sys/reg.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>

#include <signal.h>

# define FAILURE 0
# define SUCCESS 1
# define EXIT 2

//void (*print_func)(long long unsigned int);

struct bite
{
    int couille;
    void (*print_func)(long long unsigned int);
}bite_t;

enum type
{
    STRING = 0,
    CHAR,
    STRING_ARRAY,
    UNSIGNED_CHAR_ARRAY,
    INT,
    DOUBLE,
    LONG,
    SIZE_T,
    SSIZE_T,
    UNSIGNED_INT,
    UNSIGNED_LONG,
    UNSIGNED_LONG_ARRAY,
    INT_ARRAY,
    VOID_ARRAY,
    ADDR,
    VOID
}enum_t;

typedef struct	s_prototype
{
  char		*name;
  int		nb_params;
  int		params[6];
  int		ret_type;
}		t_prototype;

#endif /* !STRACE_H_ */
