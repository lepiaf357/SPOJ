#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int a[100000];
int st[300000];

int myMin(int x, int y)
{
        if (x == INT_MAX)
                return y;
        if (y == INT_MAX)
                return x;
        return (a[x] > a[y]) ? y : x;
}

int buildST(int node, int l, int r)
{
        if (l == r)
        {
                st[node] = l;
                return l;
        }
        else
        {
                int mid = l + (r - l) / 2;

                int x = buildST(2*node+1, l, mid);
                int y = buildST(2*node+2, mid+1, r);
                st[node] = (a[x] > a[y]) ? y : x;
                return st[node];
        }
}
int RMQ(int node, int l, int r, int ql, int qr)
{
        if (ql > r || qr < l || l > r)
                return INT_MAX;

        if (l >= ql && r <= qr)
                return st[node];

        int mid = l + (r-l) / 2;

        return myMin(RMQ(2*node+1, l, mid, ql, qr), RMQ(2*node+2, mid+1, r, ql, qr));
}
long long getRectangle(int n, int l, int r)
{
        if (l > r)
                return INT_MIN;
        if (l == r)
                return a[l];

        int m = RMQ(0, 0, n-1, l, r);

        long long x = getRectangle(n, l, m-1);
        long long y = getRectangle(n, m+1, r);

        return max(max(x, y), (r-l+1)*((long long)a[m]));
}

int main()
{
        int n;
        for(;;)
        {
                scanf("%d", &n);
                if (n == 0)
                        break;

                for (int i = 0; i < n; ++i)
                        scanf("%d", &a[i]);
                buildST(0, 0, n-1);
                printf("%lld\n", getRectangle(n, 0, n-1));
        }
        return 0;
}
