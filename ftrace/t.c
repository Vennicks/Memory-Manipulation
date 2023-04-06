/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** t
*/

#include "stdio.h"
#include "unistd.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

int main()
{
    my_putstr("ded\n");
    printf("tut\n");
    return (0);
}