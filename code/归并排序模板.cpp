#include <iostream>

using namespace std;

const int N = 1000010;
int q[N], tmp[N]; // tmp[N]用于存放最后的结果
int n;            // 待排序数组中元素的个数

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    // 1.确定分界点mid
    int mid = l + r >> 1;

    // 2.递归排序处理左右两边区间
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);


    int i = l, j = mid + 1, k = 0;
    // 3.合二为一
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    // 如果左右两边区间长度不相等，还需要更长区间剩余的元素存放到tmp数组中
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    // 4.将临时排好序的数组tmp重新赋值给数组q,完成数组q的排序
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}