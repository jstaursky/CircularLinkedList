#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

struct node {
	void *data;                 // data is a generic pointer.
	struct node *next;
	struct node *prev;
};

/**
   circularlist_create -- Creates an initial node for the basis of a
                          circularlist.

   Returns -- A new node with an unintialized data pointer.
  */
struct node *circularlist_create();
// -----------------------------------------------------------------------------

/**
   circularlist_insert -- Insert data into an empty node. Create new node if
                          necessary.
   Parameters
       lnode -- A node apart of the list to be modified.
       data  -- A pointer to data of arbitrary type.
   Note
       Data must be malloc'd to heap prior to being passed as an argument.
 */
void
circularlist_insert(struct node **lnode, void *data);
// -----------------------------------------------------------------------------

/**
    circularlist_delete -- Deletes a node from the linked list. Data stored in
                           deleted node is freed first.
    Parameters
        remove -- The node to be deleted.
 */
void
circularlist_delete(struct node** remove);
// -----------------------------------------------------------------------------

/**
   circularlist_find -- Finds and returns a node using a function passed as an
                        argument (as the compare argument).
   Parameters
       lnode   -- A node apart of the list to be modified.
       query   -- data that is expected to be found in the linked list.
       compare -- function used to find query in linked list.
   Returns
       node containing query data.
   Note
       The node returned is determined when (*compare)(query, node->data)
       returns 0.

 */
struct node*
circularlist_find(struct node* lnode,
                  void* query,
                  int (*compare)(const void*, const void*));
// -----------------------------------------------------------------------------

/**
   circularlist_compare_strings -- A function to be used with circularlist_find
                                   (as the "compare" argument). Use when node
                                   data point to strings.
   Parameters
       s1, s2 -- strings
   Returns
       Follows same semantics as strcmp.
       < 0 when s1 appears before s2 in dictionary order.
       > 0 when s1 appears after s2 in dictionary order.
       = 0 when s1 and s2 are the same.
  */
int
circularlist_compare_strings(const void* s1, const void* s2);
// -----------------------------------------------------------------------------

/**
   circularlist_compare_integers -- A function to be used with circularlist_find
                                    (as the "compare" argument). Use when node
                                    data points to integers.
   Parameters
       p, q -- integers
   Returns
       0 when p == q
       1 when p != q
  */
int
circularlist_compare_integers(const void* p, const void* q);
// -----------------------------------------------------------------------------

/**
   circularlist_traverse -- A function that will apply the callback() function
                            on every element in the list.
   Parameters
       lnode    -- A node apart of the list to be traversed.
       callback -- function that is applied to each element of the list which
                   lnode is apart of.
  */
void
circularlist_traverse(struct node* lnode, void (*callback)(struct node*));
// -----------------------------------------------------------------------------

/**
   circularlist_print -- A function intended for use with circularlist_traverse,
                         which assumes each node's data points to a string.
   Parameters
       lnode    -- A node apart of a list.
  */
void
circularlist_print(struct node* lnode);
// -----------------------------------------------------------------------------

#endif // CIRCULAR_LINKED_LIST_H
