#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int ro_x[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int ro_y[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

bool find_ro(vector<vector<vector<int>>> *map, int x, int y)
{
  int n = 8;
  int ro, t_x, t_y;
  while (n--)
  {
    ro = (*map)[y][x][1];
    t_x = x + ro_x[ro];
    t_y = y + ro_y[ro];
    if (t_x >= 0 && t_x < 4 && t_y >= 0 && t_y < 4)
    {
      if ((*map)[t_y][t_x][0] != -1)
      {
        return true;
      }
    }
    (*map)[y][x][1] = ro % 8 + 1;
  }
  return false;
}

void move(vector<vector<vector<int>>> *map)
{
  bool key = true;
  for (int fish = 1; fish < 17; fish++, key = true)
  {
    for (int i = 0; i < 4 && key; i++)
    {
      for (int j = 0; j < 4 && key; j++)
      {
        if ((*map)[i][j][0] == fish)
        {
          key = false;
          if (find_ro(map, j, i))
          {
            int ro = (*map)[i][j][1];
            int t_1 = (*map)[i][j][0];
            int t_2 = (*map)[i][j][1];
            (*map)[i][j][0] = (*map)[i + ro_y[ro]][j + ro_x[ro]][0];
            (*map)[i][j][1] = (*map)[i + ro_y[ro]][j + ro_x[ro]][1];
            (*map)[i + ro_y[ro]][j + ro_x[ro]][0] = t_1;
            (*map)[i + ro_y[ro]][j + ro_x[ro]][1] = t_2;
          }
        }
      }
    }
  }
}

int feed_shark(vector<vector<vector<int>>> *map, int x, int y, int depth)
{
  vector<vector<vector<int>>> ttt;
  int tmp;
  int result = 0;
  int feed;
  int n = 0;
  int s_x = 0;
  int s_y = 0;
  int t_x, t_y;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if ((*map)[i][j][0] == -1)
      {
        s_x = j;
        s_y = i;
      }
    }
  }
  feed = (*map)[y][x][0];
  int ro = (*map)[y][x][1];
  (*map)[s_y][s_x][0] = 0;
  (*map)[y][x][0] = -1;
  move(map);
  while (++n)
  {
    ttt = *map;
    t_x = x + ro_x[ro] * n;
    t_y = y + ro_y[ro] * n;
    if (t_x < 0 || t_x > 3 || t_y < 0 || t_y > 3)
    {
      break;
    }
    if ((*map)[t_y][t_x][0] == 0)
    {
      continue;
    }
    tmp = feed_shark(&ttt, t_x, t_y, depth + 1);
    result = result > tmp ? result : tmp;
  }
  return result + feed;
}

int main()
{
  int a, b;
  vector<vector<vector<int>>> map;
  for (int i = 0; i < 4; i++)
  {
    vector<vector<int>> tmp1;
    for (int j = 0; j < 4; j++)
    {
      scanf("%d%d", &a, &b);
      tmp1.push_back({a, b});
    }
    map.push_back(tmp1);
  }
  int ttt = feed_shark(&map, 0, 0, 0);
  printf("%d\n", ttt);
}