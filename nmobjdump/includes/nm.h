/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_
#include <elf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libelf.h>
#include <zconf.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NO_TYPE '?'

typedef struct nm_s nm_t;
typedef struct main_s main_t;

char		c_flag(Elf64_Sym *symtab);
struct nm_s
{
    char *name;
    char symbol;
    unsigned int value;
    nm_t *head;
    nm_t *next;
    nm_t *prev;
};

struct main_s
{
    int counter;
    int filesize;
    void *data;
    int fd;
    char *str;
    size_t count;
    Elf64_Shdr *strtab;
    Elf64_Ehdr *elf;
    Elf64_Shdr *shdr;
    Elf64_Sym *sym;
    Elf64_Shdr *symtab;
    Elf64_Shdr *shstrtab;
    Elf64_Sym buff;
};

typedef struct	s_flags
{
  int		stt;
  Elf64_Word	sh_type;
  Elf64_Word	sh_flags;
  char		type;
}		t_flags;

char print_type6(Elf64_Sym sym, Elf64_Shdr *shdr);
char print_type5(Elf64_Sym sym, Elf64_Shdr *shdr);
char print_type4(Elf64_Sym sym, Elf64_Shdr *shdr);
char print_type3(Elf64_Sym sym, Elf64_Shdr *shdr);
char print_type2(Elf64_Sym sym, Elf64_Shdr *shdr);
char print_type(Elf64_Sym sym, Elf64_Shdr *shdr);
nm_t *add_struct(char *str, Elf64_Sym sym, nm_t *list, Elf64_Shdr *shdr);
char *mod(char *str);
void modname(nm_t *list);

#endif /* !NM_H_ */
