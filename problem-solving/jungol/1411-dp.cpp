#include <stdio.h>

#define MAX_N 100000
#define MOD 20100529

int N;
int d[MAX_N + 1] = {0, 1, 3};

int dp_recursion(int n) {
  if (n <= 0)
    return 0;
  else if (d[n] > 0)
    return d[n];

  int d1 = dp_recursion(n - 1) % MOD;
  int d2 = dp_recursion(n - 2) % MOD;

  return d[n] = (d1 + 2 * d2) % MOD;
}

int dp_interation(int n) {
  if (n <= 0)
    return 0;
  else if (d[n] > 0)
    return d[n];

  for (int i = 3; i <= n; i++)
    d[i] = (d[i - 1] % MOD + (2 * d[i - 2]) % MOD) % MOD;

  return d[n];
}

int main() {
  // freopen("input.txt", "r", stdin);

  scanf("%d", &N);
  printf("%d", dp_interation(N));

  return 0;
}
