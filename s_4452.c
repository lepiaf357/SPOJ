#include <stdio.h>
#include <string.h>

long long calculate(char op, long long left, long long right)
{
        switch (op)
        {
        case '+' :
                return left + right;
        case '-':
                return left - right;
        case '*':
                return left * right;
        case '/' :
                return left / right;
        case '=' :
                return left;
        default:
                return -1;
        }
}

int main()
{
        int n, i;
        char op;
        long long res, res2;

        scanf("%d", &n);
        while(n--)
        {
                scanf("%lld", &res);
                for (;;)
                {
                        scanf(" %c", &op);

                        if(op == '=')
                        {
                                break;
                        }

                        scanf("%lld", &res2);
                        res = calculate(op, res, res2);
                }
                printf("%lld\n", res);
        }
        return 0;
}
