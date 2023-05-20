#include <cstdio>

#define MAX_INT 2000000001

int n, m;
int trees[1000000];

int get_tree_size(int heigh)
{
    unsigned int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += trees[i] > heigh ? trees[i] - heigh : 0;
        if (total > MAX_INT)
            return MAX_INT;
    }
    return total;
}

int main(void)
{
    int a = 0, b = MAX_INT;
    int c, tmp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", trees + i);
    // search
    while (1)
    {
        if (a >= b)
            break;
        c = (b + a + 1) / 2;
        tmp = get_tree_size(c);
        if (tmp >= m)
            a = c;
        else
            b = c - 1;
    }
    printf("%d\n", a);
}