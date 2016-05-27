#include <stdio.h>

int a[200001], aux[200001];
long long sum;
void merge(int *a, int i, int j, int len_l, int len_r)
{
     int k = i, i1 = i, j1 = j, r = i;

     while (i < i1 + len_l || j < j1 + len_r)
     {
          if (i == i1 + len_l)
          {
               while (j != j1 + len_r)
                    aux[k++] = a[j++];
          }
          else if (j == j1 + len_r)
          {
               while (i != i1 + len_l)
                    aux[k++] = a[i++];
          }
          else if (a[i] < a[j])
          {
               aux[k++] = a[i];
               i++;
          }
          else if (a[j] < a[i])
          {
               aux[k++] = a[j];
               sum += i1 + len_l - i;
               ++j;
          }

     }
     for (; r < i1 + len_l + len_r; ++r)
     {
          a[r] = aux[r];
     }
}
void sort(int *a, int i, int j, int len)
{
     if (len == 1)
          return ;
     int split = len / 2;
     sort(a, i, split + i - 1, split);
     sort(a, split + i, j, len - split);

     merge(a, i, split + i, split, len - split);
}
int main(void)
{
     int n, i;

     scanf("%d", &n);

     while (n--)
     {
          int a_len;
          scanf("%d", &a_len);
          sum = 0;
          for (i = 1; i <= a_len; ++i)
               scanf("%d", &a[i]);
          sort(a, 1, a_len, a_len);
          /* for (i = 1; i <= a_len; ++i) */
          /*      printf("%d ", a[i]); */
          printf("%lld\n", sum);
     }

     return 0;
}
