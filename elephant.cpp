#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	int arr[n+1];
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&arr[i]);	
	}
	int* p = (int*)calloc(sizeof(int),n+1);
	for (int i = 3; i <= n; ++i)
	{
		p[i] = max(arr[i]+p[i-3],p[i-1]);
	}
	printf("%d\n", p[n]);
}