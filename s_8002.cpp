#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> a;
vector<long long> tree;

void updateST(int node, int l, int r, int ql, int qr, long long val)
{
        if (qr < l || ql > r)
                return ;
        if (ql >= l && qr <= r)
                tree[node] += (qr - ql + 1)*val;
        else if (ql < l)
                tree[node] += (qr - l + 1)*val;
        else if (qr > r)
                tree[node] += (r - ql + 1)*val;

        int mid = l + (r - l) / 2;
        if (l < r)
        {
                updateST(2*node+1, l, mid, ql, qr, val);
                updateST(2*node+2, mid+1, r, ql, qr, val);
        }
        // else
        //         printf("L < R");
}

long long queryST(int node, int l, int r, int ql, int qr)
{
        if (ql > r || qr < l)
                return 0;
        if (ql <= l && qr >= r)
                return tree[node];
        int mid = l + (r - l) / 2;

        return queryST(2*node+1, l, mid, ql, qr) + queryST(2*node+2, mid+1, r, ql, qr);
}

int main()
{
        int t, n, c;

        a.reserve(100000);
        tree.reserve(300000);

        scanf("%d", &t);
        while(t--)
        {
                scanf("%d%d", &n, &c);
                a.assign(n, 0);
                int depth = ceil(log2(n));
                tree.assign(2 * (int)pow(2, depth), 0);
                for (int i = 0; i < c; ++i)
                {
                        int operation;
                        scanf("%d", &operation);
                        if (!operation)//update
                        {
                                int l, r;
                                long long val;
                                scanf("%d%d%lld", &l, &r, &val);
                                --l; --r;
                                for (int i = l; i <= r; ++i)
                                        a[i] += val;
                                updateST(0, 0, n-1, l, r, val);
                        }
                        else//query
                        {
                                int l, r;
                                scanf("%d%d", &l, &r);
                                --l; --r;
                                printf("%lld\n", queryST(0, 0, n-1, l, r));
                        }
                }
        }
        return 0;

}
