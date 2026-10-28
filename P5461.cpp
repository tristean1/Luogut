#include<iostream>
using namespace std;

int x2(int down){
	int ans = 1;
	for(int i = 0;i<down;i++){
		ans *= 2;
	}
	return ans;
}

bool isafe(int x,int y,int n){
	if(n==0){return 1;}
	if(x<x2(n-1) && y<x2(n-1)){
		return 0;
	}else if(x>=x2(n-1) && y<x2(n-1)){
		return isafe(x-x2(n-1),y ,n-1);
	}else if(x<x2(n-1) && y>=x2(n-1)){
		return isafe(x,y- x2(n-1),n-1);
	}else if(x>=x2(n-1) && y>=x2(n-1)){
		return isafe(x-x2(n-1),y-x2(n-1),n-1);      
	}
	return 0;
}

int main(){
	int n;
	cin>>n;
	int ans[1024][1024] ;
	for(int i =0;i<x2(n);i++){
		for(int j =0;j<x2(n);j++){
			ans[i][j] = 1;
		}}
	for(int i =0;i<x2(n);i++){
		for(int j =0;j<x2(n);j++){
			if(isafe(i,j,n)){
				ans[i][j] = 1;
				
			}else{
				ans[i][j] =0;
			}
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
