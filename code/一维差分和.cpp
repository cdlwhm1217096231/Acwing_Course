#include <iostream>


using namespace std;

const int N = 10001;

int n, m;
int a[N], b[N];   // a��ǰ׺�����飬b�ǲ������

// ��Ŀ�����볤��Ϊn�����飬����m��������ÿ������������������l��r��C,��ʾ������[l,r]�е�ÿ��������C����������������в���������顣

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
    // ��ǰ׺������a
    for(int i = 1; i <= n; i++) b[i] += b[i - 1];
    for(int i = 1; i <= n; i++) printf("%d ", b[i]);
    return 0;
}