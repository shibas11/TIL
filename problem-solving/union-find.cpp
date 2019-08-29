#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10000000

int N = 10;
int QUERY = 12;
int input[MAX_N];
int id[MAX_N];
int lv[MAX_N];

int root(int p) {
  while (p != id[p]) {
    id[p] = id[id[p]]; // path compression
    p = id[p];
  }

  return p;
}

bool isConnected(int p, int q) { return root(p) == root(q); }

void unionFunc(int p, int q) {
  if (isConnected(p, q))
    return;

  int pRoot = root(p);
  int qRoot = root(q);

  if (lv[pRoot] >= lv[qRoot]) { // p is parent
    id[qRoot] = pRoot;
    if (lv[pRoot] == lv[qRoot])
      lv[pRoot]++;
  } else { // q is parent
    id[pRoot] = qRoot;
  }
}

void initArr(int size) {
  for (int i = 0; i < size; i++) {
    input[i] = i;
    id[i] = i;
    lv[i] = 1;
  }
}

void printArr(int size) {
  for (int i = 0; i < size; i++) {
    printf("[%3d]%3d, id:%3d, root:%d\n", i, input[i], id[i], root(i));
  }
  printf("\n");
}

int main() {
  freopen("union-find.txt", "r", stdin);
  scanf("%d %d\n", &N, &QUERY);

  initArr(N);
  printArr(N);

  char command;
  int a, b;

  time_t t = clock();
  for (int i = 0; i < QUERY; i++) {
    scanf("%c %d %d\n", &command, &a, &b);
    if (command == 'u')
      unionFunc(a, b);
    else if (command == 'c')
      printf("%d\n", isConnected(a, b));
    printArr(N);
  }
  printf("elapsed time: %.3f\n", (clock() - t) / 1000.);

  return 0;
}
