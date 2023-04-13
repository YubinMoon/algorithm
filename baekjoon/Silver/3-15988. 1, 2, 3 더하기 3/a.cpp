#include <cstdio>
#include <cstring>

#define MAX_OUTPUT 1000000009
#define BOX_LEN 1000001

int main(void)
{
    int t, n, last = 3;
    int box[BOX_LEN];
    memset(box, 0x00, BOX_LEN);
    box[1] = 1;
    box[2] = 2;
    box[3] = 4;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        while (n > last)
        {
            last++;
            box[last] = (box[last - 1] + box[last - 2]) % MAX_OUTPUT;
            box[last] = (box[last] + box[last - 3]) % MAX_OUTPUT;
        }
        printf("%d\n", box[n]);
    }
    return 0;
}
