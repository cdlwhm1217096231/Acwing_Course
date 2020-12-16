#include <iostream>

using namespace std;

// 题目：定一个长度为n的数组，使用快速选择算法O(N)求数组中第k个小的元素

// 解题思路：
    // 1.确定分界点x: x的取法q[L]、q[L + R >> 1]、q[R]
    // 2.左边区间所有数Left <= x,右边区间所有数Right >= x
    // 3.递归处理左边区间或右边区间，其中左边区间所有元素的个数记为S_l,右边区间所有元素的个数记为S_r
        // 如果 k <= S_l,则递归处理左边区间Left
        // 如果 k > S_l,则递归处理右边区间Right，第k个小的元素位于右边区间的位置是k - S_l

const int N = 100010;

int n, k;
int q[N];

int quick_sort(int l, int r, int k)
{
    if(l == r) return q[l];

    int x = q[l], i = l - 1, j = r + 1;
    while(i < j)
    {
        while(q[++i] < x);
        while(q[--j] > x);
        
        if(i < j) swap(q[i], q[j]);
    }

    int sl = j - l + 1;
    if(k <= sl) return quick_sort(l, j, k);
    return quick_sort(j + 1, r, k - sl);
}



int main()
{
    cin >> n >> k;
    for(int i = 0;  i < n; i++) cin >> q[i];

    cout << quick_sort(0, n - 1, k) << endl;
    return 0;
}