#include <stdio.h>

int main()
{
	int N, M;
	int i, j = 0;
	int max = 0, sum = 0;
	int A[300000];

	scanf("%d%d", &N, &M);
	
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++)
	{
		sum += A[i];
		if (sum > M)
		{
			if ((sum - A[i]) > max)
			{
				max = sum - A[i];

			}
			while (sum > M)
			{
				sum -= A[j];
				j++;
			}
		}
		if (sum > max)
		{
			max = sum;
		} 
		if (sum == M)
		{
			max = M;
			break;
		}
	}
	printf("%d\n", max);

	return 0;
}
