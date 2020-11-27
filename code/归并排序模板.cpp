#include <iostream>

using namespace std;

const int N = 1000010;
int q[N], tmp[N]; // tmp[N]���ڴ�����Ľ��
int n;            // ������������Ԫ�صĸ���

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    // 1.ȷ���ֽ��mid
    int mid = l + r >> 1;

    // 2.�ݹ�������������������
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);


    int i = l, j = mid + 1, k = 0;
    // 3.�϶�Ϊһ
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    // ��������������䳤�Ȳ���ȣ�����Ҫ��������ʣ���Ԫ�ش�ŵ�tmp������
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    // 4.����ʱ�ź��������tmp���¸�ֵ������q,�������q������
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