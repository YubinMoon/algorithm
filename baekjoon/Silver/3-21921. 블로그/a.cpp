#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 250000

int main()
{
  int N, X;
  int arr[MAX_LEN];
  int sum_arr[MAX_LEN] = {0};
  int max = 0;
  scanf("%d %d", &N, &X);
  for (int i = 0; i < N; i++)
    scanf("%d", arr + i);

  for (int i = 0; i < X; i++)
  {
    sum_arr[0] += arr[i];
  }
  max = sum_arr[0];

  for (int i = 1; i < N - X + 1; i++)
  {
    sum_arr[i] = sum_arr[i - 1] - arr[i - 1] + arr[i + X - 1];
    max = max < sum_arr[i] ? sum_arr[i] : max;
  }
  if (max)
  {
    printf("%d\n", max);
    int sum = 0;
    for (int i = 0; i < N - X + 1; i++)
    {
      if (max == sum_arr[i])
        sum += 1;
    }
    printf("%d\n", sum);
  }
  else
  {
    printf("SAD\n");
  }
  return 0;
}