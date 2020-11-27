#include <iostream>
using namespace std;


const int N = 1e6 + 10;

int n;  // 键盘输入数组元素个数

int q[N];

void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;
    // 1.确定分界点x
    int x = q[l + r >> 1], i = l - 1, j = r + 1;  

    // 2.调整区间
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    // 3.递归处理
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);  
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n-1);

    for(int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}