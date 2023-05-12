#include <stdio.h>

bool can_move(int *arr, int l)
{
  int p = 0;
  while (arr[p+2])
  {
    if (arr[p] - arr[p + 2] == 1)
    {
      arr[p + 3] -= l;
      if (arr[p + 3] < 0)
      {
        return false;
      }
    }
    else if (arr[p + 2] - arr[p] == 1)
    {
      arr[p + 1] -= l;
      if (arr[p + 1] < 0)
      {
        return false;
      }
    }
    else
    {
      return false;
    }
    p += 2;
  }
  return true;
}

int main()
{
  int tmp;
  int n, l;
  int arr[200][200];
  scanf("%d %d", &n, &l);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  int result = 0;
  int p;
  for (int i = 0; i < n; i++)
  {
    p = 0;
    int line[401] = {0};
    line[p] = arr[i][0];
    line[p + 1] = 1;
    for (int j = 1; j < n; j++)
    {
      if (line[p] == arr[i][j])
      {
        line[p + 1]++;
      }
      else
      {
        p += 2;
        line[p] = arr[i][j];
        line[p + 1] = 1;
      }
    }
    if (can_move(line, l))
    {
      result++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    p = 0;
    int line[401] = {0};
    line[p] = arr[0][i];
    line[p + 1] = 1;
    for (int j = 1; j < n; j++)
    {
      if (line[p] == arr[j][i])
      {
        line[p + 1]++;
      }
      else
      {
        p += 2;
        line[p] = arr[j][i];
        line[p + 1] = 1;
      }
    }
    if (can_move(line, l))
    {
      result++;
    }
  }
  printf("%d\n", result);
  return 0;
}