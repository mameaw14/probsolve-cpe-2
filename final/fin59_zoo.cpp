#include <stdio.h>
using namespace std;
main()
{
	int r,c,b,t;
	scanf("%d %d %d %d",&r,&c,&b,&t);
	int refill = 1;
	int now = b;
	for (int i = 0; i < r; ++i)
	{
		bool not_refill = true;
		for (int j = 0; j < c; ++j)
		{
			int d;
			scanf("%d",&d);
			if(d && not_refill && j != 0) {
				refill++;
				now = b;
				not_refill = false;
			}
			while(d>0) {
				if(now < d*t) {
					int no_of_bird = now/t;
					now -= no_of_bird * t;
					d -= no_of_bird;

					now = b;
					refill++;
				}
				if(now >= d*t) {
					now -= d*t;
					d = 0;
				}
			}
			not_refill = true;
		}
	}
	printf("%d\n", refill);
}
