#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

/*
인터렉티브 문제
박스에 없는 값 중 가장 작은 값은 무조건 소수이다
필요한 전체 수에서 소수 배열을 구하고
배열을 이진탐색하여 문제를 해결하였다.
*/

int main(void)
{
  int N;
  int *prime;
  std::vector<int> prime_list(0);
  scanf("%d", &N);
  N = N += 1;
  prime = (int *)malloc(sizeof(int) * N);
  memset(prime, 0x00, sizeof(int) * N);
  // 소수 구하기
  for (int i = 2; i < N; i++)
  {
    if (prime[i] == 0)
    {
      prime_list.push_back(i);
      for (int j = i; j < N; j += i)
      {
        prime[j] = 1;
      }
    }
  }

  int min = 0;
  int max = prime_list.size() - 1;
  int mid;
  for (int i = 0; i < 20; i++)
  {
    mid = (min + max) / 2;
    int result;
    printf("? %d\n", prime_list[mid]);
    fflush(stdout);
    scanf("%d", &result);
    if (result)
    {
      min = mid + 1;
    }
    else
    {
      max = mid;
    }
  }
  printf("! %d\n", prime_list[mid]);
}