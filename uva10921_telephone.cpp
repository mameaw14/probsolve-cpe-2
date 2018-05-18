#include <stdio.h>
#include <map>
using namespace  std;
main()
{
	map<char,int> dict;
	for(char i = 'A';i<='Z';i++) {
		if(i=='A'||i=='B'||i=='C') {
			dict[i] = 2;
		}
		else if(i=='D'||i=='E'||i=='F') {
			dict[i] = 3;
		}
		else if(i=='G'||i=='H'||i=='I') {
			dict[i] = 4;
		}
		else if(i=='J'||i=='K'||i=='L') {
			dict[i] = 5;
		}
		else if(i=='M'||i=='N'||i=='O') {
			dict[i] = 6;
		}
		else if(i=='P'||i=='Q'||i=='R'||i=='S') {
			dict[i] = 7;
		}
		else if(i=='T'||i=='U'||i=='V') {
			dict[i] = 8;
		}
		else if(i=='W'||i=='X'||i=='Y'||i=='Z') {
			dict[i] = 9;
		}
	}
	char text[31];
	while(scanf("%s",text)!=EOF) {
		int i = 0;
		while(text[i]!='\0') {
			if(dict[text[i]]) {
				printf("%d", dict[text[i]]);
			} else printf("%c", text[i]);
			i++;
		}
		printf("\n");
	}
}