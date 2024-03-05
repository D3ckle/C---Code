
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//TODO:
//adds to end of the linkedlist
void push(stack *s, node *new_node)
{
    node *p = s->top;
    while(p->next!=NULL){
        p = p->next; //get last node
    }
    p->next = new_node; // point to new node to be added
}

//TODO:
node* pop(stack *s)
{
    node *p = s->top;
    while(p->next->next!=NULL){
        p = p->next;
    }
    p->next = NULL; //set second to last node to point to NULL, now last node in list
    free(p->next); //free node mem
	return p;
}

//TODO:
//checks if the stack is empyty or not
int empty(stack *s)
{
if (s == NULL){
    return 1; //true
}
return 0;
}

//TODO:
void clear_stack(stack *s)
{
    while(s != NULL){
        node *p = pop(s);
        free(p);
    }
}