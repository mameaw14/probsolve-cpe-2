#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
main() {
	int n,m,sum=0;
	scanf("%d %d",&n,&m);
	int t;
	map<int,int> mp;
	map<int,int>::iterator itlow,itup;
	for(int i=0;i<n;i++) {
		scanf("%d",&t);
		mp[t] = 1;
	}
	 for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
	for(int i=0;i<m;i++) {
		printf("%d:\n",i );
		scanf("%d",&t);
		itlow = mp.lower_bound(t);
		if(itlow->first > t) --itlow;
		itup = mp.upper_bound(t);
		printf("%d %d\n", itlow->first, itup->first);
		int dis1 = t - itlow->first;
		int dis2 = itup->first - t;
		if(++itlow == mp.begin()) dis1 = 100000;
		if(itup == mp.end()) dis1 = 100000;
		printf("%d %d\n", dis1,dis2);
		sum+=min(dis1,dis2);
	}
}