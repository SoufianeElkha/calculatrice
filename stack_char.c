#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#include "stack_char.h"

//Initialisation d’une pile:
void stack_init(stack_char *s, int capacity){

    s->capacity = capacity;
    s->top = -1;
    s->data = malloc(capacity * sizeof(char));
}

//Vérifie si la pile est vide:
bool stack_is_empty(stack_char s){
    return s.top == -1;
}

//Vérifie si la pile est full:
bool stack_is_full(stack_char s){
    return s.top == s.capacity - 1;
}

//Empile un élément au sommet:
void stack_push(stack_char *s, char val){

    if (stack_is_full(*s))
        assert(!stack_is_full(*s));

    else{
        s->top++;
        s->data[s->top] = val;
    }
}

//Dépile un élément du sommet:
void stack_pop(stack_char *s, char *val)
{
    if (stack_is_empty(*s))
        assert(!stack_is_empty(*s));

    else{
        *val = s->data[s->top];
        s->top--;
    }
}

//Jette un oeil au sommet:
void stack_peek(stack_char s, char *val)
{
    if (stack_is_empty(s))
        assert(!stack_is_empty(s));
    
    else
        *val = s.data[s.top];
}

//Désalloue la mémoire de la pile et met data à NULL, ainsi que la taille et le sommet à -1
void stack_destroy(stack_char *s){

    s->capacity = -1;
    s->top = -1;
    free(s->data);
    s->data = NULL;
}