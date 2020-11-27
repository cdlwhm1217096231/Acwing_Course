#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// C = A / b, 商是C, 余数是r
vector<int> div(vector<int>& A, int b, int& r)
{
    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0; i--)  // 注意除法是从高位到低位开始执行除法运算
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= 10;
    }
    reverse(C.begin(), C.end());
    // 去前导0
    while (C.size() > 1 && C.back() == 0) C.pop_back();return C;
}



int main()
{
    string a;
    int b, r;
    
    cin >> a >> b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--)  A.push_back(a[i] - '0');

    auto C = div(A, b, r);
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    cout << endl << r << endl;
    return 0;
}