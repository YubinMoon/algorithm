#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int main(void)
{
  int n, m;
  char mb[] = "ISTJ";
  int result;
  int tmp_re;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int arr[16] = {
        0,
    };
    scanf("%d", &m);
    result = m * 4;
    for (int x = 0; x < m; x++)
    {
      char *tmp = (char *)malloc(sizeof(char) * 5);
      int tt = 0;
      scanf("%s", tmp);
      for (int b = 0; b < 4; b++)
      {
        if (tmp[b] == mb[b])
        {
          tt += pow(2, b);
        }
      }
      arr[tt] += 1;
    }
    for (int y = 0; y < 16; y++)
    {
      if (!arr[y])
        continue;
      arr[y]--;
      for (int j = y; j < 16; j++)
      {
        if (!arr[j])
          continue;
        arr[j]--;
        for (int k = j; k < 16; k++)
        { 
          if (!arr[k])
            continue;
          arr[k]--;
          tmp_re = 0;
          int a1 = y;
          int a2 = j;
          int a3 = k;
          for (int l = 0; l < 4; l++)
          {
            int t1 = a1 % 2;
            int t2 = a2 % 2;
            int t3 = a3 % 2;
            if (t1 != t2)
              tmp_re += 1;
            if (t2 != t3)
              tmp_re += 1;
            if (t1 != t3)
              tmp_re += 1;
            a1 /= 2;
            a2 /= 2;
            a3 /= 2;
          }
          result = result < tmp_re ? result : tmp_re;
          arr[k]++;
        }
        arr[j]++;
      }
      arr[y]++;
    }
    printf("%d\n", result);
  }
}
/*
3
3
ENTJ INTP ESFJ
4
ESFP ESFP ESFP ESFP
5
INFP INFP ESTP ESTJ ISTJ
*/