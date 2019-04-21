#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;
template <typename T_>
inline T_ getnum()
{
    T_ res = 0;
    bool flag = false;
    char ch = getchar();
    while (!isdigit(ch))
    {
        flag = flag ? flag : ch == '-';
        ch = getchar();
    }
    while (isdigit(ch))
    {
        res = (res << 3) + (res << 1) + ch - '0';
        ch = getchar();
    }
    return res;
}

namespace my
{
struct heap
{
    lli data[100001] = {0};
    int size_;
    inline int size() { return this->size_; }
    //上浮
    inline void update(int leaf)
    {
        //以大根堆为例子
        while (leaf >= 0)
        {
            //若已经满足便退出循环
            if (data[leaf >> 1] >= data[leaf])
                break;
            swap(data[leaf], data[leaf >> 1]);
            leaf >>= 1;
        }
    }
    //插入
    inline void insert(lli num)
    {
        data[++size_] = num;
        update(size_);
    }
    //最上面的元素必定是最大的
    inline lli top() { return this->data[1]; }
    //下沉
    inline void downdate(int root)
    {
        //当root仍然不是叶子结点的时候
        while ((root << 1) <= size_)
        {
            //找一个最大的儿子的下标
            int y = data[root << 1] >= data[(root << 1) + 1] ? (root << 1) : ((root << 1) + 1);
            if (data[root] > data[y])
                break;
            //比最大的儿子都大，那肯定满足堆序
            swap(data[y], data[root]);
            root = y;
        }
    }
    //迎合python习惯，返回堆顶的值
    inline lli pop()
    {
        lli res = data[1];
        swap(data[1], data[size_]);
        size_--;
        downdate(1);
        return res;
    }
};
} // namespace my

int main()
{
#ifdef WIN32
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w+", stdout);
#endif // WIN32
    int n;
    my::heap _;
    for (register int i = 1; i <= n; i++)
    {
        lli num = getnum<lli>();
        _.insert(num);
    }
    for (register int i = 1; i <= n; i++)
    {
        cout << _.pop() << ' ';
    }
    return 0;
}
