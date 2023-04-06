/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** alloc_func
*/

#include "./include/malloc.h"

void free(void *to_free)
{
    struct header *new_header = (header_t)to_free -1;
    if (to_free == NULL)
        return;
    new_header->free = true;
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL || size <= 0)
        return (malloc(size));
    void *new_ptr = malloc(size);
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}

void *calloc(size_t nmemb, size_t size)
{
    void *new_ptr;
    size_t new_size = nmemb * size;
    if (size <= 0 || nmemb <= 0 || new_size <= 0)
        return (NULL);
    new_ptr = malloc(new_size);
    memset(new_ptr, 0, new_size);
    return (new_ptr);
}
