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
	int round = 4;
	LL n = 2341;
	int s = 145;
	int v = s*s % n;
	cout << "	Alice Private key : " << s << endl;
	cout << "	Alice Public Key : " << v << endl;
	
	for(int i=1;i<=round;i++)
	{
		cout << "	Round : " << i << endl;
		int r = rand()%100 + 1;
		cout << "	Random Number : " << r << endl;
		int w = (r*r)%n;
		cout << "	Alice --->--- Witness(x) = "<< w << "--->-- Bob"<<endl;
		int c = rand()%2;
		cout << "	Alice ---<--- Challenge(c) = "<< c <<"----<--- Bob"<<endl;
		int y = r*(c?s:1);
		y = y % n;
		cout << "	Alice --->--- Response(y) = "<< y << "--->-- Bob"<<endl;
		cout << "	Now Bob Will do Verification :" <<endl;
		int y1 = y*y % n;
		cout << "	y^2 mod n = " << y1 << endl;
		int y2 = w*(c?v:1);
		y2 = y2 % n;
		cout << "	xv^c mod n = " << y2 << endl;
		if(y1 == y2)
			cout << "Authenticated!!!" << endl;

	}
}