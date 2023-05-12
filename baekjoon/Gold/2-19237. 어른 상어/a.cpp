#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

//상어 리스트
typedef struct _shark
{
  int name;
  int face; // 1 2 3 4 / 위 왼쪽 아래 오른쪽
  int **order;
} SHARK;

// 맵에 있는 상어 정보
typedef struct _node
{
  int owner = 0;
  int scent = 0;
  int size = 0;
  vector<SHARK *> *shark; // 이동 기준 빼오기 위해
} NODE;

int n, m, k;
int ro_x[] = {0, 0, -1, 1};
int ro_y[] = {-1, 1, 0, 0};
NODE ***map;
SHARK **shark_list;

// 출력
void print_map()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", map[i][j]->owner);
    }
    printf("\n");
  }
  printf("\n");
}

bool is_last()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map[i][j]->size)
      {
        if (map[i][j]->owner > 1)
        {
          return false;
        }
      }
    }
  }
  return true;
}

// 상어 움직임 계산
void move_all()
{
  stack<vector<int>> ttt;
  bool key;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map[i][j]->size)
      {
        ttt.push({i, j}); // 움직일 상어 추가
      }
    }
  }

  while (!ttt.empty())
  {
    key = true;
    int i = ttt.top()[0];
    int j = ttt.top()[1];
    ttt.pop();
    int t_x, t_y;
    int *move_set = shark_list[map[i][j]->owner - 1]->order[shark_list[map[i][j]->owner - 1]->face];

    if(map[i][j]->owner == 5){
      
    }
    for (int w = 0; w < 4; w++)
    {
      t_x = j + ro_x[move_set[w]];
      t_y = i + ro_y[move_set[w]];
      if (t_x >= 0 && t_x < n && t_y >= 0 && t_y < n)
      {
        if(map[i][j]->owner == 5){
        }
        if (map[t_y][t_x]->scent == 0)
        {
          key = false;
          map[t_y][t_x]->size += 1;
          map[t_y][t_x]->shark->push_back(map[i][j]->shark->at(0));
          map[t_y][t_x]->shark->back()->face = move_set[w];
        if(map[i][j]->owner == 5){
        }
          map[i][j]->shark->clear();
          map[i][j]->size = 0;
        if(map[i][j]->owner == 5){
        }
          break;
        }
      }
    }
    for (int w = 0; w < 4 && key; w++)
    {
      t_x = j + ro_x[move_set[w]];
      t_y = i + ro_y[move_set[w]];
      if (t_x >= 0 && t_x < n && t_y >= 0 && t_y < n)
      {
        if (map[t_y][t_x]->owner == map[i][j]->owner)
        {
          map[t_y][t_x]->size = 1;
          map[t_y][t_x]->shark->push_back(map[i][j]->shark->at(0));
          map[t_y][t_x]->shark->back()->face = move_set[w];
          map[i][j]->shark->clear();
          map[i][j]->size = 0;
          break;
        }
      }
    }
  }
}

// 중복 상어 제거 and 향기 추가 and 향기 제거
void update_map()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map[i][j]->scent > 0)
      {
        map[i][j]->scent -= 1;
        if (map[i][j]->scent == 0)
          map[i][j]->owner = 0;
      }
      if (map[i][j]->size > 1)
      {
        int name = m;
        for (int b = 0; b < map[i][j]->shark->size(); b++)
        {
          name = name < map[i][j]->shark->at(b)->name ? name : map[i][j]->shark->at(b)->name;
        }
        SHARK *tt;
        for (int b = 0; b < map[i][j]->shark->size(); b++)
        {
          if (map[i][j]->shark->at(b)->name == name)
          {
            tt = map[i][j]->shark->at(b);
          }
        }
        map[i][j]->shark->clear();
        map[i][j]->shark->push_back(tt);
        map[i][j]->size = 1;
      }
      if (map[i][j]->size == 1)
      {
        map[i][j]->owner = map[i][j]->shark->at(0)->name; // 저장된 상어에서 이름 가져와 저장
        map[i][j]->scent = k;
      }
    }
  }
}

int get_num()
{
  int n = 0;
  while (++n)
  {
    update_map();
    if (is_last()) // 1만 남으면
    {
      return n - 1;
    }
    if (n > 1000)
      return -1;
    move_all();
  }
  return 1;
}

int main()
{
  int t;
  scanf("%d %d %d", &n, &m, &k);                      // 맴 크기, 상어 수, 향기 잔향
  shark_list = (SHARK **)malloc(sizeof(SHARK *) * m); // 상어 리스트
  for (int i = 0; i < m; i++)
  {
    shark_list[i] = (SHARK *)malloc(sizeof(SHARK));
    shark_list[i]->name = i + 1;
  }
  map = (NODE ***)malloc(sizeof(NODE **) * n); // 맵
  for (int i = 0; i < n; i++)
  {
    NODE **tmp = (NODE **)malloc(sizeof(NODE *) * n);
    for (int j = 0; j < n; j++)
    {
      NODE *ttt = (NODE *)malloc(sizeof(NODE));
      ttt->shark = new vector<SHARK *>(); // 맵에 백터 초기화
      scanf("%d", &t);
      if (t != 0)
      {
        ttt->size = 1;
        ttt->shark->push_back(shark_list[t - 1]); // 상어 추가
      }
      else
      {
        ttt->size = 0;
      }
      tmp[j] = ttt;
    }
    map[i] = tmp;
  }
  
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &t);
    shark_list[i]->face = t - 1; // 상어 현제 방향
  }
  for (int i = 0; i < m; i++)
  {
    int **tmp = (int **)malloc(sizeof(int *) * 4);
    for (int j = 0; j < 4; j++) // 상어 방향 별 기준
    {
      int *ttt = (int *)malloc(sizeof(int) * 4);
      for (int b = 0; b < 4; b++)
      {
        scanf("%d", &t);
        ttt[b] = t - 1;
      }
      tmp[j] = ttt;
    }
    shark_list[i]->order = tmp;
  }
  printf("%d\n", get_num());
  // free
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      free(shark_list[i]->order[j]);
    }
    free(shark_list[i]->order);
  }
  for (int i = 0; i < m; i++)
  {
    free(shark_list[i]);
  }
  free(shark_list);

  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      free(map[i][j]);
    }
    free(map[i]);
  }
  free(map);

  return 0;
}