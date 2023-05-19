// 2644
// 촌수계산
// 실버 2

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
queue<int> p_queue;
int p_num;
bool *p_check;

int get_fam(vector<int> people[], int s, int r)
{
  if (p_queue.empty())
  {
    return -1;
  }
  int size = p_queue.size();
  for (int i = 0; i < size; i++)
  {
    int top = p_queue.front();
    for (int next : people[top])
    {
      if (!p_check[next])
      {
        p_check[next] = true;
        if (next == s)
        {
          return r;
        }
        p_queue.push(next);
      } 
    }
    p_queue.pop();
  }
  return get_fam(people, s, r + 1);
}

int main()
{
  int f, s, n;
  scanf("%d", &p_num);
  scanf("%d %d", &f, &s);
  f--;
  s--;
  scanf("%d", &n);
  vector<int> people[p_num];
  p_check = new bool[p_num];
  for (int i = 0; i < p_num; i++)
  {
    p_check[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    people[a].push_back(b);
    people[b].push_back(a);
  }
  p_queue.push(f);
  printf("%d\n", get_fam(people, s, 1));
}