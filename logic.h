#ifndef _LOGIC_H_
#define _LOGIC_H_


bool isOperator(char c);
bool isOperandeNbr(char c);

char priorityOperator(char c);

void infix_to_postfix(char *type_infixe, char *type_postfixe);

double calc_postfix(char *type_postfixe);
double calc_infixe(char *type_infixe);
double operation(double nombre1, double nombre2, char operator);

#endif