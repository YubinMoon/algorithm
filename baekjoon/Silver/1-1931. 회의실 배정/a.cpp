#include <stdio.h>
#include <stdlib.h>

// 정렬 비교 함수
int compare(const void *a, const void *b);

int main()
{
    // 입력
    int N;
    scanf("%d", &N);
    int **tickets = (int **)malloc(sizeof(int *) * N);

    for (int i = 0; i < N; i++)
    {
        tickets[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &tickets[i][0], &tickets[i][1]);
    }

    // 정렬
    qsort(tickets, N, sizeof(int *), compare);

    int end = tickets[0][1];
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        int n_start = tickets[i][0];
        int n_end = tickets[i][1];

        if (end <= n_start) // 새로운 티켓 추가
        {
            end = n_end;
            count++;
        }
        else if (end > n_end) // 기존 티켓 변경
        {
            end = n_end;
        }
    }

    printf("%d\n", count);
}

int compare(const void *a, const void *b)
{
    int *num1 = *(int **)a;
    int *num2 = *(int **)b;

    if (num1[0] == num2[0])
    {
        return num1[1] - num2[1];
    }
    else
    {
        return num1[0] - num2[0];
    }
}