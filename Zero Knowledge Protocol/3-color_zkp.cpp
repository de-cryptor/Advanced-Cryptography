/* 
	@Author - Jatin Goel
	@Institute - IIIT Allahabad
	Hardwork definitely pays off. 
	There is no substitute of hardwork.
	There is no shortcut to success. 
*/
#include <bits/stdc++.h>
using namespace std;
#define  LL long long
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL)
int main()
{
	fast_io;
	if(fopen("input.txt", "r"))
	{
		freopen("input.txt", "r", stdin);
		//freopen("output.txt","w",stdout);
	}
	int round = 5;
	pair<int,int> edges[100];
	int V,E;
	cin >> V >> E;
	char color[100];
	cout << "	Vertex Colors" << endl;
	for(int i=1;i<=V;i++)
	{
		cin >> color[i];
		cout << "	{" << i << " " << color[i] << "}";
		if(i%5 == 0)
			cout << endl;

	}
	cout << endl;
	cout << "	Graph Edges" << endl;
	for(int i=1;i<=E;i++)
	{
		cin >> edges[i].F >> edges[i].S;
		cout << "	{"<<edges[i].F << " " << edges[i].S << "}";
		if(i%5 == 0)
			cout << endl;

	}
	cout << endl;
	vector<char> v;
	v.push_back('R');
	v.push_back('G');
	v.push_back('B');
	for(int i=1;i<=round;i++)
	{
		cout << "	Round : " << i << endl << endl;
		int r = 1 + rand()%15;
		next_permutation(v.begin(),v.end());
		for(int j=1;j<=V;j++)
		{
			if(color[j] == 'R')
				color[j] = v[0];
			else if(color[j] == 'G')
				color[j] = v[1];
			else if(color[j] == 'B')
				color[j] = v[2];
		}
		cout << "	{"<<edges[r].F << " : " <<color[edges[r].F] << " , "<< edges[r].S << " : " << color[edges[r].S] << "}"<<endl;
		
		if(color[edges[r].F] != color[edges[r].S])
			cout << "	Verified!!!"<<endl<<endl;


	}


}
