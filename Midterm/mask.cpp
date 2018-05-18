#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
main() {
	int N;
	int x[4]={0};
	int contestant[4];
	cin >> N;
	for(int j=0;j<4;j++){
		for(int i=0;i<N;i++){
			int a;
			cin >> a;
			if(a>x[j]) {
				x[j] = a;
				contestant[j] = N*j + i + 1;
			}
		}
	}
	int mem[4];
	int winA,winB;
	int scA,scB;
	mem[2] = (x[0] > x[1])? contestant[1]:contestant[0];
	mem[3] = (x[2] > x[3])? contestant[3]:contestant[2];
	winA = (x[0] > x[1])? contestant[0]:contestant[1];
	scA = (x[0]>x[1])?x[0]:x[1];
	scB = (x[2]>x[3])?x[2]:x[3];
	winB = (x[3] > x[2])? contestant[3]:contestant[2];
	mem[0] = (scA>scB)? winA:winB; 
	mem[1] = (scA<scB)? winA:winB; 
	for(int i=0;i<4;i++){
		printf("%d ", mem[i]);
	}
}