#include <stdio.h>
#include <map>
#include <utility>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);

	map<int,int> mp;
	mp[0] = 0;

	int m[n+1],p[n+1];
	m[0]=0,p[0]=0;
	for (int i = 1; i <= n; ++i)
	{
		int s,e,wi;
		scanf("%d %d %d",&s,&e,&wi);
		p[i] = (--mp.upper_bound(s))->second;
		if(i==1) p[i] = 0;

		m[i] = max(m[p[i]]+wi, m[i-1]);
		if(mp[e]) {
			mp[e] = (m[mp[e]]>m[i])? mp[e]:i;
		} else mp[e] = i;
	}	
	int i = n,c = 0;
	map<int,int> result;
	while(i!=0) {
		int now = m[i];
		while(m[--i] == now);
		i++;
		result[c++] = i;
		i = p[i];
	}
	printf("%d\n%d\n",m[n],c );
	for (int i = 0; i < c; ++i)
	{
		printf("%d ", result[i]);
	}
}