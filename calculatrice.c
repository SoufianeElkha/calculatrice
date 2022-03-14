/*  
    Soufiane El kharmoudi
    TP_Calculatrice
    14.03.2021

*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "stack_char.h"
#include "stack_double.h"
#include "logic.h"

int main(){

        //Postfixe
        char *type_infixe = "(3+2)x4";
        char type_postfixe[strlen(type_infixe) * 2 + 1];
        infix_to_postfix(type_infixe, type_postfixe);
        printf("Infixe  : %s\nPostfixe: %s\n", type_infixe, type_postfixe);

        //Infixe
        char *expression = "(3+2)x4";
        printf("%s = %lf\n", expression, calc_infixe(expression));

    return 0;

}
