// Tester for linked list. Note that this does not test all the functionality
// you implemented; you should enhance it significantly. We will test your
// linked list code with a different main.c.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkedlist.h"
#include "value.h"

int main() {
    
    Value *val1 = malloc(sizeof(Value));
    val1->type = INT_TYPE;
    val1->i = 12;

    Value *val2 = malloc(sizeof(Value));
    val2->type = DOUBLE_TYPE;
    val2->d = 4.3;

    Value *val3 = malloc(sizeof(Value));
    val3->type = STR_TYPE;
    val3->s = "hello world";
    
    Value *val4 = malloc(sizeof(Value));
    val4->type = STR_TYPE;
    val4->s = "CS251";
    
    Value *head = makeNull();
    head = cons(val1,head);    
    head = cons(val2,head);
    head = cons(val3,head);
    head = cons(val4,head);

    display(head);
    
    Value *reverse_head = reverse(head);
    display(reverse_head);
    
    printf("Is Null original list? %d\n", isNull(head));
    printf("Is Null reverse list? %d\n", isNull(reverse_head));
    printf("Length of original list? %d\n", length(head));
    printf("Length of reverse list? %d\n", length(reverse_head));

    //test car
    Value *car_ptr = car(head);
    Value *car_reverse_ptr = car(reverse_head);
    
    // car(cdr(list)) works!
    printf("car(cdr(head)): ");
    display(car(cdr(head)));
    printf("\n");

    // car(cdr(cdr(list))) works!
    printf("car(car(cdr(head))): ");
    display(car(cdr(cdr(head))));
    printf("\n");
    
    cleanup(head);
    cleanup(reverse_head);
}
