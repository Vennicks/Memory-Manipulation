/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** print
*/

#include "../include/strace.h"
#include <errno.h>
extern __pid_t pid;

void print_int(long long unsigned int i)
{
    int z = (int)i;
    printf("%d", z);
}

void print_char(long long unsigned int i)
{
    char z = (char)i;
    printf("%c", z);
}

void print_string(long long unsigned int data)
{
    unsigned long long z = 'i';
    char array[4096];
    unsigned long long cnt = 0;
    void *end;
    while (1)
    {
        z = ptrace(PTRACE_PEEKDATA, pid, data+ cnt);
        memcpy(array+cnt, &z, sizeof(z));
        if (errno != 0) {
          array[cnt] = 0;
          break;
        } if (memchr(&z, 0, sizeof(z)) != NULL) {
            printf("%s", array);
            return;
        }
        cnt = cnt + sizeof(z);
    }
}

void print_double(long long unsigned int i)
{
    double z = (double)i;
    printf("%f", z);
}

void print_long(long long unsigned int i)
{
    long z = (long)i;
    printf("%ld", z);
}

void print_unsigned_long(long long unsigned int i)
{
    unsigned long z = (unsigned long)i;
    printf("%lu", z);
}

void print_addr(long long unsigned int pointer)
{
    if (pointer == 0) {
        printf("0x0");
        return;
    }
    printf("%p", (void *)pointer);
}

void print_string_array(long long unsigned int z)
{
    (void) z;
    printf("VALUE");
}

void print_unsigned_long_array(long long unsigned int z)
{
    unsigned long *array = (unsigned long *)z;
    printf("[");
    for(int i = 0; array[i] != '\0'; i++)
    {
        printf("%lu", array[i]);
        if (i+1 != sizeof(array))
            printf(", ");
    }
    printf("]");
}

void print_int_array(long long unsigned int z)
{
    int *array = (int *) z;
    printf("[");
    for(int i = 0; array[i] != '\0'; i++)
    {
        printf("\"");
        printf("%d", array[i]);
        printf("\"");
        if (i+1 != sizeof(array))
            printf(", ");
    }
    printf("]");
}

void print_void(long long unsigned int i)
{
    (void)i;
}

struct bite printing[] =
{
    {STRING, &print_string},
    {CHAR, &print_char},
    {STRING_ARRAY, &print_string_array},
    {UNSIGNED_CHAR_ARRAY, &print_string},
    {INT, &print_int},
    {DOUBLE, &print_double},
    {LONG, &print_long},
    {SIZE_T, &print_unsigned_long},
    {SSIZE_T, &print_long},
    {UNSIGNED_INT, &print_unsigned_long},
    {UNSIGNED_LONG, &print_unsigned_long},
    {UNSIGNED_LONG_ARRAY, &print_addr},
    {INT_ARRAY, &print_addr},
    {VOID_ARRAY, &print_addr},
    {ADDR, &print_addr},
    {VOID, &print_void}
};