#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAXN = 40; // ????
const int MAXHFN = MAXN / 2;

// 원소는 데이터의 (n, n)에서 + 모양으로 다 더한 값 
int arr[MAXN];
vector<int> psum[2];

inline int readint() { int n; scanf("%d", &n); return n; }

int main() {
    int n = readint();
    int hfn = n / 2;

    int tg = 0; // 모두 한팀일 때 점수 = 전체 구역 색칠

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int v = readint();
            tg += v;
            arr[i] += v;
            arr[j] += v;
        }
    }

    // 계산을 줄이기 위해 절반씩 나누기
    for (int ipsum = 0; ipsum < 2; ++ipsum) {
        int offs = hfn * ipsum;
        int sl = ipsum == 0 ? hfn : n - hfn;
        int s = 0;
        int cnt = 0;
        // +로 색칠된 부분 경우의 수 벡터에 저장 (이 때 +끼리 겹치는 부분이 생기고 겹치는 부분이 함 팀, 색이 칠해져 있지 않은 게 한 팀)
        for (int i = 0; i < (1 << sl); ++i) {
            if (i > 0) {
                int t = i;
                int it = 0;
                while (!(t & 1)) t >>= 1, ++it;
                int sgn = (t >> 1) & 1 ? -1 : 1;
                s += sgn * arr[offs + it];
            }

            psum[ipsum].push_back(s);
        }
        sort(psum[ipsum].begin(), psum[ipsum].end());
    }

    int res = tg; // all nonnegative so ok

    if (1) {
        const vector<int> &lf = psum[0];
        const vector<int> &rg = psum[1];
        const int szl = lf.size();
        const int szr = rg.size();

        // tg = 전체 영역, c = +로 색칠 된 부분의 합 
        // 즉 색칠된 부분에서 전체를 빼면 겹쳐진 부분은 +가 빈 부분은 -가 되므로 최소를 구할 수 있음
        for (int il = 0, ir = szr - 1; il < szl && ir >= 0; ) {
            int c = lf[il] + rg[ir];
            res = min(res, abs(c - tg));
            if (c == tg) {
                break;
            } else if (c < tg) {
                ++il;
            } else {
                --ir;
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
