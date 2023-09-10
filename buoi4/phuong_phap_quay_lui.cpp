#include<iostream>
using namespace std;
int kq[100] , chon[100] , v[100] ,n,dem=0;
void khoitao(){
	n=8;
	v[0]=5;
	v[1]=4;
	v[2]=2;
	v[3]=7;
	v[4]=6;
	v[5]=2;
	v[6]=3;
	v[7]=9;
	for(int j=0;j<n;j++)
	{
		chon[j]=kq[j]=0;
	}
}
void inkq()
{
	cout<<"\n Cach thu "<<++dem<<":";
	for(int j=0;j<n;j++)
	{
		cout<<" "<<kq[j];
	}
}
void tim(int i , int d){ 
	if(i>n) inkq();
	else
	for(int j=0;j<n;j++)
	{
		if(chon[j]==0 && v[j] > d)
		{
			kq[i-1]=v[j]; 
			chon[j]=1;
			tim(i+1 , v[j]-d);
			kq[i-1]=0;
			chon[j]=0;
		}
	}
}
// Backtracking-rat in a maze
void printSolution(int sol[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d",sol[i][j]);
		}
		printf("\n");
	}
}
bool isSafe(int maze[N][N] , int x , int y)
{
	if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
	{
		return true;
	}
}
bool solveMaze(int maze[N][N]){
	int sol[N][N] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if(solveMazeUtil(maze,0,0,sol)==false){
		printf("Solution doesnt exist");
		return false;
	}
	printSolution(sol);
	return true;
}
int main(){
	int d=2;
	khoitao();
	tim(1,d);
}
