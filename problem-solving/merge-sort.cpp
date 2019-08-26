#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int input[N];
int tmp[N];

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

void merge(int *arr, int s1, int e1, int s2, int e2) {
  int left = s1, right = s2;
  int idx = s1;
  while (left <= e1 && right <= e2) {
    if (arr[left] <= arr[right])
      tmp[idx++] = arr[left++];
    else
      tmp[idx++] = arr[right++];
  }

  while (left <= e1)
    tmp[idx++] = arr[left++];

  while (right <= e2)
    tmp[idx++] = arr[right++];

  for (int i = s1; i <= e2; i++)
    arr[i] = tmp[i];
}

void mergeSort(int *arr, int s, int e) {
  if (s >= e)
    return;

  int mid = (s + e) / 2;

  if (s < mid)
    mergeSort(arr, s, mid);
  if (mid + 1 < e)
    mergeSort(arr, mid + 1, e);

  merge(arr, s, mid, mid + 1, e);
}

int comp(const void *a, const void *b) {
  int *pa = (int *)a;
  int *pb = (int *)b;

  return *pa - *pb;
}

int main() {
  time_t t1, t2;

  initArr(input, 0, N - 1);
  printf("My merge sort\n");
  t1 = clock();
  mergeSort(input, 0, N - 1);
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
