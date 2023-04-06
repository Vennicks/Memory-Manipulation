/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include "../includes/nm.h"

int handle_error(int argc, const char *path)
{
    int fd;
    if (argc == 2)
        fd = open(path, O_RDONLY);
    else if (argc < 2)
        fd = open("a.out", O_RDONLY);
    if (fd <= 0) {
        printf("nm: '%s': No such file\n", (argc < 2) ? "a.out" : path);
        exit(EXIT_FAILURE);
    }
}

void start_elf(main_t *mainL)
{
    mainL->elf = (Elf64_Ehdr *)(mainL->data);
    mainL->shdr = (Elf64_Shdr *)(mainL->data + mainL->elf->e_shoff);
    mainL->strtab = (mainL->data + \
    mainL->shdr[mainL->elf->e_shstrndx].sh_offset);
    mainL->str = (char *) (mainL->data + \
    mainL->shdr[mainL->elf->e_shstrndx].sh_offset);

    for (int i = 0; i < mainL->elf->e_shnum; i++) {
        if (strcasecmp(&mainL->str[mainL->shdr[i].sh_name], ".symtab") == 0)
            mainL->symtab = (Elf64_Shdr *) &mainL->shdr[i];
        if (strcmp(&mainL->str[mainL->shdr[i].sh_name], ".shstrtab") == 0)
            mainL->shstrtab = (Elf64_Shdr *) &mainL->shdr[i];
        if (strcmp(&mainL->str[mainL->shdr[i].sh_name], ".strtab") == 0)
            mainL->strtab = (Elf64_Shdr *) &mainL->shdr[i];
    }
    mainL->sym = (Elf64_Sym*) (mainL->data + mainL->symtab->sh_offset);
    mainL->str = (char*) (mainL->data + mainL->strtab->sh_offset);
}

nm_t *fill_list(nm_t *list, main_t *mainL)
{
    list = add_struct(mainL->str, mainL->sym[mainL->count], list, mainL->shdr);
    for (size_t i = 0; i < mainL->symtab->sh_size / sizeof(Elf64_Sym); i++) {
        list = add_struct(mainL->str, mainL->sym[i], list, mainL->shdr);
        list = list->next;
    }
    return (list);
}

void display_list(nm_t *list)
{
    while (list != NULL) {
        if (strlen(list->name) != 0 && list->symbol != 'a' &&list->symbol != 'U'
        && list->symbol != 'w')
            printf("%016x %c %s\n", list->value, list->symbol, list->name);

        else if (strlen(list->name) != 0 && list->symbol != 'a' && (list->symbol == 'U'
        || list->symbol == 'w')) {
            write(1, "                 ", 17);
            printf("%c %s\n", list->symbol, list->name);
        }
        list = list->next;
    }
}

int main(int argc, char const *argv[])
{
    main_t *mainL = malloc(sizeof(main_t));
    nm_t *list = NULL;
    mainL->count = 0;
    mainL->fd = handle_error(argc, argv[1]);
    mainL->filesize = lseek(mainL->fd, 0, SEEK_END);
    mainL->data = mmap(NULL, mainL->filesize, PROT_READ,
    MAP_SHARED, mainL->fd, 0);
    if (mainL->data != NULL) {
        start_elf(mainL);
        list = fill_list(list, mainL);
        list = list->head;
        modname(list);
        display_list(list);
        return (EXIT_SUCCESS);
    }
    perror("mmap: ");
    return (EXIT_FAILURE);
}