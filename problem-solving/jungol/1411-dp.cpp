#include <stdio.h>

#define MAX_N 100000
#define NUM 20100529
int N;
int d[MAX_N] = {0, 1, 3};

int dp(int n) {
  if (n <= 0)
    return 0;
  if (d[n] > 0)
    return d[n];

  int d1 = dp(n - 1);
  int d2 = dp(n - 2);

  return d[n] = d1 + 2 * d2;
}

int main() {
  // freopen("input.txt", "r", stdin);

  scanf("%d", &N);
  printf("%d", dp(N));
  
  return 0;
}
