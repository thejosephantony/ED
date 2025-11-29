#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *array, soma = 0;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = (int*)malloc(n * sizeof(int));  // aloca memoria

    if(array == NULL) {
        printf("Erro na alocação!\n");
        return 1;
    }


    printf("Digite %d números:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        soma += array[i];
    }

    printf("Soma: %d\n", soma);


    free(array);                 // libera memoria

    return 0;
}
