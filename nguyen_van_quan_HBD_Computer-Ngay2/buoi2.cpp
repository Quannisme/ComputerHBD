#include<bits/stdc++.h>
using namespace std;
string T,S;
//do phuc tap cua thuat toan la O(m*n)
int find(string T, string S)
{
	int n=T.length();int m=S.length();
	for(int i=0;i<=n-m;i++)
	{
		int j=0;
		while(j<m&& T[i+j]==S[j])j++;
		if(j==m) return i;
	}
	return -1;
}
int main(){
	cout<<"nhap chuoi T:";cin>>T;cout<<"Nhap chuoi S:";cin>>S;
//	T="ABABDABACDABABCABAB";
//	S="ABABCABAB";
	cout<<"/n ket qua tim chuoi S trong chuoi T";
	cout<<find(T,S);
}
