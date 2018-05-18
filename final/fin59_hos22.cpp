#include <stdio.h>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;
bool** g;
int n,m,h;
struct edge{
	int from,to;
};
// void dfs(int now,int,r,int h) {
// 	if(g[now][now]) return;
// 	// set[r].insert(now);
// 	g[now][now] = 1;
// 	if(h==0) return;
// 	for (int i = 1; i < n+1; ++i)
// 	{
// 		if(g[now][i]) dfs(i,h-1);
// 	}
// }

main()
{
	scanf("%d %d %d",&n,&m,&h);
	set<int> arr[n+1];
	vector<edge> vc;
	g = (bool**)calloc(sizeof(bool*),n+1);
	for (int i = 0; i < n+1; ++i)
	{
		g[i] = (bool*)calloc(sizeof(bool),n+1);
		arr[i].insert(i);
	}
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		edge t = {a,b};
		vc.push_back(t);
		arr[a].insert(b);
		arr[b].insert(a);
	}	
	for (int j = 0; j < h-1; ++j)
	{
		for (std::vector<edge>::iterator r = vc.begin(); r != vc.end(); ++r)
		{
			int i = r->from;
			int h = r->to;

					arr[i].insert(arr[h].begin(), arr[h].end());
					arr[h].insert(arr[i].begin(), arr[i].end());
		}
	}
	int mx = 0;
	for (int i = 1; i < n+1; ++i)
	{
		if(arr[i].size() > mx) mx = arr[i].size();
	}
	printf("%d\n",mx );
}