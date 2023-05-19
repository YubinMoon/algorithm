#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_LEN 100001
#define MAX_INT 1000000007

int main(void)
{
    int n, m, erase = 0, max_b = 0;
    int t, t1, t2;
    int bit = 0, t_bit = 0;
    int A[MAX_LEN];
    int CA[MAX_LEN];
    int CB[7] = {0};

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", A + i);
        CA[i] = A[i] % 7 + 7; // 전처리용
        t = (7 - (A[i] % 7)) % 7;
        bit = bit | (1 << t); // B에 대응하는 값
    }

    t = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &t2);
        t1 = (t + t2) % 7;
        t_bit = bit & (~(1 << t1)); // 제거한 뒤의 배열 상태
        if (t_bit) // 배열이 비지 않으면
        {
            t = t1;
            bit = t_bit;
            CB[t] += t2;
            CB[t] %= MAX_INT;
        }
    }

    // 최소값으로 값 제거
    for (int i = 0; i < 7; i++)
    {
        if (CB[i])
        {
            erase = 0;
            for (int j = 0; j < n; j++)
            {
                t = CA[j] + i * (CA[j] != 0);
                t %= 7;
                CA[j] = CA[j] * (t != 0);
                erase += (t == 0);
            }
            max_b += CB[i];
            max_b %= MAX_INT;
        }
    }

    printf("%d\n", n - erase);
    for (int i = 0; i < n; i++)
    {
        if (!CA[i])
            continue;
        A[i] += max_b;
        A[i] %= MAX_INT;
        printf("%d ", A[i]);
    }
    printf("\n");
}