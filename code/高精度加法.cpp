#include <iostream>
#include <vector>


using namespace std;


// res = A + B
vector<int> add(vector<int>& A, vector<int>& B)
{
    vector<int> res;

    if(A.size() < B.size()) return add(B, A);
    // 进位标志
    int c = 0;
    for(int i = 0; i < A.size(); i++)
    {
        c += A[i];
        if(i < B.size()) c += B[i];
        res.push_back(c % 10);   // A[i] + B[i]结果中第i位的数字
        c /= 10;   // A[i] + B[i]结果中第i位产生的进位
    }

    // 判断最高位是否还有进位
    if(c) res.push_back(1);
    return res;
}


int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;  // "1234567"
    // 1.大整数存储
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  // A = [7, 6, 5, 4, 3, 2, 1]
    for(int i = b.size() - 1; i >=0; i--) B.push_back(b[i] - '0');

    // 2.模拟人工加法过程
    auto C = add(A, B);
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}

