#include <cstdio>

int main()
{
    char num[10];
    int arr[10] = {0};
    int maxnum = -1;
    scanf("%s", num);
    for (int i = 0; num[i]; i++)
    {
        arr[num[i] - '0'] += 1;
    }
    arr[6] = (arr[6] + arr[9] + 1) / 2;
    for (int i = 0; i < 9; i++)
    {
        maxnum = arr[i]>maxnum?arr[i]:maxnum;
    }
    printf("%d\n", maxnum);
    return 0;
}