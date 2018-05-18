#include <stdio.h>
using namespace std;
main()
{
	int r,c,b,t;
	scanf("%d %d %d %d",&r,&c,&b,&t);
	int refill = 1;
	int now = b;
	bool not_refill = false;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int d;
			scanf("%d",&d);
			if(d && not_refill) {
				refill++;
				now = b;
				not_refill = false;
			}
			while(d>0) {
				if(now >= t) {
					now -= t;
					d--;
				} else {
					now = b;
					refill++;
				}
			}
		}
		not_refill = true;
	}
	printf("%d\n", refill);
}
