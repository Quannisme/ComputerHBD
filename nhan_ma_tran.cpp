#include<bits/stdc++.h>
using namespace std;
int n=0 , *d;
void docfile()
{
	fstream fi("MMATRIX.inp.txt");
	if(fi==NULL) cout<<"\n khong doc duoc file !";
	else
	{
		fi>>n;d=new int[n+1];
		for(int i=0;i<=n;i++) fi>>d[i];
		fi.close(); cout<<"\n doc xong file!";
	} 
}
int tinh(int i , int j)
{
	if(i==j) return 0;
	else if(j==(i+1))return d[i-1]*d[i]*d[i+1];
	else
	{
		int dem=INT_MAX;
		for(int k=i;k<j;k++){
			int h=(tinh(i,k)+tinh(k+1,j)+d[i-1]*d[k]*d[j]);
			if(h<dem)dem=h;
		}
		return dem;
	}
}
int main(){
	docfile();
	cout<<"\n So phep nhan ="<<tinh(1,n);
}
