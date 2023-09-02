#include<bits/stdc++.h>
using namespace std;

//ham random so 
// rand : ham cho so ngau nhien
int *a , n;
void sinh(int *&a , int n){
	a=new int [n];
	for(int i=0;i<n;i++)
	{
		int x=rand();
		if(rand()%3==0) x=-2*x;
		a[i]=x;	
	}
}
void solution1(int *a , int n){
	int tm=a[0],d=0,c=0;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=i ; j<n ; j++)
		{
			// tinh tong tu i-> j
			int s=0;
			for(int k=i ; k<=j ; k++)
			{
				s=s+a[k];
			}
			if(s>tm){
				d=i;c=j;tm=s;
			}
		}
	}
	cout<<"Tong max="<<tm<<"\n";
	cout<<"\n d="<<d<<"c="<<c<<"\n";
	for(int i=d ; i<=c ;i++){
		cout<<a[i]<<" ";
	}
}
void solution2(int *a , int n)
{
	int smax=a[0],d=0,c=0;
	int *ss=new int[n];
	ss[0]=a[0];
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int s=0;
			if(i==0)s=ss[j];else s=ss[j]-ss[i-1];
			if(s>smax){
				smax=s;
				d=i;
				c=j;
			}
		}
	}
	cout<<"\n Doan con co tong lon nhat la "<<smax<<"\n";
}

int main()
{
	//thu solution 1
	int n=4000;
	sinh(a,n);
	long t1,t2;
	t1=clock();
	solution1(a,n);
	t2=clock();
	cout<<"\n THoi gian chay ="<<(t2-t1);
}


