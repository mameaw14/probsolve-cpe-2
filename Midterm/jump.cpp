#include<stdio.h>
#include<stdlib.h>
int** map;
int** mark;
int k,n;
bool findway(int i,int j,int h,int way) {
	//printf("%d\n", map[i][j]);
	if(mark[i][j] == 1) return 0;
	if(map[i][j] - h > k) return 0;
	if(i==n-1&&j==n-1) return 1;
	bool a=0,b=0,c=0,d=0;
	// if(i>0 && way != 1) {
	// 	a = findway(i-1,j,map[i][j],3);
	// }
	if(i<n-1 && way != 3) {
		b = findway(i+1,j,map[i][j],1);
	}
	// if(j>0 && way != 2) {
	// 	c = findway(i,j-1,map[i][j],4);
	// }
	if(j<n-1 && way != 4) {
		d = findway(i,j+1,map[i][j],2);
	}
	if(!(a|b|c|d)) mark[i][j] = 1;
	return a|b|c|d;
}
main() {
	scanf("%d %d",&n ,&k);
	map = (int**)malloc(sizeof(int*)*n);
	mark = (int**)calloc(sizeof(int*),n);
	for (int i = 0; i < n; ++i)
	{
	//printf("i\n" );
		map[i] = (int*)malloc(sizeof(int) * n);
		mark[i] = (int*)calloc(sizeof(int), n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&map[i][j]);
		}
	}

	bool a = findway(0,1,map[0][0],1);
	bool b = findway(1,0,map[0][0],2);

	//printf("n\n");
	if(a|b) {
		printf("yes\n");
	} else printf("no\n");
}