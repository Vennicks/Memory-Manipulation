/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** main
*/

#include "include/strace.h"

int main(int argc, char **argv)
{
    char **var;
    if (argc < 2)
        return (84);
    int args_status = get_args(argc, argv, &var);
    if (args_status == 0 || args_status == -1) {
        strace(var, args_status);
    } else {
        pstrace(args_status);
    }
    return (0);
}
