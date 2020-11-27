
// 根据实际题目场景编写check()函数，检查x是否满足某种性质
bool check(int x) 
{

}


// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用
int bsearch_2(int l, int r)
{
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}