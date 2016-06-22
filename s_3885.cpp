// Players play until they reach a terminal pos
// The player who can't make any move is declared a looser.
// Rules:
// 1. All terminal positions are loosing.
// 2. If a player is able to move to a loosing position he is in a winning position.
// 3. If a player is able to move to a wining position he is in a loosing position.

#include <cstdio>
#include <cstring>

using namespace std;

#define W 1
#define L 2

int outcome[1000001];

void outcomeSolve(int l, int k)
{
     int i;
     outcome[0] = L;
     outcome[1] = W;
     for (i = 2; i < l; ++i)
          if (outcome[i - 1] == L)
               outcome[i] = W;
          else
               outcome[i] = L;
     outcome[i] = W;
     i++;
     for (; i < k; ++i)
          if (outcome[i - 1] == L || outcome[i - l] == L)
               outcome[i] = W;
          else
               outcome[i] = L;
     outcome[i] = W;
     i ++;
     for (; i <= 1000001; ++i)
     {
          if (outcome[i - 1] == L || outcome[i - l] == L || outcome[i - k] == L)//dati prednost poziciji pobede. optimalnost
               outcome[i] = W;
          else
               outcome[i] = L;
     }
}

int main()
{
     int n, k, l, coin;

     scanf("%d%d%d", &l, &k, &n);
     outcomeSolve(l, k);
     while (n--)
     {
          scanf("%d", &coin);
          if (outcome[coin] == W)
               printf("A");
          else
               printf("B");
     }
     printf("\n");
     return 0;
}
