#include<stdio.h>
main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		arr[i] = -1;
	}
	for (int i = 0; i < m; ++i)
	{
		int c,g;
		scanf("%d %d",&c,&g);
		if (arr[c]==-1) arr[c] = g;
		else if (arr[c] > g) arr[c] = g;
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += arr[i];
	}
	printf("%d\n", sum);
	for (int i = 1; i <= n; ++i)
	{
		printf("%d %d\n",i, arr[i] );
	}
}