/*Qual a ordem de complexidade de tempo do
algoritmo dado abaixo?
*/


SOMA DE MATRIZES

 para i:=1,…,n faça       // n
  para j:=1,…,n faça      // n^2
    Cij:=aij + bij;       // 2n^2

// n + n^2 + 2n^2 = n + 3n^2
// O(n^2)
