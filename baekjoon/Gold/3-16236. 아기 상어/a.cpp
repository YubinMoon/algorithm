#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int baby_size = 2;
int a_x[] = {1, 0, -1, 0};
int a_y[] = {0, 1, 0, -1};
int n;
int t_size;
vector<vector<bool>> map;
vector<vector<int>> fish_list;
queue<vector<int>> path_queue;
int x = 100;
int y = 100;
int cost = -2;
int result = 0;

bool search()
{
  int t_x;
  int t_y;
  if (path_queue.empty())
  {
    return false;
  }
  vector<int> pos = path_queue.front();
  path_queue.pop();
  if (fish_list[pos[0]][pos[1]] > baby_size)
  {
    return search();
  }
  for (int i = 0; i < 4; i++)
  {
    t_y = pos[0] + a_y[i];
    t_x = pos[1] + a_x[i];
    if (t_x < 0 || t_y < 0 || t_x >= n || t_y >= n)
    {
      continue;
    }
    if (map[t_y][t_x])
    {
      map[t_y][t_x] = false;
      vector<int> tmp = {t_y, t_x, pos[2] + 1};
      path_queue.push(tmp);
    }
  }
  if (pos[2] == cost + 1)
  {
    return true;
  }
  if (fish_list[pos[0]][pos[1]] == 0)
  {
    return search();
  }
  if (fish_list[pos[0]][pos[1]] < baby_size)
  {
    cost = pos[2];
    if (pos[0] < y)
    {
      y = pos[0];
      x = pos[1];
    }
    else if (pos[0] == y)
    {
      x = pos[1] < x ? pos[1] : x;
    }
  }
  return search();
}

int main()
{
  int baby_pos[2];
  int eat = 0;
  scanf("%d", &n);
  map.resize(n);
  for (int i = 0; i < n; i++)
  {
    vector<int> tmp;
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &t_size);
      if (t_size == 9)
      {
        baby_pos[0] = i;
        baby_pos[1] = j;
        tmp.push_back(0);
      }
      else
      {
        tmp.push_back(t_size);
      }
    }
    fish_list.push_back(tmp);
  }
  for (int i = 0; i < n; i++)
  {
    vector<bool> tmp(n, true);
    map[i] = tmp;
  }
  vector<vector<bool>> map_copy = map;
  while (1)
  {
    map = map_copy;
    vector<int> t = {baby_pos[0], baby_pos[1], 0};
    path_queue.push(t);
    search();
    if (cost != -2)
    {
      result += cost;
      cost = -2;
      baby_pos[0] = y;
      baby_pos[1] = x;
      fish_list[y][x] = 0;
      eat += 1;
      if (eat == baby_size)
      {
        baby_size += 1;
        eat = 0;
      }
      x = 100;
      y = 100;
      while(!path_queue.empty()){
        path_queue.pop();
      }
    }
    else
    {
      break;
    }
  }
  printf("%d\n", result);
}