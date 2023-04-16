#include<stdio.h>
#include<stdlib.h>
#include "../Headers/linked_list.h"


/* Initializes the Linked List
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
 */
void init_single_linked_list(head *head)
{
   head -> top  = NULL;
}


/* Goes through and prints each element of the Linked List
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
 */
void traverse_list(head *head)
{
    node *current_node = head -> top;

    while(current_node != NULL)
    {
        printf("%d\t", current_node -> data);
        current_node = current_node -> next;
    }
    printf("\n");
}


/* Inserts an element at the start of the Linked List
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
    @param data The element to be inserted in the list
*/
void insert_start(head *head, int data)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = head -> top;
    head -> top = new_node;
}


/* Inserts an element at the end of the Linked List
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
    @param data The element to be inserted in the list
  */
void insert_end(head *head, int data)
{
    node *current_node  = head -> top;
    node *new_node = (node*) malloc(sizeof(node));    

    // If the list is empty
    if(current_node == NULL)
    {
        head -> top = new_node;
        new_node -> data = data;
        new_node -> next = NULL;
        return;
    }

    // keep moving untill reach the last node in the list
    while(current_node -> next != NULL)
    {
        current_node = current_node -> next;
    }

    // put the new node at the end of the list
    current_node -> next = new_node;
    new_node -> data = data;
    new_node -> next = NULL;
}


/* Inserts an element Before a specific element if this element is found
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
    @param data The element to be inserted in the list
    @param element The specific element we want to insert our data before  */
void insert_middle_before_element(head *head, int data, int element)
{

    node *current_node = head -> top;
    node *prev_node = NULL;
 
    if(current_node== NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if(current_node -> data == element)
    {
        node *new_node = (node*) malloc(sizeof(node));
        new_node -> data = data;
        new_node -> next = current_node;
        head -> top = new_node;
        return;
    }

    // If there's only one element in the list and it is the element we are looking for
    if(head -> top -> next == NULL && head -> top -> data == element)
    {
        insert_start(head, data);
        return;
    }

    // keep moving untill reach the end of the list or find the element
    while(current_node !=NULL && current_node -> data != element)
    {
        prev_node = current_node;
        current_node = current_node -> next;
    }

    // Reached the end of the list without finding the element
    if(current_node == NULL)
    {
        printf("Element doesn't exist!\n");
        return;
    }

    // put the new node between the currenta nd previous nodes
    // Note: we allocate the new node here instead of the begining of the function
    // in case we couldn't add this node so we don't allocate memory for nothing
    node *new_node = (node*) malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = current_node;
    prev_node -> next = new_node;
}


/* Inserts an element AFTER a specific element if this element is found
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
    @param data The element to be inserted in the list
    @param element The specific element we want to insert our data after  */
void insert_middle_after_element(head *head, int data, int element)
{
    node *current_node = head -> top;

    if(current_node == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // keep moving untill reach the end of the list or find the element
    while(current_node != NULL && current_node -> data != element)
    {
        current_node = current_node -> next;
    }

    // Reached the end of the list without finding the element
    if(current_node == NULL)
    {
        printf("Element doesn't exist!\n");
        return;
    }

    // Add the new node in the list after the current node
    // Note: we allocate the new node here instead of the begining of the function
    // in case we couldn't add this node so we don't allocate memory for nothing
    node *new_node = (node *) malloc(sizeof(node));
    new_node -> data = data;
    new_node -> next = current_node -> next;
    current_node -> next = new_node;
}


/* Deletes the first element from the linked list
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
*/
void delete_start(head *head)
{
    node *current_node = head -> top;

    if(current_node == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    head -> top = current_node -> next;

    free(current_node);
}


/* Deletes the last element from the linked list
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
*/
void delete_end(head *head)
{
    node *current_node = head -> top;

    if(current_node == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // If there's only one element
    if(current_node -> next == NULL)
    {
        head -> top = NULL;
        free(current_node);
        return;
    }

    // keep moving till we reach the element before the last element
    while(current_node -> next -> next != NULL)
    {
        current_node = current_node -> next;
    }

    // temporarly node pointer to free the memory allocated by the node that will be removed which is 
    // the last element
    node *temp = current_node -> next;

    current_node -> next = NULL;

    free(temp);
}


/* Deletes a specific element from the linked list if this element is found
    @param *head The head of the linked list aka has "top which points at the first node in the linked list"
    @param element The element to be removed from the list*/
void delete_middle(head *head, int element)
{
    node *current_node = head -> top;
    node *prev_node = NULL;

    if(current_node == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // If the element we want to delete is the first element
    if(current_node -> data == element)
    {
        head -> top = current_node -> next;
        free(current_node);
        return;
    }

    // Keep moving to the next element untill rach the end of the list or find the element
    while(current_node != NULL && current_node -> data != element)
    {
        prev_node = current_node;
        current_node = current_node -> next;
    }

    // If end of the list is rached without finding the element
    if(current_node == NULL)
    {
        printf("Element not found!\n");
        return;
    }

    // remove the node and link the two elements before and after the node
    prev_node -> next = current_node -> next;

    free(current_node);

}