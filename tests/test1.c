#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularLinkedList.h"

char *fget_string(FILE *fp);

void populate_wordlist(struct node **list, FILE *stream);

int main(int argc, char *argv[])
{
    FILE *fp = argv[1] ? fopen(argv[1], "r")
                       : stdin;

    struct node *head = circularlist_create();
    populate_wordlist(&head, fp);
    circularlist_traverse(head, circularlist_print);

    return 0;
} // main

char *fget_string(FILE *fp)
{
    enum {initial, updated};
    int size = 128;
    char *pp[2];
    char  *p  = malloc(size);
    pp[initial] = p;

    int c;
    while ((c = fgetc(fp)) != EOF &&
           (*p++ = c) != '\n') {
        if ((p - pp[initial]) >= size) {
            size += size;
            pp[updated] = malloc(sizeof(char) * size);
            memcpy(pp[updated], pp[initial], (p - *pp));
            p = pp[updated] + (p - pp[initial]);
            free(pp[initial]);
            pp[initial] = p;
        }
    }
    *p = '\0';
    return *pp;
}

void populate_wordlist(struct node **list, FILE *stream)
{
    char *buffer = fget_string(stream);

    for (char *splice = strtok(buffer, " ");
         splice; splice = strtok(NULL, " ")) {
        char *tmp = malloc(strlen(splice) + 1);
        strcpy(tmp, splice);
        circularlist_insert(list, tmp);
    }
}
