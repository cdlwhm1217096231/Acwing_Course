#include <iostream>


using namespace std;

const int N = 10001;

int n, m;
int a[N], b[N];   // a是前缀和数组，b是差分数组

// 题目：输入长度为n的数组，进行m个操作，每个操作包含三个整数l、r、C,表示将区间[l,r]中的每个数加上C。求输出进行完所有操作后的数组。

void insert(int l, int r, int C)
{
    b[l] += C;
    b[r + 1] -= C;
}


int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for(int i = 1; i <=n; i++) insert(i, i, a[i]);
    while(m--)
    {
        int l, r, C;
        scanf("%d%d%d", &l, &r, &C);
        insert(l, r, C);
    }
    // 求前缀和数组a
    for(int i = 1; i <= n; i++) b[i] += b[i - 1];
    for(int i = 1; i <= n; i++) printf("%d ", b[i]);
    return 0;
}