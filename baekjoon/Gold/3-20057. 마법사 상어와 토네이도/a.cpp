// 20057
// 마법사 상어와 토네이도

#include <cstdio>

// 이동 방향
int to_x[] = {-1, 0, 1, 0};
int to_y[] = {0, 1, 0, -1};
int tmp_ratio[][3] = {
    {-2, 0, 5},
    {-1, 1, 10},
    {-1, -1, 10},
    {0, 1, 7},
    {0, -1, 7},
    {0, 2, 2},
    {0, -2, 2},
    {1, 1, 1},
    {1, -1, 1},
    {-1, 0, 0}};
int **std_ratio;
int n;
int count = 0;
int p_x;
int p_y;
int speed = 0;
int direction;
int **map;
int result = 0;

void change_ratio()
{
  int **tt = new int *[10];
  for (int i = 0; i < 10; i++)
  {
    tt[i] = new int[3];
    tt[i][0] = -std_ratio[i][1];
    tt[i][1] = std_ratio[i][0];
    tt[i][2] = std_ratio[i][2];
    delete[] std_ratio[i];
  }
  delete[] std_ratio;
  std_ratio = tt;
}

bool move(int **map)
{
  for (int i = 0; i < speed; i++)
  {
    int t_x, t_y;
    p_x = p_x + to_x[direction];
    p_y = p_y + to_y[direction];
    int send = map[p_y][p_x];
    int next_send = send;
    int tmp;
    for (int j = 0; j < 10; j++)
    {
      tmp = (send * std_ratio[j][2]) / 100;
      next_send -= tmp;
      if (j == 9)
      {
        tmp = next_send;
      }
      t_x = p_x + std_ratio[j][1];
      t_y = p_y + std_ratio[j][0];
      if (0 <= t_x && t_x < n && 0 <= t_y && t_y < n)
      {
        map[t_y][t_x] += tmp;
      }
      else
      {
        result += tmp;
      }
    }
    if (p_x == 0 && p_y == 0)
      return true;
  }
  return false;
}

int main()
{
  std_ratio = new int *[10];
  for (int i = 0; i < 10; i++)
  {
    std_ratio[i] = new int[3];
    for (int j = 0; j < 3; j++)
    {
      std_ratio[i][j] = tmp_ratio[i][j];
    }
  }
  scanf("%d", &n);
  map = new int *[n];
  for (int i = 0; i < n; i++)
  {
    map[i] = new int[n];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &map[i][j]);
    }
  }
  p_x = n / 2;
  p_y = n / 2;
  while (1)
  {
    if (count % 2 == 0) // 두번에 속도 증가
    {
      speed++;
    }
    direction = count % 4;
    change_ratio();
    // for(int i = 0;i<9;i++){
    //   printf("%d %d %d\n",std_ratio[i][0],std_ratio[i][1],std_ratio[i][2]);
    // }
    // printf("\n");

    if (move(map))
    {
      break;
    }
    count++;
  }
  printf("%d\n", result);
}