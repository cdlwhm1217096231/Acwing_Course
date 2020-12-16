#include <iostream>

using namespace std;

// ��Ŀ����һ������Ϊn�����飬ʹ�ÿ���ѡ���㷨O(N)�������е�k��С��Ԫ��

// ����˼·��
    // 1.ȷ���ֽ��x: x��ȡ��q[L]��q[L + R >> 1]��q[R]
    // 2.�������������Left <= x,�ұ�����������Right >= x
    // 3.�ݹ鴦�����������ұ����䣬���������������Ԫ�صĸ�����ΪS_l,�ұ���������Ԫ�صĸ�����ΪS_r
        // ��� k <= S_l,��ݹ鴦���������Left
        // ��� k > S_l,��ݹ鴦���ұ�����Right����k��С��Ԫ��λ���ұ������λ����k - S_l

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