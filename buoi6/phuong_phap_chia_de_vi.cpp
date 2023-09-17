#include<bits/stdc++.h>
using namespace std;

int *a , n;
void sinh(int *&a , int n){
	a=new int [n];
	for(int i=0;i<n;i++)
	{
		int x=rand();
		if(rand()%10==0) x=-2*x;
		a[i]=x;	
	}
}
void Merge(int *&a , int ll, int rr){
	
	if(ll<rr)
	{
		int m=(ll+rr)/2;
		Merge(a,ll,rr);
		Merge(a , m+1 ,rr);
		int i=ll , j=m+1 , v=0;
		int *kq=new int [rr -ll+1]; // mang ket qua tam chua day tang dan 
		while(i<=m && j<=rr)
		{
			if(a[i]<=a[j])
			{
				kq[v]=a[i];
				i++;
				v++;
			}else{
				kq[v]=a[j];
				v++;
				j++;
			}
		}
		while(j<=m){
			kq[v]=a[i];
			i++;
			v++;
		}
		while(j<=rr){
			kq[v]=a[j];v++;j++;
		}
		i=ll;
		for(int j=0;j<v;j++){
			a[i++]=kq[j];
		}
	}
}
void MergeSort(int *&a ,int n){
	Merge(a,0,n-1);
}
void in(int *a , int n){
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<",";
	}
}

int main()
{
	int n=10;
	sinh(a ,n);
	cout<<"ham truoc khi sap xep";
	 in(a,n);
	MergeSort(a,n);
	cout<<"ham sau khi sap xep";
	in(a,n);
}
//n se chay tuong ung voi ca thoi gian la : 10 ,  1000 ,50000, 700000 ,30000000
