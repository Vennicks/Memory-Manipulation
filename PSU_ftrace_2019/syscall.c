/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** syscall
*/

#include "strace.h"

extern sys_t sys_fct[];
extern types_t pointeurinios[];
extern types_t pointeurinios_s[];

long long unsigned int handle_args(int ag, struct user_regs_struct regs)
{
    switch (ag) {
        case -1:
            return (regs.rax);
        case 0:
            return (regs.rdi);
        case 1:
            return (regs.rsi);
        case 2:
            return (regs.rdx);
        case 3:
            return (regs.rcx);
        case 4:
            return (regs.r8);
        case 5:
            return (regs.r9);
        default:
            return (0);
    }
}

void search_in_ptrinios(char *args, int arg_nb, struct user_regs_struct regs,
int args_status)
{
    for (int i = 0; i < 33; i++) {
        if (strchr(args, '*') != NULL && (strcmp(args, "char *") != 0 &&
        strcmp(args, "char **") != 0)) {
            (args_status == -1) ? print_ptr(handle_args(arg_nb, regs)) :
            print_hexa(handle_args(arg_nb, regs));
            return;
        } else if (strcmp(args, pointeurinios[i].type) == 0) {
            (args_status == -1) ?
            pointeurinios_s[i].print_fct(handle_args(arg_nb, regs))
            : pointeurinios[i].print_fct(handle_args(arg_nb, regs));
            return;
        }
    }
}

void get_syscall_args(struct user_regs_struct regs, sys_t sys_fct,
int args_status)
{
    for (int i = 0; i < sys_fct.nbr_args; i++) {
        search_in_ptrinios(sys_fct.args[i], i, regs, args_status);
        (i != sys_fct.nbr_args - 1) ? printf(", ") : 0;
    }
}

void get_syscall_name(long reg, struct user_regs_struct regs, int args_status)
{
    long i = 0;
    char *sys_name = "";

    while (i < 314) {
        if (reg == i) {
            sys_name = sys_fct[i].name;
            printf("Syscall %s(", sys_name);
            get_syscall_args(regs, sys_fct[i], args_status);
            printf(") = 0x%x\n", (int)handle_args(-1, regs));
        }
        i++;
    }
}