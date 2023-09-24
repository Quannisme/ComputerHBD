#include<bits/stdc++.h>
using namespace std;

long ck(int m , int n){
	if(m==0 && n==0){
		return 0;
	}
	if(m==0 || n==0){
		return 1;
	}else {
		return ck( m , n-1) +ck(m-1 , n);
	}
}
int main(){
	int m=50 , n=4;
	long t1 ,t2 ;
	t1=clock();
	cout<<"\n So cah di : "<<ck(m,n);
	t2=clock();
	cout<<"\n Thoi gian thuc hien :"<<(t2-t1);
}
