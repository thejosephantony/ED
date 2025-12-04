 void bubble_sort(int array[], int n) {
  for (int i = 0; i < n - 1; i++) {         // (1, n + 1, n-1)
    for (int j = 0; j < n - i - 1; j++) {   //(n-1, n(n - 1)/2 + (n - 1), n(n - 1)/2)
      if (array[j] > array[j + 1]) {        //n(n - 1)/2
        int temp = array[j];                //n(n - 1)/2
        array[j] = array[j + 1];            //n(n - 1)/2
        array[j + 1] = temp;}}}             // n(n - 1)/2
 }

 // O(n^2)
