#include <stdio.h>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	int arr[n+1];
	arr[0] = 0;
	int result = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&arr[i]);
		int con = arr[i-1]-arr[i];
		if(con > 10) {
			result += con*10>700?700:con*10;
		}
	}
	printf("%d\n",result );
}