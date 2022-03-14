#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#include "stack_double.h"

//Initialisation d’une pile:
void stack_double_init(stack_double *s, int capacity){
    s->capacity = capacity;
    s->top = -1;
    s->data = malloc(capacity * sizeof(double));
}

//Vérifie si la pile est vide:
bool stack_double_is_empty(stack_double s){
    return s.top == -1;
}

//Vérifie si la pile est full:
bool stack_double_is_full(stack_double s){
    return s.top == s.capacity - 1;
}

//Empile un élément au sommet:
void stack_double_push(stack_double *s, double val){

    if (stack_double_is_full(*s))
        assert(!stack_double_is_full(*s));

    else{
        s->top++;
        s->data[s->top] = val;
    }
}


//Dépile un élément du sommet:
void stack_double_pop(stack_double *s, double *val){

    if (stack_double_is_empty(*s))
        assert(!stack_double_is_empty(*s));

    else{
        *val = s->data[s->top];
        s->top--;
    }
}

//Jette un oeil au sommet:
void stack_double_peek(stack_double s, double *val){

    if (stack_double_is_empty(s))
        assert(!stack_double_is_empty(s));
    else
        *val = s.data[s.top];
}

//Désalloue la mémoire de la pile et met data à NULL, ainsi que la taille et le sommet à -1
void stack_double_destroy(stack_double *s){

    s->capacity = -1;
    s->top = -1;
    free(s->data);
    s->data = NULL;
}