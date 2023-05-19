// 14501
// 퇴사
// 실버 3

#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  int n, a, b;
  vector<pair<int, int>> map;
  scanf("%d", &n);
  int arr[n + 1] = {0};
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &a, &b);
    map.push_back(make_pair(a, b));
  }
  for (int i = n - 1; i >= 0; i--)
  {
    int t = map[i].first;
    int np = map[i].second + arr[i + t];
    arr[i] = arr[i + 1];
    if (t <= n - i)
    {
      if (np > arr[i + 1])
      {
        arr[i] = np;
      }
    }
  }
  printf("%d\n", arr[0]);
}