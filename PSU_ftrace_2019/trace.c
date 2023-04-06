/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** trace
*/

#include "strace.h"

extern sys_t sys_fct[];
pid_t pid;

void trace(int args_status)
{
    int status;
    long reg;

    while (waitpid(pid, &status, 0) != -1) {
        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        if (__WORDSIZE == 64)
            reg = regs.orig_rax;
        get_syscall_name(reg, regs, args_status);
        ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    }
    write(1, "+++ exited with ", strlen("+++ exited with "));
    system("echo -n $?");
    printf(" +++\n");
}

void pstrace(int args_status)
{
    if (ptrace(PTRACE_ATTACH, args_status, NULL, NULL) == -1) {
        fprintf(stderr, "ptrace() did not work properly.\n");
        exit(84);
    }
    pid = args_status;
    trace(args_status);
}

void strace(char **var, int args_status)
{
    if ((pid = fork()) == -1) {
        fprintf(stderr, "fork() did not work properly.\n");
        exit(84);
    } else if ((pid == 0)) {
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1) {
            fprintf(stderr, "ptrace() did not work properly.\n");
            exit(84);
        }
        execvp(*var, var);
        fprintf(stderr, "execvp() did not work properly.\n");
        exit(84);
    } else {
        trace(args_status);
    }
}

void helper()
{
    printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
    exit(0);
}

int get_args(int argc, char **argv, char ***var)
{
    if (strcmp(argv[1], "--help") == 0)
        helper();
    if (((strcmp(argv[1], "-p") == 0) &&  argc > 2) == 1) {
        int nbr = atoi(argv[2]);
        return (nbr);
    }
    if (((strcmp(argv[1], "-s") == 0) &&  argc > 2) == 1) {
        *var = argv + 2;
        return (-1);
    }
    *var = argv + 1;
    return (0);
}
