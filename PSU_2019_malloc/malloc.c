/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#include "./include/malloc.h"
void *tail = NULL;
void *head = NULL;

header_t create_new_header(size_t size)
{
    size_t size_to_alloc = 4096;
    header_t new_header = sbrk(0);
    if (new_header == NULL)
        return (BAD_ALLOC);
    while (size > size_to_alloc)
        size_to_alloc = size_to_alloc * 2;
    if (size_to_alloc < 4096)
        return (BAD_ALLOC);
    if (sbrk(size + sizeof(struct header)) == BAD_ALLOC)
        return (BAD_ALLOC);
    new_header->size_used = size;
    new_header->size_max = size_to_alloc;
    new_header->next = NULL;
    new_header->free = false;
    return (new_header);
}

header_t find_good_header(size_t size)
{
    header_t list = head;
    while (list != NULL) {
        if (list->free == false && ((list->size_used + size) >= list->size_max))
            return (list);
        list = list->next;
    }
    return (NULL);
}

header_t alloc_space(header_t alloc_in, size_t size)
{
    alloc_in = sbrk(sizeof(struct header) + alloc_in->size_used);
    if (sbrk(size) == BAD_ALLOC)
        return (BAD_ALLOC);
    alloc_in->size_used += size;
    return (alloc_in);
}

void *malloc(size_t size)
{
    header_t new_header;
    header_t last_header = (header_t)tail;
    if (size <= 0)
        return (NULL);
    if (tail == NULL) {
        new_header = create_new_header(size);
        tail = new_header;
        head = new_header;
    } else {
        new_header = find_good_header(size);
        if (new_header == NULL) {
            new_header = create_new_header(size);
            last_header->next = new_header;
            tail = (void *)new_header;
        } else
            new_header = alloc_space(new_header, size);
    }
    if (new_header == BAD_ALLOC) return (NULL);
    return (new_header + 1);
}