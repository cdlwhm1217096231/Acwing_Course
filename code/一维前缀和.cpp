#include <iostream>

using namespace std;


const int N = 100010;

int n, m;
int a[N], s[N];

int main()
{
    scanf("%d%d", &n, &m);
    // 注意：原数组下标从1开始
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];  // 前缀和的初始化

    while(m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);  // 区间和的计算
    }
    return 0;
}