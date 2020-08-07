#include <stdio.h>
#include <stdlib.h>

#define MAX_M 100
#define MAX_N 100

int M, N, K;
int input[MAX_M + 1][MAX_N + 1];

int answerCount;
int answer[MAX_N];

void printMap()
{
    for (int y = 0; y < M; y++)
    {
        for (int x = 0; x < N; x++)
        {
            printf("%d", input[y][x]);
        }
        printf("\n");
    }
}

int bfs(int y, int x, int cnt)
{
    cnt++;
    input[y][x] = 0;

    if (y - 1 >= 0 && input[y - 1][x])
        cnt = bfs(y - 1, x, cnt);

    if (y + 1 < M && input[y + 1][x])
        cnt = bfs(y + 1, x, cnt);

    if (x - 1 >= 0 && input[y][x - 1])
        cnt = bfs(y, x - 1, cnt);

    if (x + 1 < N && input[y][x + 1])
        cnt = bfs(y, x + 1, cnt);

    return cnt;
}

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return num1 - num2;
}

int main()
{
    freopen("acmicpc/2583-bfs.txt", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d %d %d", &M, &N, &K);

    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            input[y][x] = 1;

    int x1, y1, x2, y2;
    for (int k = 0; k < K; k++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int y = y1; y < y2; y++)
            for (int x = x1; x < x2; x++)
                input[y][x] = 0;
    }
    //printMap();

    int cnt = 0;
    answerCount = 0;
    for (int y = 0; y < M; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (input[y][x] == 1)
            {
                cnt = bfs(y, x, 0);
                answer[answerCount++] = cnt;
            }
        }
    }

    qsort(answer, answerCount, sizeof(int), compare);

    printf("%d\n", answerCount);
    for (int i = 0; i < answerCount; i++)
        printf("%d ", answer[i]);
}
