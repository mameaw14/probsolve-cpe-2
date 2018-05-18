#include <stdio.h>
#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <set>
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
	set<int> st;
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}

	int sum = 0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,orderBySecond > q;
	int now = 1;

	while(!v[now].empty()) {
		pair<int,int> t = v[now].back();
		q.push(t);
		v[now].pop_back();
	}
	st.insert(now);
	while(!q.empty()) {
		pair<int,int> t = q.top();
		q.pop();
		now = t.first;
		if(st.find(now)==st.end()) {
			st.insert(now);
			sum+=t.second;
		} else continue;

		if(st.size() == n) break;
		while(!v[now].empty()) {
			pair<int,int> t = v[now].back();
			q.push(t);
			v[now].pop_back();
		}
	}
	printf("%d\n", sum);
}