#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H


struct node *
circlinkedlist_create();

void
circlinkedlist_expand(struct node *head);

void
circlinkedlist_insert(struct node **head, void *data);

void
circlinkedlist_delete(struct node **remove);

void
circlinkedlist_traverse(struct node *head, void (*callback)(struct node *));

struct node*
circlinkedlist_find(struct node *list, void *item,
                    int (*compare)(const void *, const void *));

int
compare_strings(const void *s1, const void *s2);

int
compare_integers(const void *p, const void *q);

#endif  // CIRCULAR_LINKED_LIST_H
