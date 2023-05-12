#include <stdio.h>

int main()
{
  int n, k;
  int result = 0;
  char str[20001];
  scanf("%d %d %s", &n, &k, str);
  for (int i = 0; i < n; i++)
  {
    if (str[i] == 'P')
    {
      for (int j = i - k; j <= i + k; j++)
      {
        if (j >= 0 && j < n)
          if (str[j] == 'H')
          {
            str[j] = 'N';
            result++;
            break;
          }
      }
    }
  }
  printf("%d\n", result);
}