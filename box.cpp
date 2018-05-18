#include<stdio.h>
#include<stdlib.h>
char** arr;
int n,m;
bool dfs(int x,int y,int direction) {
	if (y >= m-1 || y < 0) return false;
	if (x < 0) return false;
	if (!(arr[x][y] == '.' && arr[x][y+1] == '.' && arr[x+1][y] == '.' && arr[x+1][y+1] == '.')) return false;
	if (x == n-2) return true;
	if(direction == 0) return (dfs(x+1,y,0) || dfs(x,y+1,2) || dfs(x,y-1,1));
	if(direction == 1) return (dfs(x+1,y,0) || dfs(x,y-1,1) || dfs(x-1,y,3));
	if(direction == 2) return (dfs(x+1,y,0) || dfs(x,y+1,2) || dfs(x-1,y,3));
	if(direction == 3) return (dfs(x,y-1,1) || dfs(x,y+1,2) || dfs(x-1,y,3));
}

main() {
	scanf("%d %d",&n,&m);
	arr = (char**)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; ++i)
	{
		arr[i] = (char*)malloc(sizeof(char)*m+1);
		scanf("%s",arr[i]);
	}

	for (int i = 0; i < m-1; ++i)
	{
		if(dfs(0,i,0)) {
			printf("yes\n");
			return 0;
		}
	}
	printf("no\n");

}