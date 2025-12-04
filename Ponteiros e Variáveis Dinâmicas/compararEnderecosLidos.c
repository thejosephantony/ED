/*. Escreva um programa que contenha duas vari´ aveis inteiras. Leia essas vari´ aveis do
 teclado. Em seguida, compare seus enderec¸os e exiba o conte´udo do maior endereco */


 #include <stdio.h>

int main(){
    int x;
    int y;

    int *ptr1;
    int *ptr2;

    printf("Digite o valor de x: \n");
    scanf("%d", &x);
    printf("Digite o valor de y: \n");
    scanf("%d", &y);

    ptr1 = &x;
    ptr2 = &y;

    if (ptr1 > ptr2){
            printf("ptr1 de x eh maior: %p \n", ptr1);
            printf("O conteudo desse endereco: %d\n", *ptr1);
    }
    else{
        printf("ptr2 de y eh maior: %p\n", ptr2);
        printf("O conteudo desse endereco: %d\n", *ptr2);

    }

    return 0;

}
