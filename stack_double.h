#ifndef _STACK_DOUBLE_H_
#define _STACK_DOUBLE_H_

typedef struct _stack_double{

    int capacity;
    int top;
    double *data;

} stack_double;

void stack_double_init(stack_double *s, int capacity);

bool stack_double_is_empty(stack_double s);
bool stack_double_is_full(stack_double s);

void stack_double_push(stack_double *s, double val);
void stack_double_pop(stack_double *s, double *val);
void stack_double_peek(stack_double s, double *val);
void stack_double_destroy(stack_double *s);

#endif