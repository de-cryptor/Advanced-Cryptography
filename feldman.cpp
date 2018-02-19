/* Jatin Goel
	IIIT Allahabad*/
/* There is no substitute of hardwork. */
/* Hardwork definitely pays off. */
/* There is no shortcut to success. */
/* Input
3 (degree)
0 3 3 (coefficients)
*/
#include <bits/stdc++.h>
using namespace std;
#define  LL long long
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL)
int power(int x, unsigned int y)
{
    int res = 1;    
  
    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
        y = y>>1; 
        x = (x*x);  
    }
    return res;
}
int main()
{
	//fast_io;
	if(fopen("input.txt", "r"))
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt","w",stdout);
	}
	int  p=11,q=6;
	int g=3;
	cin >> p >> q;
	if((p-1)%q != 0)
	{
		cout << "Invalid Input" << endl;
		return 0;
	}

	int coeff[10];
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> coeff[i];
	cout << "Your Polynomial is : " << coeff[1] ; 
	for(int i=2;i<=n;i++)
	{
		cout << " + " <<coeff[i] <<"*x^" <<i-1;  
	}
	cout << endl;

	int commitments[10];
	int shares[10];
	cout << "The Shares are : " << endl;
	for(int i=1;i<=n;i++)
	{
		int si = coeff[1];
		for(int j=2;j<=n;j++)
		{
			si += coeff[j]*power(i,j-1);
		}
		shares[i] = si%q;
		printf("s[%d] = %d\n",i,shares[i]);

	}
	cout << "The commitments are : " << endl;
	for(int i=1;i<=n;i++)
	{
		commitments[i] = (power(g,coeff[i]))%p;
		printf("c[%d] = %d\n",i,(power(g,coeff[i]))%p);
	}
	cout << "Verification Process : \n";
	for(int i=1;i<=n;i++)
	{
		int v = 1;
		cout << "For secret : " << i << endl;
		cout << "From g^P(i) : ";
		cout << power(g,shares[i])%p << endl ;
		for(int j=1;j<=n;j++)
		{
			int x = power(i,j-1);
			v *= power(commitments[j],x);
			v = v%p; 
		}
		cout << "From commitments : ";
		cout << v << endl <<endl;
	}

}
