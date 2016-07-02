#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f(char **a)
{
     *a = malloc(10 * sizeof (char));
     strcpy(*a, "WWW");
}

int main()
{
     char *a = "HELLO";
     printf("%s\n", a);
     f(&a);
     printf("%s\n", a);
     return 0;
}
