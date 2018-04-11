/* Jatin Goel
	IIIT Allahabad*/
/* There is no substitute of hardwork. */
/* Hardwork definitely pays off. */
/* There is no shortcut to success. */
/* Input
3 (degree)
0 3 3 (coefficients of P(x))
1 2 4 (coefficients of P'(x))
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
	int  p=11,q=5;
	int g=3,h=4;
	int coeff1[10],coeff2[10];
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> coeff1[i];
	for(int i=1;i<=n;i++)
		cin >> coeff2[i];
	cout << "Your First Polynomial is : " << coeff1[1] ; 
	for(int i=2;i<=n;i++)
	{
		cout << " + " <<coeff1[i] <<"*x^" <<i-1;  
	}
	cout << endl;
	cout << "Your Second Polynomial is : " << coeff2[1] ; 
	for(int i=2;i<=n;i++)
	{
		cout << " + " <<coeff2[i] <<"*x^" <<i-1;  
	}
	cout << endl;
	int commitments[10];
	int shares1[10],shares2[10];
	cout << "The Shares are : " << endl;
	for(int i=1;i<=n;i++)
	{
		int si1 = coeff1[1];
		int si2 = coeff2[1];
		for(int j=2;j<=n;j++)
		{
			si1 += coeff1[j]*power(i,j-1);
			si2 += coeff2[j]*power(i,j-1);
		}
		shares1[i] = si1%q;
		shares2[i] = si2%q;
		printf("s[%d] = (%d,%d)\n",i,shares1[i],shares2[i]);

	}
	cout << "The commitments are : " << endl;
	for(int i=1;i<=n;i++)
	{
		commitments[i] = (((power(g,coeff1[i]))%p)*((power(h,coeff2[i]))%p))%p;
		printf("c[%d] = %d\n",i,commitments[i]);
	}
	cout << "Verification Process : \n";
	for(int i=1;i<=n;i++)
	{
		int v = 1;
		cout << "For secret : " << i << endl;
		cout << "From g^P(i)*h^Q(i) : ";
		cout << ((power(g,shares1[i])%p)*(power(h,shares2[i])%p))%p << endl ;
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
