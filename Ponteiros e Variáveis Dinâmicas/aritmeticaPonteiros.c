#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int array[5] = {0,5,10,15,20};
    int *ptr = array;

    for(int i = 0; i < 5; i++){
        printf("Array[%d] = %d, endereco %p\n", i, *(ptr + i), ptr + i);
    }
    return 0;



}
