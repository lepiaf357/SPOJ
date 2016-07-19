#include <cstdio>
#include <utility>

using namespace std;

#define TEST_CASES 10

char a[30001];
pair<int, int> st[70000];//first points to number of left open braces, second to number of right open braces

void buildST(int node, int l, int r)
{
        if (l == r)
        {
                if (a[l] == ')')
                {
                        st[node].first = 1;
                        st[node].second = 0;
                }
                else
                {
                        st[node].first = 0;
                        st[node].second = 1;
                }
                return ;
        }

        int mid = l + (r-l)/2;
        buildST(2*node+1, l, mid);
        buildST(2*node+2, mid+1, r);

        int a = st[2*node+1].second;
        int b = st[2*node+2].first;
        if (st[2*node+1].second > st[2*node+2].first)
        {
                a = st[2*node+1].second - st[2*node+2].first;
                b = 0;
        }
        else if (st[2*node+1].second < st[2*node+2].first)
        {
                b = st[2*node+2].first - st[2*node+1].second;
                a = 0;
        }
        else if (st[2*node+2].first == st[2*node+1].second)
                b = a = 0;

        st[node].first = b + st[2*node+1].first;
        st[node].second = a + st[2*node+2].second;
}

void updateST(int node, int l, int r, int k)
{
        if (k < l || k > r)
        {
                return;
        }
        if (r == l &&  r == k)
        {
                a[l] = (a[l] == ')' ? '(' : ')');
                if (a[l] == ')')
                {
                        st[node].first = 1;
                        st[node].second = 0;
                }
                else
                {
                        st[node].first = 0;
                        st[node].second = 1;
                }
                return;
        }
        int mid = l + (r-l)/2;

        updateST(2*node+1, l, mid, k);
        updateST(2*node+2, mid+1, r, k);

        int a = st[2*node+1].second;
        int b = st[2*node+2].first;
        if (st[2*node+1].second > st[2*node+2].first)
        {
                a = st[2*node+1].second - st[2*node+2].first;
                b = 0;
        }
        else if (st[2*node+1].second < st[2*node+2].first)
        {
                b = st[2*node+2].first - st[2*node+1].second;
                a = 0;
        }
        else if (st[2*node+2].first == st[2*node+1].second)
                b = a = 0;

        st[node].first = b + st[2*node+1].first;
        st[node].second = a + st[2*node+2].second;

}

int main()
{
        int n, m, k;

        for(int i=1; i <= TEST_CASES; i++)
        {
                scanf("%d", &n);
                scanf("%s", a);
                buildST(0, 0, n-1);
                scanf("%d", &m);
                printf("Test %d:\n", i);
                if (n & 1)
                {
                        for(int j=0; j < m; ++j)
                        {
                                int op;
                                scanf("%d", &op);
                                if(op == 0)
                                        printf("NO\n");
                        }
                }
                for(int j=0; j < m; ++j)
                {
                        int op;
                        scanf("%d", &op);

                        if(op == 0)
                        {
                                if (st[0].first == st[0].second && st[0].first == 0)
                                        printf("YES\n");
                                else
                                        printf("NO\n");
                        }
                        else
                                updateST(0, 0, n-1, op-1);

                }
        }
        return 0;
}
