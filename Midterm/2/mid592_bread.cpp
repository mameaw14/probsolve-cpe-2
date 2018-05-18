#include <map>
#include <stdio.h>
#include <utility>
using namespace  std;
main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	map<int, pair<int,int> > arr;
	for (int i = 0; i < n; ++i)
	{
		int x,l,I;
		scanf("%d %d %d",&x,&l,&I);
		arr[x] = make_pair(l,I);
	}
	for (int i = 0; i < k; ++i)
	{
		int t;
		scanf("%d",&t);
		int save = -1;
		int min = 10000000;
		for (int i = t-5; i <= t+5; ++i)
		{
			if(arr[i].first < min){
				if(arr[i].second>0){
					min = arr[i].first;
					save = i;
				}
			}
			

		}
			if(save!=-1){
				arr[save].second--;
				printf("%d\n", arr[save].first);
			} else printf("0\n");
	}
}