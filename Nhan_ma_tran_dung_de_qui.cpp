#include<bits/stdc++.h>
using namespace std;
#define MAXINT 20000;
int d[]={3,5,7,2,4};
int n=5;
int F[100][100];
int S[100][100];
int num=1;
int tinh(){
	int i,j,k,m;
	for(int i=1 ; i<=n ; i++) F[i][i]=0;
	for(int L=2;L<n;L++)
		for(i=1;i<=n-L+1;i++){
			j=i+L-1;F[i][j]=INT_MAX;
			for(int k=i ; k<j ;k++){
				int q=F[i][k]+F[k+1][j]+d[i-1]*d[k]*d[j];
				if(q<F[i][j]){
					F[i][j]=q;S[i][j]=k;
				}
			}
		}
	return F[1][n-1]; 
}
void inkq(int i , int  j){
	if(i==j)
		printf("A %d" , num++);
	else{
		printf("(");
		inkq(i,S[i][j]);
		printf("x");
		inkq(S[i][j]+1,j);
		printf(")");
	}	
}
int main(){
	cout<<"\n So pphep tinh it nhat la :"<<tinh()<<"\n";
	cout<<"\n Thu tu nhan nhau sau :";
	inkq(1,n-1);
}
