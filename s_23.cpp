#include <cstdio>
#include <cmath>

int main()
{
    double U, V, W, u, v, w;
    double a, b, c, d;
    double volume;
    int t;
    
    scanf("%d", &t);
    
    while (t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &U, &W, &v, &V, &w, &u);
        a = sqrt((U-v+w)*(v-w+U)*(u-V+w)*(V+u+w)*(v-W+u)*(W+u+v));
        b = sqrt((V-w+u)*(w-u+V)*(v-W+u)*(W+u+v)*(w-U+v)*(U+w+v));
        c = sqrt((W-u+v)*(u-v+W)*(w-U+v)*(U+w+v)*(u-V+w)*(V+u+w));
        d = sqrt((U-v+w)*(v-w+U)*(V-w+u)*(w-u+V)*(W-u+v)*(u-v+W));
        volume = sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d));
        volume = volume / (192*u*v*w);
        printf("%.4lf\n", volume);
    }
    
    return 0;
}