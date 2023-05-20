#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>
#include <queue>

#define MAX_SIZE

using namespace std;

inline int get_num(int a, int b, int c) { return a * 201 * 201 + b * 201 + c; }

int map[201 * 201 * 201] = {0};
queue<tuple<int, int, int>> q;

void a2b(int &a, int &b, int max_b)
{
    int rb = max_b - b;
    int ca = a > rb ? a - rb : 0;
    int cb = a > rb ? max_b : b + a;
    a = ca;
    b = cb;
}

void insert(int a, int b, int c)
{
    if (!map[get_num(a, b, c)])
    {
        q.push(make_tuple(a, b, c));
        map[get_num(a, b, c)] = 1;
    }
}

int main(void)
{
    int A, B, C;
    int a, b, c;
    int ca, cb, cc;
    scanf("%d %d %d", &A, &B, &C);
    q.push(make_tuple(0, 0, C));
    map[get_num(0, 0, C)] = 1;

    while (!q.empty())
    {
        tuple<int, int, int> tuple = q.front();
        tie(a, b, c) = tuple;
        ca = a;
        cb = b;
        cc = c;
        if (a)
        {
            a2b(ca, cb, B);
            insert(ca, cb, cc);
            ca = a, cb = b;

            a2b(ca, cc, C);
            insert(ca, cb, cc);
            ca = a, cc = c;
        }
        if (b)
        {
            a2b(cb, ca, A);
            insert(ca, cb, cc);
            ca = a, cb = b;

            a2b(cb, cc, C);
            insert(ca, cb, cc);
            cb = b, cc = c;
        }
        if (c)
        {
            a2b(cc, ca, A);
            insert(ca, cb, cc);
            ca = a, cc = c;

            a2b(cc, cb, B);
            insert(ca, cb, cc);
            cb = b, cc = c;
        }
        q.pop();
    }
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            if (map[get_num(0, j, i)])
            {
                printf("%d ", i);
                break;
            }
        }
    }
    printf("\n");
}