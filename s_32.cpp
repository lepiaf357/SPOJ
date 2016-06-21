#include <cstdio>
#include <vector>
#include <cctype>

using namespace std;

const int B = 30;
const int M = 97;
int E = 1;
int n, m, count;
int hp = 0, ht = 0;
vector<int> text;
vector<int> pattern;

int mod(int a, int b)
{
     // printf(" a : %d\n", a);
     return (a % b + b) % b;
}
int check(int l, int r)
{
     for (int i = l, j = 0; i < r; ++i, ++j)
          if (text[i] != pattern[j])
               return 0;
     printf("%d\n", l);
}
int karpRabin()
{
     if (n < m)
          return 0;
     E = 1; count = 0;
     ht = hp = 0;
     for (int i = 0; i < m; ++i)
     {
          hp = mod(hp*B + pattern[i], M);

     }
     for (int i = 0; i < m-1; ++i)
          E = mod(E * B, M);
     for (int i = 0; i < m; ++i)
          ht = mod(ht*B + text[i], M);

      // printf("ht %d, hp %d\n ", ht, hp);
     if (ht == hp)
          count += check(0, m);

     for (int i = m; i < n; ++i)
     {
          ht = mod(ht - mod(text[i-m]*E, M), M);
          ht = mod(ht * B, M);
          ht = mod(ht + text[i], M);
           // printf("ht %d, hp %d\n ", ht, hp);
          if (ht == hp)
               count += check(i - m + 1, i + 1);
     }
     return count;
}
int main()
{
     while (scanf("%d", &m) > 0)
     {
          getchar();
          // printf("m : %d\n", m);
          for (int i = 0; i < m; ++i)
          {
               int temp;
               //scanf("%c", &temp);
               temp = getchar();
               //printf("%c\n", temp);
               pattern.push_back( temp - 'a' + 1);
          }
          getchar();
          n = 0;
          for (;;)
          {
               int temp ;
               // printf("%d \n", n);
               //scanf("%c", &temp);
               temp = getchar();
               if (!isalpha(temp))
                    break;
               text.push_back(temp-'a' + 1);
               ++n;
          }
          // printf("n : %d\n", n);
          // getchar();
          int result = karpRabin();
          if (result == 0)
               printf("\n\n");
          text.clear(); pattern.clear();
     }
     return 0;
}
