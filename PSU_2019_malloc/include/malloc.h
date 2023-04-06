/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define SIZE 4096
#define BAD_ALLOC (void *)-1

typedef struct header *header_t;

struct header {
    size_t size_used;
    size_t size_max;
    struct header *next;
    bool free;
};
void free(void *free);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);

#endif /* !MALLOC_H_ */
