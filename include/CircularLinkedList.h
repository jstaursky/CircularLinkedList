#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

struct node {
	void *data;
	struct node *next;
	struct node *prev;
};


struct node *circlinkedlist_create();

void circlinkedlist_insert(struct node **lnode, void *data);

void circlinkedlist_delete(struct node **remove);

struct node *circlinkedlist_find(struct node *lnode, void *item,
                                 int (*compare)(const void *, const void *));

int compare_strings             (const void *s1, const void *s2);

int compare_integers            (const void *p, const void *q);

void circlinkedlist_traverse(struct node *lnode,
                             void (*callback)(struct node *));

void circlinkedlist_print   (struct node *lnode);

#endif // CIRCULAR_LINKED_LIST_H
