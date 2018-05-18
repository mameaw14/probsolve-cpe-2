#include <iostream>
#include <stdio.h>
using namespace  std;
main()
{
	int n,m;
	cin >> n >> m;
	char arr[n][n+1];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",arr[i]);
	}

	for (int i = 0; i < m; ++i)
	{
		char q;
		int k;
		cin >> q >> k;
		k--;
		for(int j = 0; j < n; j++) {
			if (q == 'L') {
				if(arr[k][j] == 'x' ) 
					arr[k][j] = '.';
				else break;
			} else if (q == 'R') {
				if(arr[k][n-j-1] == 'x')
					arr[k][n-j-1] = '.';
				else break;
			} else if (q == 'U') {
				if(arr[j][k] == 'x') 
					arr[j][k] = '.';
				else break;
			} else if (q == 'D') {
				if(arr[n-j-1][k] == 'x')
					arr[n-j-1][k] = '.';
				else break;
			} else if (q == 'A') {
				if(arr[k][j] != '#')
					arr[k][j] = 'x';
			} else if (q == 'B') {
				if(arr[j][k] != '#')
					arr[j][k] = 'x';
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%s\n",arr[i]);
	}
}