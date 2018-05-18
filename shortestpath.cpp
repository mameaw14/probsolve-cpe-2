#include <stdio.h>
#include <vector>
#include <list>
#include <utility>
#include <queue>
using namespace std;

struct orderBySecond {
	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
	    return lhs.second > rhs.second; 
	};
	
};

main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector< list< pair<int, int> > > v(n+1);
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	int shortest[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		shortest[i] = -1;
	}

	shortest[1] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,orderBySecond > q;
	int now = 1;

	while(!v[now].empty()) {
		pair<int,int> t = v[now].back();
		t.second+=shortest[now];
		q.push(t);
		v[now].pop_back();
	}
	while(!q.empty()) {
		pair<int,int> t = q.top();
		q.pop();
		now = t.first;
		if(shortest[now]==-1) {
			shortest[now] = t.second;
		}
		if(now == n) break;
		while(!v[now].empty()) {
			pair<int,int> t = v[now].back();
			t.second+=shortest[now];
			q.push(t);
			v[now].pop_back();
		}
	}
	printf("%d\n", shortest[n]);
}