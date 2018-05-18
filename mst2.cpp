#include <stdio.h>
#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <set>
using namespace std;

struct orderBySecond {
	bool operator() (const pair<pair<int, int>,int> & lhs, const  pair<pair<int, int>,int> & rhs) {
	    return lhs.second > rhs.second; 
	};
	
};

main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,orderBySecond > q;
	set<int> st;
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		q.push(make_pair(make_pair(a,b),c));
	}

	int sum = 0;

	while(!q.empty()) {
		pair<pair<int,int>,int> t = q.top();
		q.pop();
		int from = t.first.first;
		int to = t.first.second;
		printf("Edge from %d to %d weight = %d\n",from,to,t.second );
		if(st.find(from)==st.end()||st.find(to)==st.end()) {
			st.insert(from);
			st.insert(to);
			sum+=t.second;
			printf("%d\n", t.second);
		}

		if(st.size() == n) break;
	}
	printf("%d\n", sum);
}