#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CircularLinkedList.h"

#define coerce(type) *(type *)



struct node *circlinkedlist_create()
{
	struct node *np = malloc(sizeof(struct node));
	np->data = NULL;
	np->next = np;
	np->prev = np;

	return np;
}


void circlinkedlist_expand(struct node *head)
{
	// Create new node.
	struct node *new = malloc(sizeof(struct node));
	new->data = NULL;

	// Update links.
	head->prev->next = new;
	new->prev = head->prev;
	head->prev = new;
	new->next = head;

	return;
}


void circlinkedlist_insert(struct node **head, void *data)
{
	struct node *current = *head;
	do {
		if (current->data == NULL) {
			current->data = data;
			return; // Once data inserted, no need to continue.
		} else {
			continue;
		}
	} while (current = current->next, current != *head);

	// Exiting the while loop implies there are no available spots.
	// So we must exand the list to create one.
	circlinkedlist_expand(*head);
	// Re-attempt inserting data into updated list.
	circlinkedlist_insert(head, data); // recursive call.
	return;
}


void circlinkedlist_delete(struct node **remove)
{
	// links update.
	(*remove)->prev->next = (*remove)->next;
	(*remove)->next->prev = (*remove)->prev;
	free((*remove)->data);
	free(*remove);
	return;
}


struct node *circlinkedlist_find(struct node *list, void *item,
                                 int (*compare)(const void *, const void *))
{
	struct node *current = list;
	do {
		if ((*compare)(item, current->data) == 0)
			return current;
	} while (current = current->next, current != list);
}


int compare_strings(const void *s1, const void *s2)
{
	return strcmp((const char *)s1, (const char *)s2);
}


int compare_integers(const void *p, const void *q)
{
	if (coerce(int) p == coerce(int) q)
		return 0; // Following strcmp return convention
	else
		return 1;
}

void circlinkedlist_traverse(struct node *head, void (*callback)(struct node *))
{
	struct node *current = head;
	do {
		(*callback)(current);
	} while (current = current->next, current != head);

	return;
}