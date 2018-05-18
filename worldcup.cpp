#include <iostream>
#include <stdio.h>
using namespace std;
main()
{	
	string name[4];
	for (int i = 0; i < 4; ++i)
	{
		cin >> name[i];
	}

	int score[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> score[i][j];
		}
	}

	//cal1
	float point[4] = {0};
	int shoot[4] = {0};
	int shooted[4] = {0};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i + 1; j < 4; ++j)
		{
			shoot[i] += score[i][j];
			shooted[j] += score[i][j];
			shoot[j] += score[j][i];
			shooted[i] += score[j][i];

			if (score[i][j] > score[j][i]) point[i] += 3;
			else if (score[i][j] == score[j][i]) {
				point[i]++;
				point[j]++;
			} else point[j] += 3;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		point[i] += (shoot[i] - shooted[i]) / 100.0 + shoot[i] / 1000.0;
	}

	float max = -10000;
	float prev_max = 999999;
	int list[4] = {0};
	int t;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(point[j] > max && point[j] < prev_max) {
				max = point[j];
				t = j;
			}
		}
			prev_max = max;
			max = -10000;
			list[i] = t;
	}

	for (int i = 0; i < 4; ++i)
	{
		cout<<name[list[i]]<<" ";
		printf("%d\n", (int)(0.5+point[list[i]]));
	}
}