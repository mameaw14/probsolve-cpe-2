#include <stdio.h>
#include <vector>
using namespace std;
main()
{
	int n;
	int M=0,MAX=1;
	scanf("%d",&n);
	vector<int> v[n];
	for (int i = 0; i < n; ++i)
	{
		int e;
		scanf("%d",&e);
		v[i].push_back(e);
	}
	for (int i = 1; i < n; ++i)
	{
		int m = -1;
		int max = -1;
		for (int j = 0; j < i; ++j)
		{
			if (v[j].back() < v[i].back()) {
				int size = v[j].size();
				if(size > max) {
					max = size;
					m = j;
				}
			}
		}
		if(m!=-1) {
			int e = v[i].back();
			v[i] = v[m];
			v[i].push_back(e);
		}
		int size = v[i].size();
		if(size > MAX) {
			MAX = size;
			M = i;
		}
	}
	printf("%d\n", MAX);
	for (int i = 0; i < v[M].size(); ++i)
	{
		printf("%d ", v[M][i]);
	}
}