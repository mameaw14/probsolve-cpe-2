#include <stdio.h>
#include <map>
using namespace std;
void fn() {
	int n;
	map<double,double> li;
	scanf("%d",&n);
	while(n--) {
		double x1,x2,y1,y2,trans;
		scanf("%lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&trans);
		double a,b;
		a = x1<x2?x1:x2;
		b = x1>x2?x1:x2;
		li[a] = trans;
		li[b] = -trans;
	}
	double now = 1;
	double t = -1;
	printf("%d\n-inf",li.size()+1);
	for (map<double,double>::iterator i = li.begin(); i != li.end(); ++i)
	{
		printf(" %.3lf %.3lf\n%.3lf", i->first,now,i->first);
		if(i->second<0) now/=-i->second;
		else now*=i->second;
	}
	printf(" +inf %.3f",now);
}
main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		fn();
		printf("\n");
		if(n!=0) printf("\n");
	}
}