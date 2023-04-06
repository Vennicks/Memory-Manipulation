/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** function1
*/

#include "../includes/nm.h"

char print_type(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        c = 'u';
    else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        c = 'W';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'w';
    } else
        c = print_type2(sym, shdr);
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
        c += 32;
    return (c);
}

nm_t *add_struct(char *str, Elf64_Sym sym, nm_t *list, Elf64_Shdr *shdr)
{
    nm_t *new = malloc(sizeof(nm_t));
    if (list == NULL) {
        free(new);
        list = malloc(sizeof(nm_t));
        list->head = list;
        list->prev = NULL;
        list->next = NULL;
        list->name = str + sym.st_name;
        list->symbol = print_type(sym, shdr);
        return (list);
    }
    new->name = str + sym.st_name;
    new->value = sym.st_value;
    new->symbol = print_type(sym, shdr);
    new->head = list->head;
    new->next = NULL;
    new->prev = list;
    list->next = new;
}

char *mod(char *str)
{
    char *modstr = str;
    while (*modstr) {
        if (isalpha(*modstr))
            return (modstr);
        modstr++;
    }
    return (modstr);
}

void modname(nm_t *list)
{
    nm_t *cpy = NULL;
    nm_t *temp = list;
    nm_t *restart = list;
    int i;
    while (temp->next != NULL) {
        i = strcasecmp(mod(temp->name), mod(temp->next->name));
        if (i == 0) {
            i = strcasecmp(temp->name, temp->next->name);
        }
        if (i == 0) {
            i = (temp->value > temp->next->value) ? 1 : 0;
        }
        if (i > 0) {
            (temp->prev != NULL) ? temp->prev->next = temp->next : 0;
            cpy = temp->next;
            temp->next->prev = (temp->prev != NULL) ? temp->prev : NULL;
            temp->next = (temp->next->next != NULL) ? temp->next->next : NULL;
            (temp->next != NULL) ? temp->next->prev = temp : 0;
            cpy->next = temp;
            temp->prev = cpy;
            (temp == restart) ? restart = temp->prev : 0;
            temp = restart;
        } else
            temp = temp->next;
    }
}
