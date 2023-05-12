#include <stdio.h>
#include <vector>
#include <algorithm>

#define START 0
#define END 1

using namespace std;

int n;
vector<vector<int>> process;
int *arr;

bool cmp(vector<int> a, vector<int> b)
{
  if (a[1] < b[1])
    return 1;
  else
    return 0;
}

int find_last(int n)
{
  do
  {
    if (arr[n])
    {
      return arr[n];
    }
  } while (n--);
  return 0;
}

int get_num()
{
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; i++)
  {
    a = find_last(process[i][0]);
    b = find_last(process[i][1]);
    arr[process[i][1]] = (unsigned int)(a + b)%20070713;
  }
  return find_last(n * 2 - 1);
}

int main()
{
  int s, e;
  vector<vector<int>> container;
  scanf("%d", &n);
  process.resize(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &s, &e);
    vector<int> tmp1 = {s, i};
    vector<int> tmp2 = {e, i};
    container.push_back(tmp1);
    container.push_back(tmp2);
  }
  sort(container.begin(), container.end());
  arr = (int *)malloc(sizeof(int) * n * 2);
  for (int i = 0; i < n * 2; i++)
  {
    arr[i] = 0;
  }
  for (int i = 0; i < 2 * n; i++)
  {
    process[container[i][1]].push_back(i);
  }
  sort(process.begin(), process.end(), cmp);
  arr[0] = 1;
  printf("%d\n", get_num());
  free(arr);
  return 0;
}
