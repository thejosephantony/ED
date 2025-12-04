/* Escreva um programa que contenha duas vari´ aveis inteiras. Compare seus enderec¸os e
 exiba o maior endereco */

 #include <stdio.h>

 int main(){
    int x = 10;
    int y = 20;

    void *p1;
    void *p2;

    p1 = &x;
    p2 = &y;

    if(p1 > p2){
        printf("O endereco de p1 eh maior: %p\n", p1);
    }
    else{
        printf("O endereco de p2 eh maior: %p\n", p2);
    }

    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);

    return 0;
 }
