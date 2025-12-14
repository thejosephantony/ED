#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int num;
    int op;

    while(1){
        printf("Informe o numero que desejas saber a tabuada: \n");
        scanf("%d", &num);

        for(int i = 0; i <= 10; i++){
            printf("%d x %d = %d\n", num, i, num * i);
        }
        printf("Continuar?\n 1- Sim \n");
        scanf("%d", &op);
        if(op!= 1){
            break;
        }
    }
    return 0;
}
