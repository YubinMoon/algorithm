// 20058
// 마법사 상어와 파이어스톰
// 골드 4

#include <cstdio>
#include <cmath>

int n, q, l, m;
int map[100][100];
int tmp[100][100];

void print_map()
{
  for (int i = 0; i < n+2; i++)
  {
    for (int j = 0; j < n+2; j++)
    {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void print_tmp()
{
  for (int i = 0; i < n+2; i++)
  {
    for (int j = 0; j < n+2; j++)
    {
      printf("%d ", tmp[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void rotate(int s_r, int s_c)
{
  int t_r, t_c;
  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < l; j++)
    {
      t_r = j;
      t_c = -i + l-1;
      tmp[s_r + t_r][s_c + t_c] = map[s_r + i][s_c + j];
    }
  }
}

void erease(){
  int a;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=n;j++){
      a = 0;
      // if()
    }
  }
}

int main()
{
  scanf("%d %d", &n, &q);
  n = (int)pow(2, n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &map[i + 1][j + 1]);
    }
  }
  // print_map();
  while (q--)
  {
    scanf("%d", &l);
    l = (int)pow(2, l);
    m = n / l;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < m; j++)
      {
        rotate(l * i + 1, l * j + 1);
      }
    }
    print_tmp();
  }
}