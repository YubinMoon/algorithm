#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(void)
{
    int n, num, tmp, end = 1;
    int arr[10001];
    arr[1] = 1;
    while (scanf("%d", &n) != EOF)
    {
        if (n > end)
        {
            num = arr[end];
            for (int i = end; i < n; i++)
            {
                tmp = num * (i + 1);
                while (!(tmp % 10))
                    tmp = tmp / 10;
                tmp = tmp % 100000;
                arr[i + 1] = tmp;
                num = arr[i + 1];
            }
        }
        printf("%5d -> %d\n", n, arr[n] % 10);
    }
}