/* Escreva um programa que declare um inteiro, um real e um char, e ponteiros para in
teiro, real, e char. Associe as vari´ aveis aos ponteiros (use &). Modifique os valores de
cada vari´ avel usando os ponteiros. Imprima os valores das vari´ aveis antes e ap´ os a
modificac¸˜ ao. */

#include <stdio.h>
#include <stdlib.h>


int main(){

    int x = 10;
    double y = 24.2;
    char c = 'j';

    int *p1;
    double *p2;
    char *p3;

    p1 = &x;
    p2 = &y;
    p3 = &c;

    printf("O valor do inteiro antes da modificacao: %d\n", *p1);
    printf("O valor do float antes da modificacao: %f\n", *p2);
    printf("O valor do char antes da modificacao: %c\n", *p3);

    *p1 = 2;
    *p2 = 11.24;
    *p3 = 'z';

    printf("O valor do inteiro apos a modificacao: %d\n", *p1);
    printf("O valor do float apos a modificacao: %f\n", *p2);
    printf("O valor do char apos a modificacao: %c\n", *p3);

    printf("Endereco de x: %p\n", (void*)p1);
    printf("Endereco de y: %p\n", (void*)p2);
    printf("Endereco de c: %p\n", (void*)p3);


    return 0;

}
