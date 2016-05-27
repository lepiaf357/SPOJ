#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define x printf
#define z else
#define M(q,w,e,r) if(m==1) x("%d\n",q); z if(m==2) x("%d\n",w); z if(m==3) x("%d\n",e); z x("%d\n",r); break
int main()
{
char c,*s=malloc(19);int n,a,b,l,m;scanf("%d",&n);
while(n>0)
{
while((c=getchar())!=' ')
a=c-'0';scanf("%s",s);l=strlen(s);
if(l==1)
b=atoi(s);
z
b=(s[l-2]-'0')*10+s[l-1]-'0';if(b == 0 && l == 1) x("1\n");
z if(a==0 || a==1 || a==5 || a==6) x("%d\n", a);
z if(a==4)
{
if(b%2==0) x("6\n");
z
x("4\n");
}
z if(a==9)
{
if(b%2==0) x("1\n");z x("9\n");}z{m=b%4;switch(a){case 2: M(2,4,8,6);case 3: M(3,9,7,1);case 7: M(7,9,3,1);case 8: M(8,4,2,6);}}n--;}return 0;}
