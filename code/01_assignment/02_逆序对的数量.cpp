#include <iostream>

using namespace std;

// 题目：求逆序对的数量

// 逆序对：对于数组的第i个元素和第j个元素，如果满足i < j且a[i] > a[j]，则称为一个逆序对，否则不是。

// 解题思路：先归并排序，后分以下三种情况讨论逆序对出现的情景：
        // 1.左半边内部的构成逆序对且数量是： merge_sort(L, mid)
        // 2.右半边内部的构成逆序对且数量是：merge_sort(mid + 1, R)
        // 3.左半边内部(从i指针指向位置开始)与右半边内部(j指针指向位置)构成逆序对且数量是：s_j = mid - i + 1

typedef long long LL;  // 由于最终的结果res会超过int的最大范围，所以使用long long

const int N = 100010;

int n;
int q[N], tmp[N];

LL merge_sort(int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;

    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);  // 逆序对的数量

    // 归并的过程
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else 
        {
            tmp[k++] = q[j++];
            res += mid - i + 1;  // 逆序对的数量
        }
    }

    // 扫尾
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    // 将排好序的数组tmp放回原数组q中
    for(int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
    return res;
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];

    cout << merge_sort(0, n - 1) << endl;
    return 0;
}