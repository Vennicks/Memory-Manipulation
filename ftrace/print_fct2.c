/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_fct2
*/

#include "strace.h"

extern pid_t pid;

void print_hexa(long long unsigned int reg_value)
{
    printf("0x%llx", reg_value);
}

void print_nth(long long unsigned int reg_value)
{
    (void)reg_value;
    return;
}

void print_str(long long unsigned int reg_value)
{
    long c = -1;

    printf("\"");
    for (int i = 0; (char)c != '\0' && i < 42; i++) {
        c = ptrace(PTRACE_PEEKDATA, pid, reg_value, NULL);
        printf("%c", (char)c);
        reg_value++;
    }
    printf("\"");
}

void print_tab(long long unsigned int reg_value)
{
    long str = -1;

    printf("[");
    for (int i = 0; (void*)str != NULL && i < 6; i++) {
        str = ptrace(PTRACE_PEEKDATA, pid, reg_value, NULL);
        print_str((unsigned long long int)str);
        printf(", ");
        reg_value++;
    }
    printf("]");
}