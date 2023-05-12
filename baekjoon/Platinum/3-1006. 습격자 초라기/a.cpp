// 1006
// 습격자 초라기

#include <cstdio>
#include <algorithm>
#define MAX 30000

using namespace std;

int main()
{
  int t, n, w, result = MAX;
  int storage[10002][4];
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &w);
    int area1[n]; // 외부 원
    int area2[n]; // 내부 원
    for (int i = 0; i < n; i++)
    {
      scanf("%d", area1 + i);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d", area2 + i);
    }
    storage[0][0] = 0; // 둘 다 커버 가능
    storage[0][1] = 0; // 위만 커버 가능
    storage[0][2] = 0; // 아래만 커버 가능
    storage[0][3] = 0; // 둘 다 커버 불가능
    result = MAX;
    for (int i = 0; i < 4; i++) // 0:위쪽 결합 시작 1:아래쪽 결합 시작 2:3:일반 시작
    {
      for (int a = 0; a < n; a++)
      {
        for (int j = 0; j < 4; j++)
        {
          storage[a][j] = MAX;
        }
      }
      if (i == 0)
      {
        if (area1[n - 1] + area1[0] <= w)
        {
          storage[0][0] = 3; // 둘 다 커버 가능
          storage[0][1] = 3; // 위만 커버 가능
          storage[0][2] = 2; // 아래만 커버 가능
          storage[0][3] = 2; // 둘 다 커버 불가능
        }
        else
        {
          continue;
        }
      }
      else if (i == 1)
      {
        if (area2[n - 1] + area2[0] <= w)
        {
          storage[0][0] = 3; // 둘 다 커버 가능
          storage[0][1] = 2; // 위만 커버 가능
          storage[0][2] = 3; // 아래만 커버 가능
          storage[0][3] = 2; // 둘 다 커버 불가능
        }
        else
        {
          continue;
        }
      }
      else if (i == 2)
      {
        if ((area2[n - 1] + area2[0] <= w) && (area1[n - 1] + area1[0] <= w))
        {
          storage[0][0] = 4; // 둘 다 커버 가능
          storage[0][1] = 3; // 위만 커버 가능
          storage[0][2] = 3; // 아래만 커버 가능
          storage[0][3] = 2; // 둘 다 커버 불가능
        }
        else
        {
          continue;
        }
      }
      else if (i == 3)
      {
        if (area1[0] + area2[0] <= w)
        {
          storage[0][0] = 2; // 둘 다 커버 가능
          storage[0][1] = 2; // 위만 커버 가능
          storage[0][2] = 2; // 아래만 커버 가능
          storage[0][3] = 1; // 둘 다 커버 불가능
        }
        else
        {
          storage[0][0] = 2; // 둘 다 커버 가능
          storage[0][1] = 2; // 위만 커버 가능
          storage[0][2] = 2; // 아래만 커버 가능
          storage[0][3] = 2; // 둘 다 커버 불가능
        }
      }
      for (int k = 1; k < n - 1 + i / 3; k++)
      {
        storage[k][0] = min({storage[k - 1][0] + 2, storage[k - 1][1] + 2, storage[k - 1][2] + 2, storage[k - 1][3] + 2});
        storage[k][1] = min({storage[k - 1][0] + 2, storage[k - 1][1] + 2, storage[k - 1][2] + 2, storage[k - 1][3] + 2});
        storage[k][2] = min({storage[k - 1][0] + 2, storage[k - 1][1] + 2, storage[k - 1][2] + 2, storage[k - 1][3] + 2});
        storage[k][3] = min({storage[k - 1][0] + 2, storage[k - 1][1] + 2, storage[k - 1][2] + 2, storage[k - 1][3] + 2});
        if (area1[k] + area1[k - 1] <= w)
        {
          storage[k][2] = min({storage[k][2], storage[k - 1][0] + 1, storage[k - 1][1] + 1});
        }
        if (area2[k] + area2[k - 1] <= w)
        {
          storage[k][1] = min({storage[k][1], storage[k - 1][0] + 1, storage[k - 1][2] + 1});
        }
        if (area1[k] + area2[k] <= w)
        {
          storage[k][3] = min({storage[k][3], storage[k - 1][0] + 1, storage[k - 1][1] + 1, storage[k - 1][2] + 1, storage[k - 1][3] + 1});
        }
        if ((area1[k] + area1[k - 1] <= w) && (area2[k] + area2[k - 1] <= w))
        {
          storage[k][3] = min({storage[k][3], storage[k - 1][0]});
        }
        // printf("%d %d %d %d\n", storage[k][0], storage[k][1], storage[k][2], storage[k][3]);
      }
      // printf("%d %d %d %d\n", storage[n - 1][0], storage[n - 1][1], storage[n - 1][2], storage[n - 1][3]);
      // printf("%d  \n", i);
      if (i == 0)
      {
        result = min({result, storage[n - 2][0] + 1, storage[n - 2][1] + 1, storage[n - 2][2] + 1, storage[n - 2][3] + 1});
        if (area2[n - 2] + area2[n - 1] <= w)
        {
          result = min({result, storage[n - 2][0], storage[n - 2][2]});
        }
      }
      if (i == 1)
      {
        result = min({result, storage[n - 2][0] + 1, storage[n - 2][1] + 1, storage[n - 2][2] + 1, storage[n - 2][3] + 1});
        if (area1[n - 2] + area1[n - 1] <= w)
        {
          result = min({result, storage[n - 2][0], storage[n - 2][1]});
        }
      }
      if (i == 2)
      {
        result = min({result, storage[n - 2][0], storage[n - 2][1], storage[n - 2][2], storage[n - 2][3]});
      }
      if (i == 3)
      {
        result = min({result, storage[n - 1][0], storage[n - 1][1], storage[n - 1][2], storage[n - 1][3]});
      }
    }
    if (n == 1)
    {
      if (area1[0] + area2[0] <= w)
        result = 1;
      else
        result = 2;
    }
    printf("%d\n", result);
  }
}