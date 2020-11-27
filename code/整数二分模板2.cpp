
// 根据实际题目场景编写check()函数，检查x是否满足某种性质
bool check(int x) 
{

}

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用
int bsearch_1(int l, int r)
{
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;  // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}