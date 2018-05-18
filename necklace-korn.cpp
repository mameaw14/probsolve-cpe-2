#include "iostream"
// #include "stdio.h"
// #include "map"
using namespace std;
int main(int argc, char const *argv[])
{
	int head = 0;
	// std::map<int , int> findhead;
	int n ;
	cin >> n;
	int pre[n + 1] , next[n + 1] , first[n + 1] , last[n + 1];

	for (int i = 0; i < n + 1; ++i)
	{
		pre[i] = 0;
		next[i] = 0;
		first[i] = 0;
		last[i] = 0;
	}
	int t1, t2;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> t1 >> t2;
		if (next[t1] == 0 && pre[t1] == 0 && next[t2] == 0 && pre[t2] == 0)
		{
			pre[t1] = t2;
			next[t2] = t1;
			first[t2] = t2;
			last[t2] = t1;
			first[t1] = t2;
			last[t1] = t1;
		}
		else if (next[t2] != 0)
		{
			int nextNode = next[t2];
			next[t2] = t1;
			pre[t1] = t2;
			if (last[t1] == 0)
			{
				pre[nextNode] = t1;
				next[t1] = nextNode;
			}
			else
			{
				// last[t1] = first[t1] = 0;
				pre[nextNode] = last[t1];
				next[last[t1]] = nextNode;
			}
			
		}
		else if (next[t2] == 0 && pre[t2] == 0){
			next[t2] = t1;
			pre[t1] = t2;
			first[t2] = t2;
			last[t2] = last[t1];
			first[last[t1]] = t2;
		}
		else if (next[t2] == 0 )
		{
			next[t2] = t1;
			pre[t1] = t2;
			if (last[t1] == 0)
			{
				last[first[t2]] = t1;
				first[t1] = first[t2];
				last[t1] = t1;
			}
			else
			{
				// last[t1] = first[t1] = 0;
				last[first[t2]] = last[t1];
				first[last[t1]] = first[t2];
				// last[t1] = t1;
			}
		}
		head = first[last[t2]];
		////////////////////////////////////
		cout << i + 1 << " head:" <<  head <<  endl;
		for (int i = 0; i < n; ++i)
		{
			cout << i + 1 << '\t';
		}
		cout << endl;
		for (int i = 0; i < n; ++i) //pre char
		{
			cout << pre[i + 1] << '\t';
		}
		cout << endl;
		for (int i = 0; i < n; ++i) // next char
		{
			cout << next[i + 1] << '\t';
		}
		cout << endl;
		for (int i = 0; i < n; ++i) // first char of string 
		{
			cout << first[i + 1] << '\t';

		}
		cout << endl;
		for (int i = 0; i < n; ++i) // last char 
		{
			cout << last[i + 1] << '\t';
		}
		cout << endl;
		cout << endl;
	}
    for (int i = 1; i <= n; ++i)
	{
		if (pre[i] == 0)
		{
			head = i;
		}
	}
	int j = head;
	for (int i = 0; i < n; ++i)
	{
		cout << j << ' ';
		j = next[j];
	}
	return 0;
}