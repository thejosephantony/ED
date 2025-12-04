#include <stdio.h>

int i, j, k;

for (i = 0; i < N; i++) {        // 1 + n + 1 + n = 2 + 2n
    for (j = 0; j < N; j++) {    // n + n + n^2 + n^2 = 2n + 2n^2
        for (k = 0; k < N; k++) { // n^2(1 + n + 1 + n) = 2n^2 + 3n^3
            R[i][j] += A[i][k] * B[k][j];
    }
}


int i , j ,s;
s = 0;                   //  1
for( i=1; i <N -1; i++){  // 1 + n - 1 + n = 2n
 for( j=1; j <2N; j++){  // n(1 + 1 + 2n + n) = n(1 + 3n) = n + 3n^2
  s = s + 1;             // n^2
  }
  }

