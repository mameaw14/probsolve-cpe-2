#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node {
	int height;
	int num;
	node(int height, int num) : height(height),num(num) {}
	bool operator<(const node& rhs) const { height > rhs.height; }
};

bool cmp(const node* a, const node* b) {
	return a->height > b->height;
}
main() {
	int N, M, min=10000000,number_of_broken=0,t=0;
	scanf("%d %d",&N,&M);
	int* is_broken = (int*)calloc(sizeof(int), N);
	node* s[N];
	for(int i=0;i<N;i++) {
		int x;
		scanf("%d",&x);
		s[i] = new node(x, i);
	}
	sort(s, s+N, cmp);
	while(M--) {
		int x;
		scanf("%d",&x);
		// printf("nob=%d\n",number_of_broken);
		if(x < min) min = x;
		if(x!=min) {
			printf("0\n");
			continue;
		}
		int bf_number_of_broken = number_of_broken;
		while(s[t]->height > x) {
			if(!is_broken[s[t]->num] || is_broken[s[t]->num]==M) {
				if(!is_broken[s[t]->num]){
					is_broken[s[t]->num] = M;
					number_of_broken++;
				}

				if(s[t]->num!=0 && !is_broken[s[t]->num - 1]){
					is_broken[s[t]->num - 1] = M;
					number_of_broken++;
				}

				if(s[t]->num!=N-1 && !is_broken[s[t]->num + 1]){
					is_broken[s[t]->num + 1] = M;
					number_of_broken++;
				}
			}
			t++;
		}
		printf("%d\n", number_of_broken - bf_number_of_broken);
	}
}