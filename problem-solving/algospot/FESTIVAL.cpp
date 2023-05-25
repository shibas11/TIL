#include <stdio.h>

#define MAX_C 100
#define MAX_N 1000
#define MAX_L 1000

int C, N, L;
int input_sum[MAX_N + 1] = { 0, };
double sum, answer, temp;

int main() {
    freopen("algospot/FESTIVAL.txt", "r", stdin);

    scanf("%d", &C);
    for (int c = 0; c < C; c++) {
        scanf("%d %d", &N, &L);
        for (int i = 1; i <= N; i++) {
            scanf("%d", input_sum + i);
            input_sum[i] += input_sum[i - 1]; // 1���� �����̰�, [0]���� 0�� ����־ ��������
        }

        answer = 1000000;
        for (int n = 1; n <= N - L + 1; n++) {
            for (int i = n; i <= N; i++) {
                if ((i - n + 1) < L)
                    continue;
                sum = input_sum[i] - input_sum[n - 1];
                temp = sum / (i - n + 1);
                if (temp < answer) answer = temp;
                //printf("%d %d %.11f\n", n, i, answer); // range�� ���� üũ
            }
        }
        printf("%.11f\n", answer);
    }

    return 0;
}
