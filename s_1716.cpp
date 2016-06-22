#include <cstdio>
#include <algorithm>

int a[50001];
int max_prefix[150000];
int max_suffix[150000];
int sum[150000];
int max_sum[150000];

void segmentTree(int node, int l, int r)
{
        if (l == r)
                sum[node] = max_prefix[node] = max_suffix[node] = max_sum[node] = a[l];
        else
        {
                int mid = l + (r-l)/2;

                segmentTree(2*node+1, l, mid);
                segmentTree(2*node+2, mid+1, r);

                sum[node] = sum[2*node+1] + sum[2*node+2];
                max_prefix[node] = max(max_prefix[2*node+1], max_prefix[2*node+2] + sum[2*node + 1]);
                max_suffix[node] = max(max_suffix[2*node+2], max_suffix[2*node+1] + sum[2*node + 2]);
                max_sum[node] = max(max(max_sum[2*node+1], max_sum[2*node+2]), max_suffix[2*node+1] + max_prefix[2*node+2]);
        }
}

int main()
{
    int n, m;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    segmentTree(0, 0, n-1);
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int b, x, y;
        scanf("%d%d%d", &b, &x, &y);
        
        if (b == 0)
        {
            //a[x] = y;
        }
        else
        {
            //printf("%d\n", max_sum(x,y));
        }
    }
    
    return 0;
}
