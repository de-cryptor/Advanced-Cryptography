/* Jatin Goel
	IIIT Allahabad*/
/* There is no substitute of hardwork. */
/* Hardwork definitely pays off. */
/* There is no shortcut to success. */
/*
Input
4 3 (n,t)
11 13 17 23 (m1,m2,--mn)
3 (k)
1 3 4 (what all shares to be used for reconstruction)

*/
#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
// returns x where (a * x) % b == 1
int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
 
int chinese_remainder(int n[], int a[], int len)
{
	int p, i, prod = 1, sum = 0;
 
	for (i = 0; i < len; i++) prod *= n[i];
 
	for (i = 0; i < len; i++) {
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}
 
	return sum % prod;
}
 
int main(void)
{
	
	if(fopen("input.txt", "r"))
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt","w",stdout);
	}
	int nm,th,flag=0;
	//Input (n,t)
	cin >> nm >> th;
	int n[10];
	for(int i=0;i<nm;i++)
		cin >> n[i];
	int a[10];
	int k;
	// input(k)
	scanf("%d",&k);
	if(th > k)
		flag=1;
	// input what all shares to be used for reconstruction
	for(int i=0;i<k;i++)
		cin >> a[i];
	int i=0;
	int p=1,q=1;
	for(i=0;i<k-1;i++)
	{
	    p *= n[i];
	}
	for(i=nm-k;i<nm;i++)
	{
	    q *= n[i];
	}
	printf("Range of Secret : ");
	printf("%d %d\n",p,q);
	srand(time(0));
	int num = (rand() + p) % (q + 1);
	printf("Secret : ");
	printf("%d\n",num);
	printf("Secret Shares\n");
	for(int i=0;i<nm;i++)
	{
	    a[i] = num%n[i];
	    printf("Share[%d] = %d \n",i+1,a[i]);
	}
	if(flag)
	{
		cout << "Secret can not be Reconstructed |_-_|" << endl;
		return 0;
	}
	printf("Reconstructed Secret : ");
	printf("%d\n", chinese_remainder(n, a,nm));
	return 0;
}