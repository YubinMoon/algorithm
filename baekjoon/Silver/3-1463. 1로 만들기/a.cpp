// 1로 만들기

#include <stdio.h>
#define MAX 1000001

int min(int a, int b)
{
  return a > b ? b : a;
}

int main()
{
  int N;
  int arr[MAX];
  for (int i = 0; i < MAX; i++)
    arr[i] = MAX;
  scanf("%d", &N);
  arr[1] = 0;
  for (int i = 1; i < N; i++)
  {
    arr[i + 1] = min(arr[i + 1], arr[i] + 1);
    if (i * 2 <= N)
      arr[i * 2] = min(arr[i * 2], arr[i] + 1);
    if (i * 3 <= N)
      arr[i * 3] = min(arr[i * 3], arr[i] + 1);
  }
  printf("%d\n", arr[N]);
}