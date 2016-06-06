#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getSumUtil(int *st, int node, int l, int r, int ql, int qr)
{
        if (l >= ql && r <= qr)
                return st[node];
        if (ql > r || qr < l)
                return 0;
        int mid = l + (r-l)/2;

        return getSumUtil(st, 2*node+1, l, mid, ql, qr) + getSumUtil(st, 2*node+2, mid+1, r, ql, qr);
}

int getSum(int *st, int n, int ql, int qr)
{
        return getSumUtil(st, 0, 0, n-1, ql, qr);
}

int constructSTUtil(int arr[], int *st, int node, int l, int r)
{
        if (r == l)
        {
                st[node] = arr[l];
                return arr[l];
        }
        int mid = l + (r-l)/2;

        st[node] = constructSTUtil(arr, st, 2*node+1, l, mid) + constructSTUtil(arr, st, 2*node+2, mid+1, r);

        return st[node];
}

int *constructST(int arr[], int n)
{
        int x = (int) ceil(log2(n));
        int max_size = 2*(int)pow(2, x) - 1;
        int *st = malloc(max_size * sizeof *st);

        constructSTUtil(arr, st, 0, 0, n-1);

        return st;
}

void updateValueUtil(int *st, int node, int l, int r, int i, int diff)
{
        if (i < l || i > r)
                return ;
        st[node] += diff;

        int mid = l + (r-l)/2;
        if (l < r)
        {
                updateValueUtil(st, 2*node+1, l, mid, i, diff);
                updateValueUtil(st, 2*node +2, mid+1, r, i, diff);
        }

}

void updateValue(int *arr, int *st, int n, int i, int new_val)
{
        int diff = new_val - arr[i];
        arr[i] = new_val;

        updateValueUtil(st, 0, 0, n-1, i, diff);
}

int main()
{
        int arr[] = {1, 3, 5, 7, 9, 11};
        int n = sizeof arr / sizeof *arr;

        int *st = constructST(arr, n);
        printf("Sum of values in given range = %d\n",
               getSum(st, n, 1, 3));

        // Update: set arr[1] = 10 and update corresponding
        // segment tree nodes
        updateValue(arr, st, n, 1, 10);

        // Find sum after the value is updated
        printf("Updated sum of values in given range = %d\n",
               getSum(st, n, 1, 3));
        return 0;

}
