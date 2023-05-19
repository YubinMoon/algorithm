#include <stdio.h>

int main()
{
  char king[10];                            // king 입력
  char stone[10];                           // stone 입려
  char input[10];                           // 방향 입력
  char move_code[8] = {'R', 'L', 'B', 'T'}; // 방향 종류
  int move_x[8] = {1, -1, 0, 0};            // 종류별 방향
  move_code;
  int move_y[8] = {0, 0, -1, 1};
  int n, x, y;
  scanf("%s %s %d", king, stone, &n);

  // 위치 지정 0~7
  int king_x = king[0] - 'A';
  int king_y = king[1] - '1';
  int stone_x = stone[0] - 'A';
  int stone_y = stone[1] - '1';
  while (n--)
  {
    // 방향 초기화
    x = 0;
    y = 0;
    scanf("%s", input);

    // 방향 설정
    for (int i = 0; i < 4; i++)
    {
      if (input[0] == move_code[i])
      {
        x += move_x[i];
        y += move_y[i];
        break;
      }
    }
    if (input[1])
    {
      for (int i = 0; i < 4; i++)
      {
        if (input[1] == move_code[i])
        {
          x += move_x[i];
          y += move_y[i];
          break;
        }
      }
    }

    // 옮기기
    // 범위를 넘어서면
    if ((king_x + x < 0 || 7 < king_x + x) || (king_y + y < 0 || 7 < king_y + y))
    {
      continue;
    }
    else
    {
      // king과 stone가 겹치면
      if (king_x + x == stone_x && king_y + y == stone_y)
      {
        // stone이 범위를 벗어나면
        if ((stone_x + x < 0 || 7 < stone_x + x) || (stone_y + y < 0 || 7 < stone_y + y))
        {
          continue;
        }
        else
        {
          king_x += x;
          king_y += y;
          stone_x += x;
          stone_y += y;
          continue;
        }
      }
      else
      {
        king_x += x;
        king_y += y;
        continue;
      }
    }
  }
  printf("%c%d\n%c%d\n", king_x + 'A', king_y + 1, stone_x + 'A', stone_y + 1);
}