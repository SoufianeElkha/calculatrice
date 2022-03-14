#ifndef _STACK_CHAR_H_
#define _STACK_CHAR_H_

typedef struct _stack_char{

    int capacity;
    int top;
    char *data;

} stack_char;

void stack_init(stack_char *s, int capacity);

bool stack_is_empty(stack_char s);
bool stack_is_full(stack_char s);

void stack_push(stack_char *s, char val);
void stack_pop(stack_char *s, char *val);
void stack_peek(stack_char s, char *val);
void stack_destroy(stack_char *s);

#endif