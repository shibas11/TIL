#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int input[N];

void initArr(int *arr, int s, int e) {
  srand(time(NULL));
  for (int i = 0; i < N; i++)
    arr[i] = rand() % N;
}

void printArr(int *arr, int s, int e) {
  for (int i = s; i <= e; i++) {
    printf("%2d ", arr[i]);
  }
  printf("\n\n");
}

bool validate(int *arr, int s, int e) {
  for (int i = s; i < e; i++) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

void quickSort(int *arr, int s, int e) {
  if (s >= e)
    return;

  int tmp;
  int pi = (s + e) / 2;
  int pv = arr[pi];

  tmp = arr[pi];
  arr[pi] = arr[e];
  arr[e] = tmp;

  int idx = s;
  for (int i = s; i < e; i++) {
    if (arr[i] < pv) {
      tmp = arr[i];
      arr[i] = arr[idx];
      arr[idx++] = tmp;
    }
  }

  tmp = arr[idx];
  arr[idx] = arr[e];
  arr[e] = tmp;

  if (s < idx - 1)
    quickSort(arr, s, idx - 1);
  if (idx + 1 < e)
    quickSort(arr, idx + 1, e);
}

int comp(const void *a, const void *b) {
  int *pa = (int *)a;
  int *pb = (int *)b;

  return *pa - *pb;
}

int main() {
  time_t t1, t2;

  initArr(input, 0, N - 1);
  printf("My quick sort\n");
  t1 = clock();
  quickSort(input, 0, N - 1);
  t2 = clock();
  printf("elapsed time: %.3f\n", (t2 - t1) / 1000.);
  printf("isValid? %d\n\n", validate(input, 0, N - 1));

  initArr(input, 0, N - 1);
  printf("Original quick sort in stdlib\n");
  t1 = clock();
  qsort(input, N, sizeof(int), comp);
  t2 = clock();
  printf("elapsed time: %.3f\n", (t2 - t1) / 1000.);
  printf("isValid? %d\n\n", validate(input, 0, N - 1));

  return 0;
}
