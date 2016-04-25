// Tester for linked list. Note that this does not test all the functionality
// you implemented; you should enhance it significantly. We will test your
// linked list code with a different main.c.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "value.h"

int main() {
    Value *val1 = malloc(sizeof(Value));
    val1->type = INT_TYPE;
    val1->i = 12;

    Value *val2 = malloc(sizeof(Value));
    val2->type = DOUBLE_TYPE;
    val2->d = 4.3;

    Value *head = makeNull();
    printf("Length of null list = %d\n",length(head));
    printf("Is null? Should be 1: %d\n",isNull(head));
    
    head = cons(val1,head);
    printf("car of head: %d\n", head->c.car->i);
    printf("Is null? Should be 0: %d\n",isNull(head));
    
    head = cons(val2,head);
    display(head);
    printf("Length of size 2 list = %d\n",length(head));

/*
    printf("Empty? %i\n",isNull(head));
*/
    cleanup(head);
}
