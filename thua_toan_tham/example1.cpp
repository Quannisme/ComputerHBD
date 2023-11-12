#include<bits/stdc++.h>
#include <iostream>
#include <vector>   
using namespace std;
//using std::vector;

vector<int>F;
void sinh(){
	while(true){
		int x; cout<<"Nhap kich thuoc file >0";cin>>x;
		if(x<=0) break;else F.push_back(x);
	}
	cout<<"\n Mang F:";
//	for(auto f:F) {
//	cout<<f<<" ";}
	for(int i=1  ; i<F.size() ; i++) cout<<F[i]<<" ";
}
void sol1(){
	int d=0;
	for(int i=1  ; i<F.size() ; i++){
		cout<<"\n Ghep File"<<F[i-1]<<"va"<<F[i]<<"----> R/W= "<<(F[i-1] + F[i]);
		d=d+(F[i-1]+F[i]);
		F[i]=F[i-1]+F[i];
	}
	cout<<"\n -------------------- Tong so lan doc ghi file="<<d;
}
void sol3(){
	int d=0;
	priority_queue <int , vector<int> , greater<int> > pq;
	for(int i=0;i<F.size();i++) pq.push(F[i]);
	while(!pq.empty()){
		int x=pq.top();pq.pop();
		if(pq.empty()) cout<<"\n --- Da tron xong file! \n So lan doc ghi file la"<<x;
		else{
			int y=pq.top();pq.pop();
			cout<<"\t\t ghep hai file"<<x<<"va"<<y;
			d=d+x+y;
			pq.push(x+y);
		}
	}
}
int main(){
	sinh();
//	sol1();
	sol3();
}
