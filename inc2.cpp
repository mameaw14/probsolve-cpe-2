#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int find_index(vector<int> &v, int l, int r, int key) {
	while (r-l > 1) {
	int m = l + (r-l)/2;
	if (v[m] >= key)
		r = m;
	else
		l = m;
	}

	return r;
}

int lis(vector<int> &v) {
	if (v.size() == 0)
		return 0;

	vector<int> tail(v.size(), 0);
	int length = 1; 

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] < tail[0])
			tail[0] = v[i];
		else if (v[i] > tail[length-1])
			tail[length++] = v[i];
		else
			tail[find_index(tail, -1, length-1, v[i])] = v[i];
	return length;
}
	

main() {
	int n;
	scanf("%d",&n);

	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int e;
		scanf("%d",&e);
		v.push_back(e);
	}
	printf("%d\n",lis(v));
}
