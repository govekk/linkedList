/*
* Tom Choi, Kiya Govek, Jonah Tuchow
* Implementation of linked lists in c,
* mimicing structure of cons cells,
* and allowing different types in the same list
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linkedlist.h"
#include "value.h"

// Create a new NULL_TYPE value node.
Value *makeNull(){
    Value *nulltype = malloc(sizeof(Value));
    nulltype->type = NULL_TYPE;
    return nulltype;
}

// Helper method that creates a separate copy of Value struct
// in order not to share the same memory between the original and new one.
Value *copy_Value(Value *val){
    Value *val_copy = malloc(sizeof(Value));
    switch (val->type) {
        case(NULL_TYPE):
            val_copy->type = NULL_TYPE;
            break;
        case(CONS_TYPE):
            printf("constype\n");
            val_copy->type = CONS_TYPE;
            val_copy->c.car = copy_Value(car(val));
            val_copy->c.cdr = copy_Value(cdr(val));
            break;
        case (INT_TYPE):
            val_copy->type = INT_TYPE;
            val_copy->i = val->i;
            break;
        case (DOUBLE_TYPE):
            val_copy->type=DOUBLE_TYPE;
            val_copy->d = val->d;
            break;
        case (STR_TYPE):
            val_copy->type = STR_TYPE;
            val_copy->s = val->s;
            break;
    }
    return val_copy;
}

// Utility to check if pointing to a NULL_TYPE value. Use assertions to make sure
// that this is a legitimate operation.
bool isNull(Value *value){
    assert(value);
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

// Performs recursive step of reverse process
Value *reverseHelper(Value *list, Value *newlist) {
    assert(isNull(list) || list->type == CONS_TYPE);
    if (isNull(list)) {
        return newlist;
    } else {
        newlist = cons(copy_Value(car(list)), newlist);
        return reverseHelper(cdr(list), newlist);
    }
}

// Return a new list that is the reverse of the one that is passed in.
Value *reverse(Value *list){
    Value *newlist = makeNull();
    newlist = reverseHelper(list, newlist);
    return newlist;
}

// Frees up all memory directly or indirectly referred to by list.
void cleanup(Value *list){
    if (list->type == CONS_TYPE) {
        cleanup(list->c.car);
        cleanup(list->c.cdr);
        free(list);
    }else{
        free(list);
    }
}

// Utility to make it less typing to get car value.
Value *car(Value *list){
    assert(list);
    assert(list->type == CONS_TYPE);
    return (list->c.car);
}

// Utility to make it less typing to get cdr value.
Value *cdr(Value *list){
    assert(list);
    assert(list->type == CONS_TYPE);
    return (list->c.cdr);
}

// Measure length of list.
int length(Value *value){
    assert(value);
    if (value->type == CONS_TYPE) {
        return length(value->c.cdr)+1;
    } else {
        return 0;
    }
}
