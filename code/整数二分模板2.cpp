
// ����ʵ����Ŀ������дcheck()���������x�Ƿ�����ĳ������
bool check(int x) 
{

}

// ����[l, r]�����ֳ�[l, mid]��[mid + 1, r]ʱʹ��
int bsearch_1(int l, int r)
{
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;  // check()�ж�mid�Ƿ���������
        else l = mid + 1;
    }
    return l;
}