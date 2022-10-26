#include <stdio.h>

int* merge(int* a, int mid, int length) {
  int b[length];
  int i = 0;
  int j = 0;
  int k = mid;

  while (i < length) {
    if (k >= length || j < mid && a[j] <= a[k]) {
      b[i++] = a[j++];
    } else {
      b[i++] = a[k++]; 
    }
  }

  //for (int i = 0; i < length; i++) a[i] = b[i];

  return b;
}

void merge_sort(int* a, int length) {
  int mid = length / 2;

  if (mid == 0) return;

  merge_sort(a, mid);
  merge_sort(a + mid, length - mid);

  int* b = merge(a, mid, length); 

  for (int i = 0; i < length; i++) a[i] = b[i];
}

int main() {
  int a[5] = {3, 2, 4, 1, 5};
  merge_sort(a, 5);

  for (int i = 0; i < 5; i++) printf("%d,", a[i]);
  printf("\n");
  return 0;
}
