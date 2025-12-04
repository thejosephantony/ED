int soma_elementos(int array[], int n) {
    int soma = 0;                      // 1
    for (int i = 0; i < n; i++) {      // (1, (n+1), n)
        soma += array[i];              // n
    }
    return soma;                       // 1
 }
 // 1 + (n+1 + 1 + n + n) + 1 = 3n + 3
 // O(n)
