#include <stdio.h>
using namespace std;
main()
{
	int r,s,t,n;
	scanf("%d %d %d %d",&r,&s,&t,&n);

	int p = s+t;

	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x<r) {
			printf("no\n");
			continue;
		}
		x-=r;
		x%=p;
		if(x<=s) printf("yes\n");
		else printf("no\n");
	}
}