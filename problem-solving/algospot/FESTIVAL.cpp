#include <stdio.h>

#define MAX_N 1000
#define MAX_C 100

int C, N, L;
int input[MAX_N];
int d[MAX_N][MAX_N];
float tmp;

int main() {
//   freopen("algospot/FESTIVAL.txt", "r", stdin);

  double answer, tmp;

  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    answer = 100000;

    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
      scanf("%d", input + i);
      d[i][i] = input[i];
    }

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        d[i][j] = d[i][j - 1] + input[j];
      }
    }

    for (int i = 0; i <= N - L; i++) {
      for (int j = i + L - 1; j < N; j++) {
        tmp = (double)d[i][j] / (j - i + 1);
        answer = tmp < answer ? tmp : answer;
      }
    }

    printf("%.12f\n", answer);
  }

  return 0;
}
