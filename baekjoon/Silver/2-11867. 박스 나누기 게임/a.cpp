// 11867
// 박스 나누기 게임
// 실버 2

#include <cstdio>

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  printf(a * b % 2 ? "B\n" : "A\n");
}