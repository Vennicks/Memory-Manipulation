/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print_fct
*/

#include "strace.h"

void print_int(long long unsigned int reg_value)
{
    printf("%d", (int)reg_value);
}

void print_uint(long long unsigned int reg_value)
{
    printf("%u", (unsigned int)reg_value);
}

void print_long(long long unsigned int reg_value)
{
    printf("%ld", (long)reg_value);
}

void print_ulong(long long unsigned int reg_value)
{
    printf("%lu", (unsigned long)reg_value);
}

void print_ptr(long long unsigned int reg_value)
{
    if ((void *)reg_value == 0)
        printf("NULL");
    else
        printf("%p", (void *)reg_value);
}