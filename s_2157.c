#include <stdio.h>

int check(char *op1, int op1_len)
{
        int i = 0;
        for (; i <= op1_len; ++i)
                if (op1[i] < '0' || op1[i] > '9')
                        return 0;
        return 1;
}
int main(void)
{
        int n;
        char op1[100], op2[100], op3[100];

        scanf("%d", &n);
        while(n--)
        {
                int len, op1_len = 0, op2_len = 0, op3_len = 0;
                char c;

                scanf(" %c", &c);
                while (c != ' ')
                {
                        op1[op1_len++] = c;
                        scanf("%c", &c);
                }
                op1_len--;
                getchar();//+
                scanf(" %c", &c);
                while (c != ' ')
                {
                        op2[op2_len++] = c;
                        scanf("%c", &c);
                }
                op2_len--;
                getchar();//=
                scanf(" %s", op3);
                for (op3_len = 0; op3[op3_len] != '\0'; ++op3_len);
                --op3_len;
                op1[op1_len+1] = op2[op2_len + 1] = op3[op3_len + 1] = '\0';
                if (!check(op1, op1_len))
                        printf("%d + %d = %d\n", atoi(op3) - atoi(op2), atoi(op2), atoi(op3));
                else if (!check(op2, op2_len))
                        printf("%d + %d = %d\n", atoi(op1), atoi(op3) - atoi(op1), atoi(op3));
                else if (!check(op3, op3_len))
                        printf("%d + %d = %d\n", atoi(op1), atoi(op2),  atoi(op1) + atoi(op2));
        }
        return 0;
}
