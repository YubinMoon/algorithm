#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

int get_diff(int n, int *stat, int bitmap)
{
    int result, a, b;
    int team[] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        a = (bitmap >> i) & 1;
        for (int j = i + 1; j < n; j++)
        {
            b = (bitmap >> j) & 1;
            if (a == b)
            {
                team[a] += stat[j * (j - 1) / 2 + i];
            }
        }
    }
    result = team[0] - team[1];
    return result > 0 ? result : -result;
}

int main(void)
{
    int n, tmp, stat_len, result = 1e9, bitmap = 0;
    int stat[200] = {0};
    scanf("%d", &n);
    stat_len = n * (n - 1) / 2;

    // 삼각행렬로 저장
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tmp);
            if (i > j)
            {
                stat[(i * (i - 1) / 2) + j] += tmp;
            }
            else if (i < j)
            {
                stat[j * (j - 1) / 2 + i] += tmp;
            }
        }
    }

    while (bitmap < (1 << (n - 1)) + 1)
    {
        // printf("%d %d\n", bitmap, get_diff(n, stat, bitmap));
        result = (tmp = get_diff(n, stat, bitmap)) < result ? tmp : result;
        bitmap += 1;
    }
    printf("%d\n", result);
}