// 25169
// 피곤한 아리의 현생 살기

#include <cstdio>
#include <vector>

using namespace std;
int n;
int max_time = 0;
int job_list[100];
vector<pair<int, int>> job;

int get_stress(int stress, int time, int remain_time)
{
  int st = stress * time;
  return st + st * remain_time / 10;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    job.push_back(make_pair(a, b));
    max_time += a;
    job_list[i] = i;
  }
  job_list[n] = -1;

  for (int i = 0; i < n; i++)
  {
    printf("%d %d\n", job[job_list[i]].first, job[job_list[i]].second);
  }
}