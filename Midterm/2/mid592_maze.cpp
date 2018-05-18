#include <stdio.h>
#include <stdlib.h>
char** map;
int** mark;
int k,n;
bool findway(int i,int j,int di,int dj,int way,bool key) {
	if(i<0||i>=n||j<0||j>=n) return 0;
	bool removeblock = 0;
	if(map[i][j]=='#') return 0;
	 if(mark[i][j] == 1) return 0;
	mark[i][j] = 1;
	if(i==di&&j==dj) {
		 // printf("Found!\n");
		return 1;
	}
	if(map[i][j]=='O') {
		// printf("use");
		if(key) {
			map[i][j] = '#';
			removeblock = 1;
			key = 0;
		} else return 0;
	}
	// printf("%d %d %d\n",i,j,way );
	bool a=0,b=0,c=0,d=0;
	if(i>0 && way != 1) {
		a = findway(i-1,j,di,dj,3,key);
	}
	if(i<n-1 && way != 3 && !a) {
		b = findway(i+1,j,di,dj,1,key);
	}
	if(j>0 && way != 2 && !a && !b) {
		c = findway(i,j-1,di,dj,4,key);
	}
	if(j<n-1 && way != 4 && !a &&!b &&!c) {
		d = findway(i,j+1,di,dj,2,key);
	}
	if(removeblock) map[i][j] = 'O';
	// printf(" - %d\n", a|b|c|d);
	return a|b|c|d;
}
main() {
	scanf("%d %d",&n ,&k);
	map = (char**)malloc(sizeof(char*)*n);
	mark = (int**)calloc(sizeof(int*),n);
	for (int i = 0; i < n; ++i)
	{
	//printf("i\n" );
		map[i] = (char*)malloc(sizeof(char) * n+1);
		mark[i] = (int*)calloc(sizeof(int), n);
		scanf("%s",map[i]);
		// printf("%s\n",map[i] );
	}

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int l = 0; l < n; ++l)
			{
				mark[j][l] = 0;
			}
		}
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		x1--,y1--,x2--,y2--;
		bool a = findway(x1-1,y1,x2,y2,1,1);
		// printf("+\n");
		for (int j = 0; j < n; ++j)
		{
			for (int l = 0; l < n; ++l)
			{
				mark[j][l] = 0;
			}
		}
		bool b = findway(x1,y1+1,x2,y2,2,1);
		for (int j = 0; j < n; ++j)
		{
			for (int l = 0; l < n; ++l)
			{
				mark[j][l] = 0;
			}
		}
		// printf("+\n");
		bool c = findway(x1,y1-1,x2,y2,3,1);
		for (int j = 0; j < n; ++j)
		{
			for (int l = 0; l < n; ++l)
			{
				mark[j][l] = 0;
			}
		}
		// printf("+\n");
		bool d = findway(x1-1,y1,x2,y2,4,1);
		if(a|b|c|d) {
			printf("yes\n");
		} else 
		printf("no\n");
	}

}