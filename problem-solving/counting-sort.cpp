#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int count[N];
int tmp[N];
void countingSort(int *arr, int s, int e) {
  // count[e] = e; // for the test
  memset(count + s, 0, sizeof(int) * (e - s + 1));

  for (int i = s; i <= e; i++)
    count[arr[i]]++;
  for (int i = s + 1; i <= e; i++)
    count[i] += count[i - 1];

  for (int i = e; i >= s; i--) { // from the last
    tmp[--count[arr[i]]] = arr[i];
  }

  for (int i = s; i <= e; i++)
    arr[i] = tmp[i];
}

int comp(const void *a, const void *b) {
  int *pa = (int *)a;
  int *pb = (int *)b;

  return *pa - *pb;
}

int main() {
  time_t t1, t2;

  initArr(input, 0, N - 1);
  printf("My counting sort\n");
  t1 = clock();
  countingSort(input, 0, N - 1);
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
