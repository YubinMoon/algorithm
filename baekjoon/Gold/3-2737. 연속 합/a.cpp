// 2737
// 연속 합
// 골드 3

#include <cstdio>
int result;
long long k;

bool even(long long n)
{
  if (2 * k > n * n)
  {
    if (k % n == n / 2)
    {
      result++;
    }
    return true;
  }
  else
  {
    return false;
  }
}

bool odd(long long n)
{
  if (2 * k > n * n - n)
  {
    if (k % n == 0)
    {
      result++;
    }
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int t;
  long long n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &k);
    result = 0;
    n = 2;
    while (even(n))
    {
      n += 2;
    }
    n = 3;
    while (odd(n))
    {
      n += 2;
    }
    printf("%d\n", result);
  }
}