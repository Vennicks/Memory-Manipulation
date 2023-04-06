/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** types
*/

#include "strace.h"

const types_t pointeurinios_s[] =
{
    {"void", &print_nth},
    {"char *", &print_str},
    {"char **", &print_tab},
    {"int", &print_int},
    {"int[2]", &print_ptr},
    {"uint32_t", &print_uint},
    {"unsigned int", &print_uint},
    {"long", &print_long},
    {"unsigned long", &print_ulong},
    {"u64", &print_ulong},
    {"size_t", &print_ulong},
    {"ssize_t", &print_long},
    {"caddr_t", &print_str},
    {"ndfs_t", &print_int},
    {"off_t", &print_ulong},
    {"key_t", &print_ulong},
    {"pid_t", &print_int},
    {"socklen_t", &print_ulong},
    {"uid_t", &print_int},
    {"gid_t", &print_int},
    {"gid_t[]", &print_ptr},
    {"clock_t", &print_ulong},
    {"cap_user_header_t", &print_ptr},
    {"cap_huser_data_t", &print_ptr},
    {"dev_t", &print_ulong},
    {"off64_t", &print_ulong},
    {"cpu_set_t", &print_ulong},
    {"aio_context_t", &print_ulong},
    {"mqd_t", &print_int},
    {"idtype_t", &print_ulong},
    {"key_serial_t", &print_ulong},
    {NULL, NULL}
};

const types_t pointeurinios[] =
{
    {"void", &print_nth},
    {"char *", &print_ptr},
    {"char **", &print_ptr},
    {"int", &print_hexa},
    {"int[2]", &print_ptr},
    {"uint32_t", &print_hexa},
    {"unsigned int", &print_hexa},
    {"long", &print_hexa},
    {"unsigned long", &print_hexa},
    {"u64", &print_hexa},
    {"size_t", &print_hexa},
    {"ssize_t", &print_hexa},
    {"caddr_t", &print_ptr},
    {"ndfs_t", &print_hexa},
    {"off_t", &print_hexa},
    {"key_t", &print_hexa},
    {"pid_t", &print_hexa},
    {"socklen_t", &print_hexa},
    {"uid_t", &print_hexa},
    {"gid_t", &print_hexa},
    {"gid_t[]", &print_ptr},
    {"clock_t", &print_hexa},
    {"cap_user_header_t", &print_ptr},
    {"cap_huser_data_t", &print_ptr},
    {"dev_t", &print_hexa},
    {"off64_t", &print_hexa},
    {"cpu_set_t", &print_hexa},
    {"aio_context_t", &print_hexa},
    {"mqd_t", &print_hexa},
    {"idtype_t", &print_hexa},
    {"key_serial_t", &print_hexa},
    {NULL, NULL}
};