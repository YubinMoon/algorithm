#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

queue<vector<int>> qu;
int ****box;
int n, m, h;
int d_x[] = {1, -1, 0, 0, 0, 0};
int d_y[] = {0, 0, 1, -1, 0, 0};
int d_z[] = {0, 0, 0, 0, 1, -1};

int main()
{
  scanf("%d %d %d", &n, &m, &h);
  box = (int ****)malloc(sizeof(int ***) * h);
  for (int i = 0; i < h; i++)
  {
    box[i] = (int ***)malloc(sizeof(int **) * m);
    for (int j = 0; j < m; j++)
    {
      box[i][j] = (int **)malloc(sizeof(int *) * n);
      for (int k = 0; k < n; k++)
      {
        box[i][j][k] = (int *)malloc(sizeof(int) * 2);
        scanf("%d", &box[i][j][k][0]);
        box[i][j][k][1] = 0;
        if (box[i][j][k][0] == 1)
        {
          qu.push({i, j, k});
        }
      }
    }
  }
  int x, y, z;
  int t_x, t_y, t_z;
  int result = 0;
  while (!qu.empty())
  {
    x = qu.front()[0];
    y = qu.front()[1];
    z = qu.front()[2];
    for (int i = 0; i < 6; i++)
    {
      t_x = x + d_x[i];
      t_y = y + d_y[i];
      t_z = z + d_z[i];
      if (0 <= t_x && t_x < h && 0 <= t_y && t_y < m && 0 <= t_z && t_z < n)
        if (box[t_x][t_y][t_z][0] == 0)
        {
          box[t_x][t_y][t_z][0] = 1;
          qu.push({t_x, t_y, t_z});
          box[t_x][t_y][t_z][1] = box[x][y][z][1] + 1;
        }
    }
    qu.pop();
  }
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < n; k++)
      {
        if (box[i][j][k][0] == 0)
        {
          printf("-1\n");
          return 0;
        }
        result = result < box[i][j][k][1] ? box[i][j][k][1] : result;
      }
    }
  }
  printf("%d\n", result);
  return 0;
}
