#include <stdio.h>
#include <map>
using namespace std;
main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	map<int,int> M;
	int MX = 0;
	for (int i = 0; i < n; ++i)
	{
		int x,c;
		scanf("%d %d",&x,&c);
		map<int,int>::iterator itlow = M.lower_bound(x);
		int mx = 0;
		while(itlow != M.end()) {
			if(itlow->first - x > k) break;
			if(itlow->second > mx) mx = itlow->second;
			itlow++;
		}
		M[x] = c + mx;
		if(M[x] > MX) MX = M[x];
		// printf("%d\n", M[x]);
	}
	printf("%d\n", MX);
}