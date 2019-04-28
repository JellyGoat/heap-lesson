#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;
typedef long long int lli;
namespace my{
inline int lson(int rt){return rt<<1;}
inline int rson(int rt){return (rt<<1)+1;} 
inline int rt(int son){return son>>1;}
struct heap{
	//数据 
	lli data[100001];
	//记录节点个数 
	int cnt;
	//初始化 
	heap()
	{
		memset(data,0,sizeof(data));
		cnt=0;
	}
	inline int size(){return this->cnt;}
	inline void downdate(int p)
	{
		while ((p<<1)<=this->cnt)
		{
			int son;
			if (this->data[lson(p)]>=this->data[rson(p)])
				son=lson(p);
			else
				son=rson(p);
			if (this->data[p]>this->data[son])break;
			swap(this->data[p],this->data[son]);
			p=son;
		}
	}
	inline void update(int p)
	{
		while (p!=1)
		{
			if (this->data[rt(p)]>this->data[p])break;
			swap(this->data[rt(p)],this->data[p]);
			p=rt(p);
		}
	}
	inline void push(lli num)
	{
		this->data[++this->cnt]=num;
		this->update(this->cnt);
	}
	inline lli top(){return this->data[1];}
	inline void pop()
	{
		this->data[1]=this->data[this->cnt--];
		this->downdate(1);
	}
};
} 

int main()
{
	int n;
	my::heap _;
	cin>>n;
	for (register int i=1;i<=n;i++)
	{
		lli num;
		cin>>num;
		_.push(num);
	}
	for (register int i=1;i<=n;putchar(' '),i++)
	{
		cout<<_.top();
		_.pop();
	}
	return 0;
}
