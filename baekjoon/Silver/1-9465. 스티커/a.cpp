// 9465
// 스티커

#include <stdio.h>
#include <vector>

using namespace std;

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int N;
  scanf("%d", &N);
  // N번 반복
  for (int i = 0; i < N; i++)
  {
    vector<vector<int>> sticker;
    int n;
    scanf("%d", &n);

    // 데이터 입력
    for (int i = 0; i < 2; i++)
    {
      vector<int> tmp;
      int tt;
      for (int j = 0; j < n; j++)
      {
        scanf("%d", &tt);
        tmp.push_back(tt);
      }
      sticker.push_back(tmp);
    }

    // 저장소 초기화
    vector<vector<int>> store;
    for (int i = 0; i < n + 1; i++)
    {
      vector<int> tmp;
      for (int j = 0; j < 3; j++)
      {
        tmp.push_back(0);
      }
      store.push_back(tmp);
    }

    // 0일 때 위를 제거
    // 1일 때 아래를 제거
    // 2일 때 제거하지 않음
    for (int i = 1; i < n + 1; i++)
    {
      // 스티커를 때지 않고 이전 데이터 중 가장 큰 수 저장
      store[i][2] = max(store[i - 1][0], store[i - 1][1]);

      // 위 스티커를 때고 이전에 아래를 땟거나 때지 않은 경우 중 큰 수 저장
      store[i][0] = max(store[i - 1][1] + sticker[0][i - 1], store[i - 1][2] + sticker[0][i - 1]);

      // 아래 스티커를 때고 이전에 위를 땟거나 때지 않은 경우 중 큰 수 저장
      store[i][1] = max(store[i - 1][0] + sticker[1][i - 1], store[i - 1][2] + sticker[1][i - 1]);
    }
    printf("%d\n", max(max(store[n][0], store[n][1]), store[n][2]));
  }
}