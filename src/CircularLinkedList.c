#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CircularLinkedList.h"

#define coerce(type) *(type *)


struct node *circularlist_create()
{
	struct node *np = malloc(sizeof(struct node));
	np->data = NULL;
	np->next = np;
	np->prev = np;

	return np;
}

static void circularlist_expand(struct node *lnode)
{
	// Create new node.
	struct node *new = malloc(sizeof(struct node));
	new->data = NULL;

	// Update links.
	lnode->prev->next = new;
	new->prev = lnode->prev;
	lnode->prev = new;
	new->next = lnode;

    return;
}

void circularlist_insert(struct node **lnode, void *data)
{
	struct node *current = *lnode;
	do {
		if (current->data == NULL) {
			current->data = data;
			return; // Once data inserted, no need to continue.
		} else {
			continue;
		}
	} while (current = current->next, current != *lnode);

	// Exiting the while loop implies there are no available spots.
	// So we must exand the list to create one.
	circularlist_expand(*lnode);
	// Re-attempt inserting data into updated list.
	circularlist_insert(lnode, data); // recursive call.
	return;
}

void circularlist_delete(struct node **remove)
{
	// links update.
	(*remove)->prev->next = (*remove)->next;
	(*remove)->next->prev = (*remove)->prev;
	free((*remove)->data);
	free(*remove);
	return;
}

struct node *circularlist_find(struct node *lnode, void *query,
                               int (*compare)(const void *, const void *))
{
	struct node *current = lnode;
	do {
		if ((*compare)(query, current->data) == 0)
			return current;
	} while (current = current->next, current != lnode);
}

int circularlist_compare_strings(const void *s1, const void *s2)
{
	return strcmp((const char *)s1, (const char *)s2);
}

int circularlist_compare_integers(const void *p, const void *q)
{
	if (coerce(int) p == coerce(int) q)
		return 0; // Following strcmp return convention
	else
		return 1;
}

void circularlist_traverse(struct node *lnode,
                           void (*callback)(struct node *))
{
	struct node *current = lnode;
	do {
		(*callback)(current);
	} while (current = current->next, current != lnode);

	return;
}

void circularlist_print(struct node *lnode)
{
    // Assumes data has been assigned char *
    puts(lnode->data);
}
