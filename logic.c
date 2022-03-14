#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "stack_char.h"
#include "stack_double.h"
#include "logic.h"

// Operateur aritmetic
bool isOperator(char c){
    return c == '+' || c == '-' || c == 'x' || c == '/' || c == '^';
}

//Verifie Number
bool isOperandeNbr(char c){
    return c >= '0' && c <= '9';
}

//Priorité Operateur
char priorityOperator(char c){

    if (c == '+' || c == '-')
        return '1';

    else if (c == 'x' || c == '/')
        return '2';

    else
        return '3';
}

//Fonction Infix To Postfix
void infix_to_postfix(char *type_infixe, char *type_postfixe){

    int capacity = strlen(type_infixe);

    stack_char operator;
    stack_char priority;
    stack_char resultat;

    stack_init(&operator, capacity);
    stack_init(&priority, capacity);
    stack_init(&resultat, capacity);

    for (int i = 0; i < capacity; i++){

        if (isOperandeNbr(type_infixe[i]))
            stack_push(&resultat, type_infixe[i]);

        else if (type_infixe[i] == '(' ){

            stack_push(&operator, '(' );
            stack_push(&priority, '0' );
        }

        else if (isOperator(type_infixe[i])){

            if (!stack_is_empty(operator)){

                char val;
                stack_peek(priority, &val);

                while (val >= priorityOperator(type_infixe[i])){

                    char tmp;
                    stack_pop(&operator, &tmp);
                    stack_push(&resultat, tmp);
                    stack_pop(&priority, &tmp);

                    if (!stack_is_empty(operator))
                        stack_peek(priority, &val);

                    else
                        val = '0';
                }//end while
            }//end if

            //Empiler Operator/priority/type infixe
            stack_push(&operator, type_infixe[i]);
            stack_push(&priority, priorityOperator(type_infixe[i]));
        }//end else if

        else if (type_infixe[i] == ')'){

            char val;
            stack_peek(operator, & val);

            while (val !=  '(' ){

                char tmp;
                stack_pop(&priority, &tmp);
                stack_pop(&operator, &tmp);
                stack_push(&resultat, tmp);
                stack_peek(operator, &val);
            }

            stack_pop(&operator, &val);
            stack_pop(&priority, &val);
        }
    }

    while (!stack_is_empty(operator)){

        char tmp;
        stack_pop(&operator, &tmp);
        stack_push(&resultat, tmp);
    }

    //Capacité de Resultat
    int sizeResultat = (resultat.top + 1) * 2;
    type_postfixe[sizeResultat] = '\0';

    for (int i = sizeResultat - 1; i >= 0; i -= 2){

        char val;
        stack_pop(&resultat, &val);
        type_postfixe[i] = ' ';
        type_postfixe[i - 1] = val;
    }

    //Vide les stacks
    stack_destroy(&operator);
    stack_destroy(&priority);
    stack_destroy(&resultat);
}


double calc_postfix(char *type_postfixe){

    int capacity = strlen(type_postfixe);
    stack_double operande;
    stack_double_init(&operande, capacity);

    for (int i = 0; i < capacity; i++){
        if (isOperandeNbr(type_postfixe[i]))
            stack_double_push(&operande, type_postfixe[i] - '0' );

        else if (type_postfixe[i] != ' ' ){

            double nombre1;
            double nombre2;
            stack_double_pop(&operande, &nombre2);
            stack_double_pop(&operande, &nombre1);
            double val = operation(nombre1, nombre2, type_postfixe[i]);
            stack_double_push(&operande, val);
        }
    }

    double result;
    stack_double_pop(&operande, &result);
    stack_double_destroy(&operande);
    return result;
}

double calc_infixe(char *type_infixe){

    char type_postfixe[strlen(type_infixe) * 2 + 1];
    infix_to_postfix(type_infixe, type_postfixe);
    double result = calc_postfix(type_postfixe);
    return result;
}

//Switch entre les cas
double operation(double nombre1, double nombre2, char operator){

    switch(operator) {

    case '+': return nombre1 + nombre2;
        break;
    case '-': return nombre1 - nombre2;
        break;
    case 'x': return nombre1 * nombre2;
        break;
    case '/': return nombre1 / nombre2;
        break;
    case '^': return pow(nombre1, nombre2);
        break;
    }
}