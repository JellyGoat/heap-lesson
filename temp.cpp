#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <time.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;
const double pi = acos(-1);
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, n, a) for (int i = n; i >= a; i--)
#define Rep(i, u) for (int i = head[u]; i; i = Next[i])
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
ld eps = 5e-7;
ll pp = 1000000007;
ll mo(ll a, ll pp)
{
    if (a >= 0 && a < pp)
        return a;
    a %= pp;
    if (a < 0)
        a += pp;
    return a;
}
ll powmod(ll a, ll b, ll pp)
{
    ll ans = 1;
    for (; b; b >>= 1, a = mo(a * a, pp))
        if (b & 1)
            ans = mo(ans * a, pp);
    return ans;
}
ll read()
{
    ll ans = 0;
    char last = ' ', ch = getchar();
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        ans = ans * 10 + ch - '0', ch = getchar();
    if (last == '-')
        ans = -ans;
    return ans;
}
//head

int n, m;
double a[100][100];

bool check(int k)
{
    rep(i, 1, n+1) if (fabs(a[k][i]) < eps) return 1;
    if (fabs(a[k][n + 1]) < eps)
        return 1;
    return 0;
}
int main()
{

    n = read();
    m = n;
    // a_i,1 a_i,2 ... a_i,n a_i,n+1
    rep(i, 1, m)
        rep(j, 1, n + 1) a[i][j] = read();

    int flag = 0;
    rep(i, 1, n)
    {
        int t = i;
        while (a[t][i] == 0 && t <= n)
            t += 1;
        if (t == n + 1)
        {
            flag = 1;
            continue;
        }
        rep(j, 1, n + 1) swap(a[i][j], a[t][j]);
        double kk = a[i][i];
        rep(j, 1, n + 1) a[i][j] /= kk;
        rep(j, 1, m) if (i != j)
        {
            double kk = a[j][i];
            rep(k, 1, n + 1)
                a[j][k] -= kk * a[i][k];
        }
    }
    if (flag)
    {
        rep(i, 1, m) if (!check(i))
        {
            cout << -1;
            return 0;
        }
        cout << 0;
        return 0;
    }
    rep(j, 1, m)
    {
        if (abs(a[j][n + 1] / a[j][j]) < 5e-3)
            printf("x%d=0\n", j);
        else
        {

            printf("x%d=%.2lf\n", j, a[j][n + 1] / a[j][j]);
        }
    }
}