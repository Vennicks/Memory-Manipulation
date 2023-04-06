/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** main
*/

#include "../include/strace.h"

extern t_prototype g_syscalls[];
extern struct bite printing[];
__pid_t pid;

void write_error(const char *str)
{
    fprintf(stderr, str);
    exit(84);
}

void print_type(int i, int type, struct user_regs_struct regs)
{
    switch (i) {
        case 0:
            printing[type].print_func(regs.rdi);
            break;
        case 1:
            printing[type].print_func(regs.rsi);
            break;
        case 2:
            printing[type].print_func(regs.rdx);
            break;
        case 3:
            printing[type].print_func(regs.rcx);
            break;
        case 4:
            printing[type].print_func(regs.r8);
            break;
        case 5:
            printing[type].print_func(regs.r9);
            break;
    }
}

void print_return(int s_option, long reg, struct user_regs_struct regs)
{
    printf(") = ");
    if (g_syscalls[reg].ret_type != VOID && s_option == 1)
        printing[g_syscalls[reg].ret_type].print_func(regs.rax);
    else if (g_syscalls[reg].ret_type != VOID && s_option == 0)
        printing[ADDR].print_func(regs.rax);
    printf("\n");
}

void print_line(long reg, struct user_regs_struct regs, int s_option)
{
    int type = 0;
    printf("%s(", g_syscalls[reg].name);
    for (int z = 0; z != g_syscalls[reg].nb_params; z++) {
        type = g_syscalls[reg].params[z];
        if (s_option)
            print_type(z, type, regs);
        else
            print_type(z, ADDR, regs);
        if (z+1 != g_syscalls[reg].nb_params)
            printf(", ");
    }
    print_return(s_option, reg, regs);
}

void ssstrace(char **var, int s_option)
{
    int status;
    int ret;
    long reg;
    if ((pid = fork()) == -1)
        write_error("fork() did not work properly.\n");
    else if ((pid == 0)) {
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
            write_error("ptrace() did not work properly.\n");
        ret = execvp(*var, var);
        write_error("execvp() did not work properly.\n");
    } else {
        (void) ret;
        while (waitpid(pid, &status, 0) != -1) {
            struct user_regs_struct regs;
            ptrace(PTRACE_GETREGS, pid, NULL, &regs);
            long data = ptrace(PTRACE_PEEKTEXT, pid, regs.rax, NULL);
            data = data & 0xffff;
            if (__WORDSIZE == 64)
                reg = regs.orig_rax;
            if (g_syscalls[reg].name != NULL && reg != -1)
                print_line(reg, regs, s_option);
            ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
        }
        write(1, "+++ exited with ", 16);
        system("echo -n $?");
        printf(" +++\n");
    }
}

void pstrace(int var, int s_option)
{
    int status;
    long reg;
    struct rusage usage;
    pid = var;
    ptrace(PT_ATTACH, pid, NULL, NULL);
    while (waitpid(pid, &status, 0) != -1) {
        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        long data = ptrace(PTRACE_PEEKTEXT, pid, regs.rax, NULL);
        data = data & 0xffff;
        if (__WORDSIZE == 64)
            reg = regs.orig_rax;
        if (g_syscalls[reg].name != NULL)
            print_line(reg, regs, s_option);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    }
    write(1, "+++ exited with ", 16);
    system("echo -n $?");
    printf(" +++\n");
}

int get_args(char **argv, char ***var, int *c)
{
    int i = 0;
    if (strcmp(argv[1], "-s") == 0) {
        *c = 1;
        i ++;
    }
    if (strcmp(argv[1+i], "-p") == 0) {
        if (argv[2+i] == NULL)
            exit (84);
        return (atoi(argv[2+i]));
    }
    if (argv[1+i] == NULL)
        exit (84);
    *var = argv + 1 + i;
    return (0);
}

int main(int argc, char **argv)
{
    char **var;
    int c = 0;
    if (argc < 2 || argc > 5)
        return (84);
    int args_status = get_args(argv, &var, &c);
    if (args_status == 0)
        ssstrace(var, c);
    else
        pstrace(args_status, c);
    return (0);
}