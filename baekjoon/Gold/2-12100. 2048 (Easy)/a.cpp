#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<vector<bool>> tool;
int result = 0;

void print_metrix(vector<vector<int>> box)
{
  for (vector<int> y : box)
  {
    for (int x : y)
    {
      printf("%d ", x);
    }
    printf("\n");
  }
  printf("\n");
}

void move_0(vector<vector<int>> *box)
{
  vector<vector<bool>> t(tool);
  for (int y = 0; y < n; y++)
  {
    for (int x = n - 2; x >= 0; x--)
    {
      if ((*box)[y][x])
      {
        int a = 1;
        while (1)
        {
          if (x + a >= n)
          {
            (*box)[y][n - 1] = (*box)[y][x];
            (*box)[y][x] = 0;
            break;
          }
          if ((*box)[y][x + a])
          {
            if ((*box)[y][x + a] == (*box)[y][x] && !t[y][x + a])
            {
              (*box)[y][x + a] = (*box)[y][x + a] * 2;
              result = result > (*box)[y][x + a] ? result : (*box)[y][x + a];
              (*box)[y][x] = 0;
              t[y][x + a] = 1;
              break;
            }
            else
            {
              if ((*box)[y][x + a - 1] == (*box)[y][x])
                break;
              else
              {
                (*box)[y][x + a - 1] = (*box)[y][x];
                (*box)[y][x] = 0;
                break;
              }
            }
          }
          a++;
        }
      }
    }
  }
}

void move_1(vector<vector<int>> *box)
{
  vector<vector<bool>> t(tool);
  for (int y = 0; y < n; y++)
  {
    for (int x = 1; x < n; x++)
    {
      if ((*box)[y][x])
      {
        int a = 1;
        while (1)
        {
          if (x - a < 0)
          {
            (*box)[y][0] = (*box)[y][x];
            (*box)[y][x] = 0;
            break;
          }
          if ((*box)[y][x - a])
          {
            if ((*box)[y][x - a] == (*box)[y][x] && !t[y][x - a])
            {
              (*box)[y][x - a] = (*box)[y][x - a] * 2;
              result = result > (*box)[y][x - a] ? result : (*box)[y][x - a];
              (*box)[y][x] = 0;
              t[y][x - a] = 1;
              break;
            }
            else
            {
              if ((*box)[y][x - a + 1] == (*box)[y][x])
                break;
              else
              {
                (*box)[y][x - a + 1] = (*box)[y][x];
                (*box)[y][x] = 0;
                break;
              }
            }
          }
          a++;
        }
      }
    }
  }
}

void move_2(vector<vector<int>> *box)
{
  vector<vector<bool>> t(tool);
  for (int y = 1; y < n; y++)
  {
    for (int x = 0; x < n; x++)
    {
      if ((*box)[y][x])
      {
        int a = 1;
        while (1)
        {
          if (y - a < 0)
          {
            (*box)[0][x] = (*box)[y][x];
            (*box)[y][x] = 0;
            break;
          }
          if ((*box)[y - a][x])
          {
            if ((*box)[y - a][x] == (*box)[y][x] && !t[y - a][x])
            {
              (*box)[y - a][x] = (*box)[y - a][x] * 2;
              result = result > (*box)[y - a][x] ? result : (*box)[y - a][x];
              (*box)[y][x] = 0;
              t[y - a][x] = 1;
              break;
            }
            else
            {
              if ((*box)[y - a + 1][x] == (*box)[y][x])
                break;
              else
              {
                (*box)[y - a + 1][x] = (*box)[y][x];
                (*box)[y][x] = 0;
                break;
              }
            }
          }
          a++;
        }
      }
    }
  }
}

void move_3(vector<vector<int>> *box)
{
  vector<vector<bool>> t(tool);
  for (int y = n - 2; y >= 0; y--)
  {
    for (int x = 0; x < n; x++)
    {
      if ((*box)[y][x])
      {
        int a = 1;
        while (1)
        {
          if (y + a >= n)
          {
            (*box)[n - 1][x] = (*box)[y][x];
            (*box)[y][x] = 0;
            break;
          }
          if ((*box)[y + a][x])
          {
            if ((*box)[y + a][x] == (*box)[y][x] && !t[y + a][x])
            {
              (*box)[y + a][x] = (*box)[y + a][x] * 2;
              result = result > (*box)[y + a][x] ? result : (*box)[y + a][x];
              (*box)[y][x] = 0;
              t[y + a][x] = 1;
              break;
            }
            else
            {
              if ((*box)[y + a - 1][x] == (*box)[y][x])
                break;
              else
              {
                (*box)[y + a - 1][x] = (*box)[y][x];
                (*box)[y][x] = 0;
                break;
              }
            }
          }
          a++;
        }
      }
    }
  }
}

void get_max(vector<vector<int>> box, int ro, int depth)
{
  vector<vector<int>> block(box);
  if (depth > 5)
  {
    return;
  }
  block = box;
  move_0(&block);
  get_max(block, ro, depth + 1);
  block = box;
  move_1(&block);
  get_max(block, ro, depth + 1);
  block = box;
  move_2(&block);
  get_max(block, ro, depth + 1);
  block = box;
  move_3(&block);
  get_max(block, ro, depth + 1);
}

int main()
{
  vector<vector<int>> box;
  int t;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &t);
      tmp.push_back(t);
      result = result > t ? result : t;
    }
    box.push_back(tmp);
  }
  for (int i = 0; i < n; i++)
  {
    vector<bool> tmp;
    for (int i = 0; i < n; i++)
    {
      tmp.push_back(0);
    }
    tool.push_back(tmp);
  }
  get_max(box, 0, 1);
  printf("%d\n", result);
}