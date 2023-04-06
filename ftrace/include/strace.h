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

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>

#include <signal.h>

typedef struct s_sys {
    char *name;
    int nbr_args;
    char *args[6];
    char *ret_value;
} sys_t;

typedef struct s_types {
    char *type;
    void (*print_fct)(long long unsigned int rest_value);
} types_t;

void get_syscall_name(long reg, struct user_regs_struct regs, int args_status);

void print_int(long long unsigned int reg_value);
void print_hexa(long long unsigned int reg_value);
void print_uint(long long unsigned int reg_value);
void print_long(long long unsigned int reg_value);
void print_ulong(long long unsigned int reg_value);
void print_ptr(long long unsigned int reg_value);
void print_nth(long long unsigned int reg_value);
void print_str(long long unsigned int reg_value);
void print_tab(long long unsigned int reg_value);

int get_args(int argc, char **argv, char ***var);
void strace(char **var, int args_status);
void pstrace(int args_status);

#endif /* !STRACE_H_ */
