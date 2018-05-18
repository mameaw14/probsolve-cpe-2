#include <stdio.h>
#include <cstdlib>
using namespace std;
bool** g;
int* arr;
int n,m,h;
void dfs(int now,int h) {
	if(g[now][now]) return;
	arr[now]++;
	g[now][now] = 1;
	if(h==0) return;
	for (int i = 1; i < n+1; ++i)
	{
		if(g[now][i]) dfs(i,h-1);
	}
}

main()
{
	scanf("%d %d %d",&n,&m,&h);
	arr = (int*)calloc(sizeof(int),n+1);
	g = (bool**)calloc(sizeof(bool*),n+1);
	for (int i = 0; i < n+1; ++i)
	{
		g[i] = (bool*)calloc(sizeof(bool),n+1);
	}
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		g[a][b] = 1;
		g[b][a] = 1;
	}	
	for (int i = 1; i < n+1; ++i)
	{
		arr[i]--;
		for (int j = 1; j < n+1; ++j)
		{
			g[j][j] = 0;
		}
		dfs(i,h);
		// printf("\n" );
	}
	int mx = 0;
	for (int i = 1; i < n+1; ++i)
	{
		// printf("= %d %d\n",i, arr[i] );
		if(arr[i] > mx) mx = arr[i];
	}
	printf("%d\n",mx+1 );
}