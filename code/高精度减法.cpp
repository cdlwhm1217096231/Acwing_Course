#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 2.判断A是否大于等于B
bool cmp(vector<int>& A, vector<int>& B)
{
    // A、B两个大数的位数不相同情况
    if(A.size() != B.size()) return A.size() > B.size();
    // A、B两个大数的位数相同情况
    for(int i = A.size() - 1; i >= 0; i--)
        if(A[i] != B[i]) return A[i] > B[i];
    return true;
}


// 3.模拟人工减法过程 C = A - B
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for(int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }

    // 去掉前导0
    while(C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    // 1.利用数组存储大整数
    for (int i = A.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = B.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    if (cmp(A, B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    else {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }

    return 0;
}