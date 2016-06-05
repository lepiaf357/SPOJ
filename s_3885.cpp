#include <cstdio>

int isWinning_r(int coin, int k, int l, int player)
{
     if (coin == 0 && player == 1)
          return 1;
     if (coin == 0 && player == 0)
          return 0;
     // if (coin < 0 && player == 0)
     //      return 0;
     // if (coin < 0 && player == 1)
     //      return 0;
     int a, b, c;
     a = isWinning_r(coin - 1, k, l, (player+1)%2);
     b = isWinning_r(coin - k, k, l, (player+1)%2);
     c = isWinning_r(coin - l, k, l, (player+1)%2);
     return a || b || c;
}

int main()
{
     int n, k, l, coin;

     scanf("%d%d%d", &l, &k, &n);
     while (n--)
     {
          scanf("%d", &coin);
          if (isWinning_r(coin, k, l, 0))
               printf("A");
          else
               printf("B");
     }
     return 0;
}
