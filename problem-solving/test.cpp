#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 50000

int input[MAX_N];

int binSearch(int* arr, int s, int e, int target) {
  int idx = -1;
  while (s <= e) {
    idx = (s + e) / 2;
    if (target == arr[idx]) return idx;
    else if (target > arr[idx]) s = idx + 1;
    else e = idx - 1;
  }

  return idx;
}

void randomizeArray(int s, int e) {
  // srand(time(NULL));
  for (int i = s; i < e; i++) {
    input[i] = rand() % 100;
  }
}

// [s, e) s는 닫힌구간(포함), e는 열린구간(미포함 )
void printArray(int s, int e, char* title = NULL, int gap = 1) {
  if ((e - s) > 100)
    return;

  if (title != NULL) {
    printf("%s ", title);
  }

  if (gap == 1) {
    for (int i = s; i < e; i += gap) {
      printf("%2d  ", input[i]);
    }
  } else {
    for (int i = s; i < e; i += gap) {
      printf("[%2d] %2d  ", i, input[i]);
    }
  }
  printf("\n");
}

void bubbleSort(int s, int e) {
  int tmp = -1, w = 0;
  for (int j = s; j < e; j++) {
    for (int i = s; i < e - 1 - w; i++) { // s가 0이 아닐 때를 위해 w변수 따로 둠(이미 정렬된 갯수)
      if (input[i] > input[i + 1]) {      //  -1은 i for문자체가 i+1과 비교하는 것이기 때문에 overflow 방지
        tmp = input[i];
        input[i] = input[i + 1];
        input[i + 1] = tmp;
      }
    }
    w++;
  }
}

void selectionSort(int s, int e) {
  int idx, val, tmp;

  for (int i = s; i < e; i++) {
    idx = i;
    val = input[i];

    for (int j = i + 1; j < e; j++) {
      if (input[j] < val) {
        idx = j;
        val = input[j];
      }
    }

    if (idx != i) {
      tmp = input[i];
      input[i] = input[idx];
      input[idx] = tmp;
    }
  }
}

void insertionSort(int s, int e) {
  int val, tmp, j;

  for (int i = s + 1; i < e; i++) { // 두번째 원소부터(첫번째 원소는 left가 없어서 무의미)
    val = input[i];

    for (j = i - 1; j >= s; j--) { // left 방향으로 진행하면서 크기 비교. 
      if (input[j] > val) {        //   val보다 크면 right방향으로 밀려나온다
        input[j + 1] = input[j];
      } else {
        break;
      }
    }
    input[j + 1] = val;            //   남은 빈자리에 비교값이었던 val이 들어간다

    /*
    for (j = i - 1; j >= s && input[j] > val; j--)
      input[j + 1] = input[j];
    input[j + 1] = val;
    */
  }
}

void insertionSort2(int s, int e, int gap = 1) {
  int val, tmp, j;

  // printArray(s, e, "    부분집합 before", gap);
  for (int i = s + gap; i < e; i += gap) { // 두번째 원소부터(첫번째 원소는 left가 없어서 무의미)
    val = input[i];

    for (j = i - gap; j >= s && input[j] > val; j -= gap)
      input[j + gap] = input[j];
    input[j + gap] = val;
  }
  // printArray(s, e, "    부분집합 after ", gap);
}

void shellSort(int s, int e) {
  // int k = 5;// 테스트용
  int k = (e - s) / 2;
  // int k = (e - s) / 3;
  if (k > 0 && k % 2 == 0) k++;

  while (k > 0) {
    // printf("\nk= %d\n", k);

    // printArray(s, e, "  ");
    for (int i = 0; i < k; i++) {
      insertionSort2(s + i, e, k);
    }
    // printArray(s, e, "  ");

    k = k / 2;
    if (k > 0 && k % 2 == 0) k++;
  }

}

void quickSort(int s, int e) {
  if (s >= e) return; // 유효범위 체크

  int tmp;
  int pi = (s + e) / 2;
  int pv = input[pi];

  // 피벗값을 맨 우측으로 옮겨놓자
  tmp = input[pi];
  input[pi] = input[e - 1];
  input[e - 1] = tmp;

  int leftIdx = s;
  for (int i = s; i < e - 1; i++) { // 피벗값인 원소를 제외한 나머지를 돌면서
    if (input[i] < pv) {            // 피벗값보다 작은 애들을 왼쪽부터 차례대로 세우자
      tmp = input[i];
      input[i] = input[leftIdx];
      input[leftIdx] = tmp;
      leftIdx++;
    }
  }

  // leftIdx가 피벗값의 위치가 됨
  tmp = input[leftIdx];
  input[leftIdx] = input[e - 1];
  input[e - 1] = tmp;

  quickSort(s, pi - 1); // 좌측 부분집합. 유효한 범위인지는 quickSort 함수 내에서 체크함
  quickSort(pi + 1, e); // 우측 부분집합. 유효한 범위인지는 quickSort 함수 내에서 체크함
}

int main() {
  clock_t t, t2;

  // // 바이너리서치 테스트
  // int data[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
  // int target;
  // printf("Input Number(10 ~ 19): ");
  // scanf("%d", &target);
  // t = clock();
  // int answer = binSearch(data, 0, sizeof(data) / sizeof(int) - 1, target);
  // printf("%d is on index [%d]\n");
  // scanf("elapsed time: %f\n", (clock() - t) / 1000.);


  int s = 3;
  int e = 50000;
  printf("index 범위: [%d, %d)\n", s, e);

  randomizeArray(0, e);
  // printArray(0, e);
  t = clock();
  bubbleSort(s, e);
  t2 = clock();
  printArray(0, e);
  printf("\n버블 정렬 걸린시간: %f\n", (t2 - t) / 1000.);

  randomizeArray(0, e);
  // printArray(0, e);
  t = clock();
  selectionSort(s, e);
  t2 = clock();
  printArray(0, e);
  printf("\n선택 정렬 걸린시간: %f\n", (t2 - t) / 1000.);

  randomizeArray(0, e);
  // printArray(0, e);
  t = clock();
  insertionSort(s, e);
  t2 = clock();
  printArray(0, e);
  printf("\n삽입 정렬 걸린시간: %f\n", (t2 - t) / 1000.);

  randomizeArray(0, e);
  // printArray(0, e);
  t = clock();
  shellSort(s, e);
  t2 = clock();
  printArray(0, e);
  printf("\n 쉘  정렬 걸린시간: %f\n", (t2 - t) / 1000.);

  randomizeArray(0, e);
  // printArray(0, e);
  t = clock();
  shellSort(s, e);
  t2 = clock();
  printArray(0, e);
  printf("\n 퀵  정렬 걸린시간: %f\n", (t2 - t) / 1000.);

  return 0;
}
