#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 12
#define N 10000000

#define HEAP_ROOT 1

int sample[M + 1] = {-1, 10, 4, 8, 5, 12, 2, 6, 11, 3, 9, 7, 1};
int input[N + 1];

void initArr(int *arr, int s, int e) {
  srand(time(NULL));
  for (int i = 0; i <= e; i++)
    arr[i] = rand() % N;
}

void printArr(int *arr, int s, int e) {
  for (int i = s; i <= e; i++)
    printf("%2d ", arr[i]);
  printf("\n");
}

bool validate(int *arr, int s, int e) {
  for (int i = s; i < e; i++) {
    if (arr[i] > arr[i + 1]) {
      printf("[%d]%d > [%d]%d\n", i, arr[i], i + 1, arr[i + 1]);
      return false;
    }
  }
  return true;
}

void createMaxHeap(int *arr, int s, int e) {
  int idx, tmp;
  for (int i = s; i <= e; i++) {
    idx = i;
    while (idx > HEAP_ROOT && arr[idx] > arr[idx / 2]) {
      tmp = arr[idx];
      arr[idx] = arr[idx / 2];
      arr[idx / 2] = tmp;
      idx /= 2;
    }
  }
}

void heapSort(int *arr, int s, int e) {
  int tmp, idx, childIdx, childVal;
  while (s <= e) {
    tmp = arr[s];
    arr[s] = arr[e];
    arr[e--] = tmp;

    idx = s;
    while (idx * 2 <= e) {
      childIdx = idx * 2;
      if (idx * 2 + 1 <= e && arr[idx * 2] < arr[idx * 2 + 1]) {
        childIdx = idx * 2 + 1;
      }
      if (arr[idx] >= arr[childIdx])
        break;

      tmp = arr[idx];
      arr[idx] = arr[childIdx];
      arr[childIdx] = tmp;

      idx = childIdx;
    }
  }
}

int comp(const void *a, const void *b) {
  int *pa = (int *)a;
  int *pb = (int *)b;

  return *pa - *pb;
}

int main() {
  printf("Sample heap sort\n");
  printArr(sample, 1, M); // 10  4  8  5 12  2  6 11  3  9  7  1
  createMaxHeap(sample, 1, M);
  printArr(sample, 1, M); // 12 11  8 10  9  2  6  4  3  5  7  1
  heapSort(sample, 1, M);
  printArr(sample, 1, M); //  1  2  3  4  5  6  7  8  9 10 11 12
  printf("isValid? %d\n\n", validate(sample, 1, M));

  time_t t1, t2;

  printf("My heap sort\n");
  initArr(input, 1, N);
  t1 = clock();
  createMaxHeap(input, 1, N);
  t2 = clock();
  printf("createMaxHeap elapsed time: %.3f\n", (t2 - t1) / 1000.);

  t1 = clock();
  heapSort(input, 1, N);
  t2 = clock();
  printf("elapsed time: %.3f\n", (t2 - t1) / 1000.);
  printf("isValid? %d\n\n", validate(input, 1, N));

  printf("Original quick sort in stdlib\n");
  initArr(input, 1, N);
  t1 = clock();
  qsort(input + 1, N, sizeof(int), comp);
  t2 = clock();
  printf("elapsed time: %.3f\n", (t2 - t1) / 1000.);
  printf("isValid? %d\n\n", validate(input, 1, N));

  return 0;
}
