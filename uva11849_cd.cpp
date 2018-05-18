#include <stdio.h>
#include <map>
using namespace std;
main()
{
	int n,m;

	scanf("%d %d",&n,&m);
	while(n!=0 && m!=0) {
		map<int,bool> nmap;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			int d;
			scanf("%d",&d);
			nmap[d] = true;
		}
		for (int i = 0; i < m; ++i)
		{
			int d;
			scanf("%d",&d);
			if(nmap[d]) count++;
		}
		printf("%d\n", count);
		scanf("%d %d",&n,&m);
	}
}