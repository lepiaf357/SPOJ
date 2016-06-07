#include <cstdio>

using namespace std;

// res in B
void matrix_mul_mod(long long A[2][2], long long B[2][2])
{
    long long C[2][2];
    
    C[0][0] = (A[0][0]*B[0][0] + A[0][1]*B[1][0]) % 1000000007;
    C[0][1] = (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % 1000000007;
    C[1][0] = (A[1][0]*B[0][0] + A[1][1]*B[1][0]) % 1000000007;
    C[1][1] = (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % 1000000007;
    
    B[0][0]=C[0][0];
    B[0][1]=C[0][1];
    B[1][0]=C[1][0];
    B[1][1]=C[1][1];
}

void fibonacci_matrix_pow(long long fibonacci_matrix_n[2][2], int n)
{   
    
    long long fibonacci_tmp[2][2];

    fibonacci_tmp[0][0] = 1;
    fibonacci_tmp[0][1] = 1;
    fibonacci_tmp[1][0] = 1;
    fibonacci_tmp[1][1] = 0;    
    
    fibonacci_matrix_n[0][0] = 1;
    fibonacci_matrix_n[0][1] = 0;
    fibonacci_matrix_n[1][0] = 0;
    fibonacci_matrix_n[1][1] = 1;
        
    while (n) 
    {
        if (n & 1) // my boyfriend is a genius :) Love him so much!
            matrix_mul_mod(fibonacci_tmp, fibonacci_matrix_n);
        
        matrix_mul_mod(fibonacci_tmp, fibonacci_tmp);
        n /= 2;
    }
}


/*
 * return F(n)
 * 
 *  |1   1|^n    | F(n+1)  F(n)   |
 *  |     |   =  |                |   
 *  |1   0|      | F(n)    F(n-1) |
 * 
 * fibonacci_first^n [0][0] = F(n+1)
 * fibonacci_first^(n-1) [0][0] = F(n)
 * 
 */
long long fibonacci(int n) 
{
    long long fibonacci_matrix_n[2][2];
    
    if (n == 0) 
        return 0;

    if (n == 1)
        return 1;
    
    fibonacci_matrix_pow(fibonacci_matrix_n, n-1);
    
    return fibonacci_matrix_n[0][0];
}

int main() {
    
    int N, M, t;
    long long sumN_1, sumM, res;
    
    scanf("%d", &t);
    
    while(t--) 
    {
        scanf("%d%d", &N, &M);
        
        // Sum[i=1...n] F(i) = F(n+2) - 1
        // F(i) = fibonacci(i)
        
        if (M == N)
        {
            res = fibonacci(M) % 1000000007;
        }
        else
        {
           sumM = fibonacci(M + 2);   // Sum 1...N-1 N...M  + 1
           sumN_1 = fibonacci(N + 1); // Sum 1...N-1        + 1
           res = (sumM - sumN_1) % 1000000007;
        }
        
        // (7 - 2) mod 3 = 7 mod 3 - 2 mod 3 = 1 - 2 = -1
        // (7 - 2) mod 3 = 5 mod 3 = 2
        // -1 + 3 = 2
        if (res < 0) 
            res += 1000000007;
        
        printf("%lld\n", res);
    }
    return 0;
}
