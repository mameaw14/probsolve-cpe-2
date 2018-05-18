#include<iostream>
#include<stdio.h>
#include<map>
#include<list>
using namespace std;
main() {
    map<int,int> mp;
    list<int> sort[100001];
    int n, a, max=0;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&a);
        if(mp.find(a) == mp.end()) {
            mp[a] = 1;
        } else {
            mp[a]++;
        }
        int rank = mp[a];
        if(rank>max) max = rank;
        sort[rank].push_front(a);
        printf("%d\n", sort[max].front() );

    }

}