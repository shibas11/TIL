#include "stdio.h"
#include <queue>
using namespace std;

#define N 100

int COL, ROW;
int input[N][N];
int total;

queue<int> que;

void printArr(int r, int c) {
  printf("%d, %d\n", r, c);
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (r == i && c == j)
        printf("[%1d]", input[i][j]);
      else
        printf("%2d ", input[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  // freopen("input.txt", "r", stdin);

  scanf("%d %d", &COL, &ROW);
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      scanf("%1d", &input[i][j]);
      if (input[i][j])
        total++;
    }
  }
  int c, r, tmp, max = 0;
  scanf("%d %d", &c, &r);
  c--, r--; // index is started from 1(not 0)

  if (input[r][c] > 0) {
    input[r][c] = 3;
    que.push(r * COL + c);

    while (!que.empty()) {
      total--;
      tmp = que.front(), que.pop();
      r = tmp / COL, c = tmp % COL;
      max = max < input[r][c] ? input[r][c] : max;
      // printArr(r, c);

      if (r - 1 >= 0 && input[r - 1][c] == 1) {
        input[r - 1][c] = input[r][c] + 1;
        que.push((r - 1) * COL + c);
      }
      if (r + 1 < ROW && input[r + 1][c] == 1) {
        input[r + 1][c] = input[r][c] + 1;
        que.push((r + 1) * COL + c);
      }
      if (c - 1 >= 0 && input[r][c - 1] == 1) {
        input[r][c - 1] = input[r][c] + 1;
        que.push(r * COL + c - 1);
      }
      if (c + 1 < COL && input[r][c + 1] == 1) {
        input[r][c + 1] = input[r][c] + 1;
        que.push(r * COL + c + 1);
      }
    }
  }

  printf("%d\n%d\n", max, total);

  return 0;
}
