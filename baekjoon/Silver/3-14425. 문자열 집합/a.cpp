// 14425
// 문자열 집합

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int get_hash(const char *str)
{
  unsigned int hash = 0;
  int prime = 6037;
  for (int i = 0; str[i] != 0; i++)
  {
    hash += str[i];
    hash *= prime;
    hash %= 20000;
  }
  return hash;
}

int main()
{
  int n, m, hash, result = 0;
  char *str;
  vector<const char *> table[20000];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    str = new char[501];
    scanf("%s", str);
    hash = get_hash(str);
    table[hash].push_back(str);
  }
  for (int i = 0; i < m; i++)
  {
    str = new char[501];
    scanf("%s", str);
    hash = get_hash(str);
    for (const char *ss : table[hash])
    {
      if (strcmp(ss, str) == 0)
      {
        result++;
        break;
      }
    }
  }
  printf("%d\n", result);
}