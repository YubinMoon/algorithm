#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

#define Do 0
#define Gae 1
#define Gul 2
#define Yut 3
#define Mo 4

using namespace std;

/*
윷놀이를 구현하는 문제인듯 하다.
연속으로 던져도 말을 움직이는 순서는 변하지 않아 난이도가 높지 않다.
움직일 수 있는 말이 여러개라 움직이는 말별로 판을 새로 저장하는 게 좋을 것 같다.
칸이 번호별로 있어 말이 움직일 위치를 지정하기 번거로우니 각 자리에서 윷별로 움직일 번호를 미리 적어주었다.
*/

int map_route[][5] = {
    {1, 2, 3, 4, 5},
    {2, 3, 4, 5, 6},
    {3, 4, 5, 6, 7},
    {4, 5, 6, 7, 8},
    {5, 6, 7, 8, 9},

    {20, 21, 22, 23, 24},
    {7, 8, 9, 10, 11},
    {8, 9, 10, 11, 12},
    {9, 10, 11, 12, 13},
    {10, 11, 12, 13, 14},

    {25, 26, 22, 27, 28},
    {12, 13, 14, 15, 16},
    {13, 14, 15, 16, 17},
    {14, 15, 16, 17, 18},
    {15, 16, 17, 18, 19},

    {16, 17, 18, 19, 20},
    {17, 18, 19, 29, 30},
    {18, 19, 29, 30, 30},
    {19, 29, 30, 30, 30},
    {29, 30, 30, 30, 30},

    {21, 22, 23, 24, 15},
    {22, 23, 24, 15, 16},
    {27, 28, 29, 30, 30},
    {24, 15, 16, 17, 18},
    {15, 16, 17, 18, 19},

    {26, 22, 27, 28, 29},
    {22, 27, 28, 29, 30},
    {28, 29, 30, 30, 30},
    {29, 30, 30, 30, 30},
    {30, 30, 30, 30, 30},
};

typedef struct _status
{
    int turn, finish_a, finish_b; // 1 or -1
    int board[31];
} Status;

Status *copy_status(Status *status)
{
    Status *temp;
    temp = (Status *)malloc(sizeof(Status));
    for (int i = 0; i < 31; i++)
    {
        temp->board[i] = status->board[i];
    }
    temp->turn = status->turn;
    temp->finish_a = status->finish_a;
    temp->finish_b = status->finish_b;
    return temp;
}

Status *new_board(Status *status, int now_loc, int yut)
{
    int next_loc = map_route[now_loc][yut];
    int turn = status->turn;
    int piece_num = status->board[now_loc];
    int next_piece = status->board[next_loc] * turn;
    int *finish = turn > 0 ? &status->finish_a : &status->finish_b;

    status->board[now_loc] = 0;

    // 한바퀴 다 돌았을 때
    if (next_loc == 30)
        *finish += piece_num * turn;
    // 말 이동
    if (next_piece > 0)
    {
        status->board[next_loc] += piece_num;
    }
    else
    {
        status->board[next_loc] = piece_num;
        if (!(next_piece < 0 || yut == Yut || yut == Mo))
            status->turn = -turn;
    }
    return status;
}

int main(void)
{
    int T, U, N, A, B;
    char str[150];
    vector<int> UA, UB;
    queue<int> Y_list;
    queue<Status *> status_list;
    int tmp;
    scanf("%d", &T);
    for (int test_case = 0; test_case < T; test_case++)
    {
        UA.clear();
        UB.clear();
        scanf("%d %d %d %d", &U, &N, &A, &B);
        for (int i = 0; i < N; i++)
        {
            scanf("%s ", str);
            if (str[0] == 'D')
                Y_list.push(Do);
            else if (str[0] == 'Y')
                Y_list.push(Yut);
            else if (str[0] == 'M')
                Y_list.push(Mo);
            else if (str[1] == 'a')
                Y_list.push(Gae);
            else
                Y_list.push(Gul);
        }
        for (int i = 0; i < A; i++)
        {
            scanf("%d", &tmp);
            UA.push_back(tmp);
        }
        for (int i = 0; i < B; i++)
        {
            scanf("%d", &tmp);
            UB.push_back(tmp);
        }

        Status *status = (Status *)malloc(sizeof(Status));
        status->turn = 1;
        status->finish_a = 0;
        status->finish_b = 0;
        memset(status->board, 0x00, sizeof(int) * 31);
        status_list.push(status);
        while (!Y_list.empty())
        {
            int size = status_list.size(); // 계산할 게임판의 수
            int now_yut = Y_list.front();  // 계산할 윷
            Y_list.pop();
            for (int i = 0; i < size; i++)
            {
                status = status_list.front();
                status_list.pop();

                int turn = status->turn;
                int Y_count = 0; // 판 위 말 개수
                int finish_count = turn > 0 ? status->finish_a : status->finish_b;
                for (int j = 0; j < 30; j++)
                {
                    if (status->board[j] * turn > 0)
                    {
                        Status *tmp_status = copy_status(status);
                        new_board(tmp_status, j, now_yut);
                        Y_count += status->board[j] * turn;
                        status_list.push(tmp_status);
                    }
                }
                Y_count += finish_count;
                if (Y_count < U)
                {
                    Status *tmp_status = copy_status(status);
                    tmp_status->board[0] = tmp_status->turn;
                    new_board(tmp_status, 0, now_yut);
                    status_list.push(tmp_status);
                }
                free(status);
            }
        }
        int result = 0;
        while (!status_list.empty())
        {
            Status *status = status_list.front();
            status_list.pop();
            for (int i : UA)
            {
                status->board[i]--;
            }
            for (int i : UB)
            {
                status->board[i]++;
            }
            int count = 0;
            for (int i = 0; i < 30; i++)
            {
                if (status->board[i] != 0)
                {
                    count++;
                }
            }
            if (!count)
            {
                result = 1;
            }
            free(status);
        }
        printf("Case #%d: %s\n", test_case + 1, result ? "YES" : "NO");
    }
}