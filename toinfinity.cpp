#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
main()
{
	int n;
	cin >> n;
	int x,y,r;
	int m1=9999999,m2=-9999999;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d",&x,&y,&r);	
		if(y>=0) {
			m1 = min(m1,y-r);
			if(m1<0) {
				m1=0;
				break;
			}
		}
		if(y<=0) {
			m2 = max(m2,y+r);
			if(m2>0) {
				m2=0;
				break;
			}
		}
	}
	m2*=-1;
	if(m1==0||m2==0) {
		printf("-1\n");
	} else printf("%d\n", min(m1,m2));
}