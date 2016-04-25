#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include "value.h"

// Create a new NULL_TYPE value node.
Value *makeNull(){
    Value *nulltype = malloc(sizeof(Value));
    nulltype->type = NULL_TYPE;
    return nulltype;
}

// Utility to check if pointing to a NULL_TYPE value. Use assertions to make sure
// that this is a legitimate operation.
bool isNull(Value *value){
    //assert(value->type);
    return (value->type == NULL_TYPE);
}

// Create a new CONS_TYPE value node.
Value *cons(Value *car, Value *cdr){ 
    Value *constype = malloc(sizeof(Value));
    constype->type = CONS_TYPE;
    constype->c.car = car;
    constype->c.cdr = cdr;
    return constype;
}

// Display the contents of the linked list to the screen in some kind of
// readable format
void display(Value *list){
    switch (list->type) {
        case (CONS_TYPE):
            display(list->c.car);
            display(list->c.cdr);
            break;
        case (INT_TYPE):
            printf("%i ", list->i);
            break;
        case (DOUBLE_TYPE):
            printf("%f ", list->d);
            break;
        case (STR_TYPE):
            printf("%s ", list->s);
            break;
        case (NULL_TYPE):
            printf("\n");
            break;
    }
}

Value *reverseHelper(Value *list, Value *newlist) {
    if (isNull(list)) {
        return newlist;
    } else {
        newlist = cons(list->c.car, newlist);
        return reverseHelper(list->c.cdr, newlist);
    }
}

// Return a new list that is the reverse of the one that is passed in. All
// content within the list should be duplicated; there should be no shared
// memory between the original list and the new one.
Value *reverse(Value *list){
    Value *newlist = makeNull();
    return reverseHelper(list, newlist);
}

// Frees up all memory directly or indirectly referred to by list.
void cleanup(Value *list){
    if (list->type == CONS_TYPE) {
        cleanup(list->c.car);
        cleanup(list->c.cdr);
        free(list);
    } else {
        free(list);
    }
}

// Utility to make it less typing to get car value. Use assertions to make sure
// that this is a legitimate operation.
Value *car(Value *list){
    Value *ptr = malloc(sizeof(Value));
    return ptr;
}

// Utility to make it less typing to get cdr value. Use assertions to make sure
// that this is a legitimate operation.
Value *cdr(Value *list){
    Value *ptr = malloc(sizeof(Value));
    return ptr;
}

// Measure length of list. Use assertions to make sure that this is a legitimate
// operation.
int length(Value *value){
    if (value->type == CONS_TYPE) {
        return length(value->c.cdr)+1;
    } else {
        return 0;
    }
}
