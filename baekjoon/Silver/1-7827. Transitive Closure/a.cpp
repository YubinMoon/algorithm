#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    int T;
    int N, M;
    int v, u;
    int sum;
    bool visited[2501] = {0};
    vector<vector<int>> link(2501, vector<int>(0));
    stack<int> node;
    scanf("%d", &T);
    while (T--)
    {
        link.clear();
        link.assign(2501, vector<int>(0));
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &v, &u);
            link[v].push_back(u);
        }
        sum = 0;
        for (int i = 1; i <= N; i++)
        {
            memset(visited, 0, N + 1);
            node.push(i);
            while (!node.empty())
            {
                v = node.top();
                node.pop();
                if (!visited[v])
                {
                    visited[v] = 1;
                    sum += 1;
                    for (int u : link[v])
                    {
                        node.push(u);
                    }
                }
            }
            sum -= 1;
        }
        printf("%d\n", sum);
    }
}