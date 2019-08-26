#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <queue>
using namespace std;

#define N 10000000
#define K 10
#define P 3

int input[N];

void initArr(int *arr, int s, int e) {
  srand(time(NULL));
  int p = pow(K, P - 1);
  for (int i = 0; i < N; i++)
    arr[i] = rand() % p;
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

queue<int> que[K];
void radixSort(int *arr, int s, int e, int p) {
  int pow = 1, idx;

  for (int i = 1; i <= p; i++) {
    for (int j = 0; j < N; j++) {
      que[arr[j] / pow % K].push(arr[j]);
    }

    idx = 0;
    for (int j = 0; j < K; j++) {
      while (!que[j].empty()) {
        arr[idx++] = que[j].front();
        que[j].pop();
      }
    }
    pow *= K;
  }
}

int comp(const void *a, const void *b) {
  int *pa = (int *)a;
  int *pb = (int *)b;

  return *pa - *pb;
}

int main() {
  time_t t1, t2;

  initArr(input, 0, N - 1);
  printf("My radix sort\n");
  t1 = clock();
  radixSort(input, 0, N - 1, P);
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
