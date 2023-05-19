// 2606
// 바이러스

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void get_num(int name, vector<int> graph[], bool check[])
{
  int result = 0;
  check[name] = true;
  for (int i = 0; i < graph[name].size(); i++)
  {
    if (check[graph[name][i]] == false)
    {
      get_num(graph[name][i], graph, check);
    }
  }
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> graph[n + 1];
  bool check[n + 1] = {false};
  for (int k = 0; k < n + 1; k++)
  {
    check[k] = false;
  }
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < n + 1; i++)
  {
    sort(graph[i].begin(), graph[i].end());
  }
  get_num(1, graph, check);
  int result = 0;
  for (int i = 0; i < n + 1; i++)
  {
    if (check[i])
    {
      result++;
    }
  }
  printf("%d\n", result-1);
}