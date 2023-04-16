#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct head 
{
    struct node *top;
}head;

void init_single_linked_list(head *);
void traverse_list(head *);
void insert_start(head *, int);
void insert_end(head *, int);
void insert_middle_before_element(head *, int, int);
void insert_middle_after_element(head *, int, int);
void delete_start(head *);
void delete_end(head *);
void delete_middle(head *, int);



#endif