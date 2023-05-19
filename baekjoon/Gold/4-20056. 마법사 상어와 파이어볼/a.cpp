// 20056
// 마법사 상어와 파이어볼

#include <cstdio>
#include <vector>

using namespace std;

typedef struct _ball
{
  int mess;
  int speed;
  int direction;
} BALL;

int n, m, k;
int x_to[] = {0, 1, 1, 1, 0, -1, -1, -1};
int y_to[] = {-1, -1, 0, 1, 1, 1, 0, -1};

// void print_map(vector<BALL *> **map)
// {
//   printf("map\n");
//   for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       for (BALL *b : map[i][j])
//       {
//         printf("%d %d: m=%d s=%d d=%d\n", i, j, b->mess, b->speed, b->direction);
//       }
//     }
//   }
//   printf("\n");
// }

void clear(vector<BALL *> **map)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map[i][j].size() > 0)
        map[i][j].clear();
    }
  }
}

void move(vector<BALL *> **map, vector<BALL *> **buf)
{
  int x, y;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (BALL *b : map[i][j])
      {
        x = (j + b->speed * x_to[b->direction]) % n;
        while (x < 0)
          x += n;
        y = (i + b->speed * y_to[b->direction]) % n;
        while (y < 0)
          y += n;
        buf[y][x].push_back(b);
      }
    }
  }
}

void spread(vector<BALL *> **map, vector<BALL *> **buf)
{
  int mess, speed, direction;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map[i][j].size() == 1)
      {
        buf[i][j].push_back(map[i][j][0]);
      }
      else if (map[i][j].size() > 1)
      {
        mess = 0, speed = 0, direction = 0;
        for (BALL *b : map[i][j])
        {
          mess += b->mess;
          speed += b->speed;
          direction += (b->direction % 2);
        }
        mess /= 5;
        speed /= map[i][j].size();
        if (mess == 0)
        {
          continue;
        }
        if (direction == 0 || direction == map[i][j].size())
        {
          direction = 0;
        }
        else
        {
          direction = 1;
        }
        for (int k = 0; k < 4; k++)
        {
          BALL *b = new BALL;
          b->mess = mess;
          b->speed = speed;
          b->direction = k * 2 + direction;
          buf[i][j].push_back(b);
        }
      }
    }
  }
}

int main()
{
  scanf("%d %d %d", &n, &m, &k);
  vector<BALL *> **map = new vector<BALL *> *[n];
  vector<BALL *> **buf = new vector<BALL *> *[n];
  for (int i = 0; i < n; i++)
  {
    map[i] = new vector<BALL *>[n];
    buf[i] = new vector<BALL *>[n];
  }
  BALL *b;
  for (int i = 0; i < m; i++)
  {
    int r, c, speed;
    b = new BALL;
    scanf("%d %d", &r, &c);
    scanf("%d %d %d", &(b->mess), &(b->speed), &(b->direction));
    map[r - 1][c - 1].push_back(b);
  }
  while (k--)
  {
    move(map, buf);
    clear(map);
    spread(buf, map);
    clear(buf);
  }
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (BALL *b : map[j][i])
      {
        result += b->mess;
      }
    }
  }
  printf("%d\n", result);
}