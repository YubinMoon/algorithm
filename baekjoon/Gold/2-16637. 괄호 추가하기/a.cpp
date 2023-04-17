#include <cstdio>
#include <cstdlib>
#include <cstring>

int calc(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    }
    return 0;
}

void get_max_num(char *exp, int prevalue, int *result)
{
    int value1, value2, tmp;
    int len = strlen(exp);

    // case 1 - pre + a
    value1 = calc(prevalue, exp[1] - '0', exp[0]);
    if (len <= 2)
    {
        *result = *result < value1 ? value1 : *result;
        return;
    }
    get_max_num(exp + 2, value1, result);

    // case 2 - pre + (a+b)
    tmp = calc(exp[1] - '0', exp[3] - '0', exp[2]);
    value2 = calc(prevalue, tmp, exp[0]);
    if (len <= 4)
    {
        *result = *result < value2 ? value2 : *result;
        return;
    }
    get_max_num(exp + 4, value2, result);
}

int main(void)
{
    int n, result = 0x80000000;
    char exp[30] = {0};
    char *ptr = exp;
    scanf("%d ", &n);
    scanf("%s", exp);
    if (n == 1)
    {
        result = exp[0] - '0';
    }
    if (n >= 3)
    {
        get_max_num(exp + 1, exp[0] - '0', &result);
    }
    if (n >= 5)
    {
        get_max_num(exp + 3, calc(exp[0] - '0', exp[2] - '0', exp[1]), &result);
    }
    printf("%d\n", result);
}