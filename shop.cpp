#include<stdio.h>
main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int cost[n];
    scanf("%d",&cost[0]);
    int i = 0;
    while(++i<n) {
        scanf("%d",&cost[i]);
        cost[i] += cost[i-1];
    }
    while(m--) {
        int money;
        scanf("%d",&money);
        int half = (n+1)/2 -1;
        int a = 0;
        int b = n-1;
        int result = -1;
        while(a<=b) {
            if(cost[half] == money) {
                result = half;
                break;
            }
            if(cost[half] < money && half < result) break;
            if(cost[half] < money && half > result) result = half;
            if(cost[half] > money) {
                b = half-1;
            } else {
                a = half+1;
            }
            half = (b+a)/2;
        }
        printf("%d\n",result+1);
    }
}