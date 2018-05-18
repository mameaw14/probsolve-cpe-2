#include <stdio.h>
#include <map>
using namespace std;

main() {
	map<int,int> order;
	map<int,int> count;
	int m=0;
	int n;
	while(1==scanf("%d",&n)) {
		if(count[n]==0) {
			order[m++] = n;
		}
			count[n]++;
	}
	for (int i = 0; i < m; ++i)
	{
		printf("%d %d\n",order[i],count[order[i]] );
	}
}