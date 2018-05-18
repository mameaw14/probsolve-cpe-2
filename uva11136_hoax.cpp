#include <stdio.h>
#include <map>
using namespace std;
main()
{

	int n;
	scanf("%d",&n);
	while(n!=0) {
		int sum = 0;
		map<int,int> mp;
		while(n--) {
			int c;
			scanf("%d",&c);
			while(c--) {
				int t;
				scanf("%d",&t);
				mp[t]++;	
			}
			map<int,int>::iterator a = mp.begin();
			map<int,int>::iterator b = --mp.end();
			int A=a->first,B=b->first;
			mp[A]--;
			mp[B]--;
			if(!mp[A]) mp.erase(a);
			if(!mp[B]) mp.erase(b);
			sum+=B-A;
		}
		printf("%d\n",sum);
		scanf("%d",&n);	
	}
}