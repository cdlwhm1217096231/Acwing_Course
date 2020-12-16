#include <iostream>

using namespace std;

// ��Ŀ��������Ե�����

// ����ԣ���������ĵ�i��Ԫ�غ͵�j��Ԫ�أ��������i < j��a[i] > a[j]�����Ϊһ������ԣ������ǡ�

// ����˼·���ȹ鲢���򣬺���������������������Գ��ֵ��龰��
        // 1.�����ڲ��Ĺ���������������ǣ� merge_sort(L, mid)
        // 2.�Ұ���ڲ��Ĺ���������������ǣ�merge_sort(mid + 1, R)
        // 3.�����ڲ�(��iָ��ָ��λ�ÿ�ʼ)���Ұ���ڲ�(jָ��ָ��λ��)����������������ǣ�s_j = mid - i + 1

typedef long long LL;  // �������յĽ��res�ᳬ��int�����Χ������ʹ��long long

const int N = 100010;

int n;
int q[N], tmp[N];

LL merge_sort(int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;

    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);  // ����Ե�����

    // �鲢�Ĺ���
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else 
        {
            tmp[k++] = q[j++];
            res += mid - i + 1;  // ����Ե�����
        }
    }

    // ɨβ
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    // ���ź��������tmp�Ż�ԭ����q��
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