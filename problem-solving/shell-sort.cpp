#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000

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

void insertionSort(int *arr, int s, int e, int gap) {
  int tmp, val, j;
  for (int i = s + gap; i <= e; i += gap) {
    val = arr[i];
    for (j = i - gap; j >= s; j -= gap) {
      if (arr[j] <= val)
        break;
      arr[j + gap] = arr[j];
    }
    arr[j + gap] = val;
  }
}

void shellSort(int *arr, int s, int e, int gap) {
  for (int i = s; i < s + gap; i++) {
    insertionSort(arr, i, e, gap);
  }

  if (gap <= 1)
    return;

  gap = gap / 3 + 1;
  shellSort(arr, s, e, gap);
}

void shellSort2(int *arr, int s, int e) {
  int gap = (e - s + 1) / 3 + 1;

  while (gap > 1) {
    for (int i = 0; i < gap; i++) {
      insertionSort(arr, i, e, gap);
    }
    gap = gap / 3 + 1;
  }
  insertionSort(arr, s, e, 1); // gap == 1
}

int comp(const void *a, const void *b) {
  int *pa = (int *)a;
  int *pb = (int *)b;

  return *pa - *pb;
}

int main() {
  time_t t1, t2;

  initArr(input, 0, N - 1);
  printf("My insertion sort\n");
  t1 = clock();
  insertionSort(input, 0, N - 1, 1);
  t2 = clock();
  printf("elapsed time: %.3f\n", (t2 - t1) / 1000.);
  printf("isValid? %d\n\n", validate(input, 0, N - 1));

  initArr(input, 0, N - 1);
  printf("My shell sort\n");
  t1 = clock();
  shellSort(input, 0, N - 1, N / 3 + 1);
  t2 = clock();
  printf("elapsed time: %.3f\n", (t2 - t1) / 1000.);
  printf("isValid? %d\n\n", validate(input, 0, N - 1));

 initArr(input, 0, N - 1);
  printf("My shell sort2\n");
  t1 = clock();
  shellSort2(input, 0, N - 1);
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
