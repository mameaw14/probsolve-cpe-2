#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
main() {
    map<int,int> mp;
    int n,a,b;
    scanf("%d",&n);
    while(n--) {
        int i;
        scanf("%d",&i);
        if(i==1){
            scanf("%d %d",&a,&b);
            if(mp.find(a) == mp.end()) {
                mp[a] = b;
            } else {
                mp[a] += b;
            }
        } else if(i==2) {
            scanf("%d",&a);
            if(mp.find(a) == mp.end()) {
                printf("0\n");
            } else {
                printf("%d\n",mp[a]);
            }
        } else if(i==3) {
            scanf("%d %d",&a,&b);
            if(mp.find(a) == mp.end()) {
                printf("0\n");
            } else {
                if(mp[a] < b) {
                    printf("%d\n",mp[a]);
                    mp[a] = 0;
                } else {
                    mp[a] -= b;
                    printf("%d\n",b);
                }
            }
        }
    }
}