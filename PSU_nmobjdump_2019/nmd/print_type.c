/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** print_type
*/

#include "../includes/nm.h"

char print_type6(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;
    if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        c = 'D';
    else
        c = '?';
    return (c);
}

char print_type5(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;
    if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        c = 'D';
    else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        c = 'T';
    else
        return print_type6(sym, shdr);
    return (c);
}

char print_type4(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;
    if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
        && shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        c = 'B';
    else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
        c = 'R';
    else
        return print_type5(sym, shdr);
    return (c);
}

char print_type3(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;
    if (sym.st_shndx == SHN_ABS)
        c = 'A';
    else if (sym.st_shndx == SHN_COMMON)
        c = 'C';
    else
        return print_type4(sym, shdr);
    return (c);
}

char print_type2(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char c;
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK
    && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) {
        c = 'V';
        if (sym.st_shndx == SHN_UNDEF)
            c = 'v';
    } else if (sym.st_shndx == SHN_UNDEF)
        c = 'U';
    else
        return print_type3(sym, shdr);
    return (c);
}








