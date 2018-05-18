#include <iostream>

using namespace std;
main() {
	int n,a,b;
	cin>> n >> a >> b;
	int w[n];
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		cin >> w[i];
		if(w[i]>max)max=w[i];
	}
	a = a>max?a:max;
	int min = 99999999;
	int result = -1;
	for (int i = a; i <= b; ++i)
	{
		int cur = 0;
		int extra = 0;
		for (int j = 0; j < n; ++j)
		{
			if (cur + w[j] > i) {
				extra += i - cur;
				cur = 0;
			}
			cur += w[j];
			if(extra >= min) {
				extra = -1;
				break;
			}
		}
		if(extra!=-1){
			if(cur) extra += i -cur;
			if(extra<min){
				result = i;
				min = extra;
			}
		}

	}
	cout << result <<endl;
}