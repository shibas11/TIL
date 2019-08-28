#include <stdio.h>

#define MAX_N 200
#define MAX_M 1000

int input[MAX_N + 1][MAX_N + 1];
int city[MAX_N + 1];
int id[MAX_N + 1];
int lv[MAX_N + 1];
int query[MAX_M];

int N, M;

void initArr(int size, int querySize) {
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++)
      scanf("%d", &input[i][j]);

    city[i] = id[i] = i;
    lv[i] = 1;
  }

  for (int i = 0; i < querySize; i++)
    scanf("%d", &query[i]);
}

int root(int p) {
  while (p != id[p])
    p = id[p];

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

int main() {
  // freopen("acmicpc/1976-union-find.txt", "r", stdin);
  setbuf(stdout, NULL);

  scanf("%d", &N, &M);
  initArr(N, M);

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++)
      if (input[i][j])
        unionFunc(i, j);
  }

  bool result = true;
  for (int i = 0; i < M - 1; i++) {
    if (!isConnected(query[i], query[i + 1])) {
      result = false;
      break;
    }
  }

  if (result)
    printf("YES");
  else
    printf("NO");
}
