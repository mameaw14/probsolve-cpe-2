#include <string.h>
#include <stdio.h>
#include <math.h>
main() {
	char str[1001];
	scanf("%s",str);
	int c = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		if(str[i] == ',') c++;
	}
	if(strlen(str) == 2) c=-1;
	printf("%d\n", (int)pow(2,c+1));
}