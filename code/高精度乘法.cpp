#include <iostream>
#include <vector>
#include <string>

using namespace std;

// C = A * b
vector<int> mul(vector<int>& A, int b)
{
    vector<int> C;
    int t = 0;   // ��λ
    for(int i = 0; i < A.size() || t; i++)
    {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);  // ��˺����еĵ�iλ��C[i]
        t /= 10;   // ��˹����в����Ľ�λ
    }

     // ȥǰ��0
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}


int main()
{
    string a;
    int b;  // b����һ��С������
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = mul(A, b);
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}