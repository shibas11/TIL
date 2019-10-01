#include <stdio.h>

#define MAX_N 1000
#define MAX_C 100

int C, N, L;
int input[MAX_N + 1] = {0};
int d[MAX_N + 1];
float tmp;

int main() {
  freopen("algospot/FESTIVAL.txt", "r", stdin);
  double answer, tmp;

  scanf("%d", &C);
  while (C--) {
    answer = 100000;

    scanf("%d %d", &N, &L);
    for (int i = 1; i <= N; i++) {
      scanf("%d", input + i);
      d[i] = d[i - 1] + input[i];
    }

    for (int i = 1; i <= N - L + 1; i++) {
      for (int j = i + L - 1; j <= N; j++) {
        tmp = (double)(d[j] - d[i] + input[i]) / (j - i + 1);
        answer = tmp < answer ? tmp : answer;
      }
    }

    printf("%.12f\n", answer);
  }

  return 0;
}
