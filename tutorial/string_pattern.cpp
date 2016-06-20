// Serching a pattern in a string
// A naive approach
// The best case is when a string is not present at all O(n)
// The worst case is when all characters of text string and pattern string are the same O(m*(n-m+1))

#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
        char text[1000];
        char pattern[100];

        scanf("%s%s", text, pattern);
        int n = strlen(text);
        int m = strlen(pattern);
        int i;
        for (i = 0; i <= n - m; ++i)
        {
                int j;
                for (j = 0; j < m; ++j)
                        if (text[i+j] != pattern[j])
                                break;
                if (j == m)
                        printf("Found a match at %d position\n", i);
        }

        return 0;
}
