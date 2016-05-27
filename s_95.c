//#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
        stack<int> st;
        int n;

        scanf("%d", &n);

        while(n != 0)
        {
                int i, next, tmp, f = 1;

                for(i = 0, next = 1; i < n; i++)
                {
                        scanf("%d", &tmp);

                        if(tmp == next)
                        {
                                next++;
                                continue;
                        }
                        else
                        {
                                if(st.empty())
                                {
                                        st.push(tmp);
                                        continue;
                                }
                                else
                                {
                                        if(st.top() == next)
                                        {
                                                do
                                                {
                                                        st.pop();
                                                        next++;
                                                } while (!st.empty() && st.top() == next);
                                                st.push(tmp);
                                        }
                                        else if(st.top() < tmp)
                                        {
                                                printf("no\n");
                                                f = 0;
                                                ++i;
                                                for( ; i < n; i++)
                                                        scanf("%d", &tmp);

                                        }
                                        else
                                                st.push(tmp);
                                }
                        }
                }
                while(!st.empty())
                        st.pop();

                if(f)
                        printf("yes\n");
                scanf("%d", &n);
        }
        return 0;
}
