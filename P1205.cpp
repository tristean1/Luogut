#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	char a[10][10];
	char b[10][10];
	bool ans[7] = {1,1,1,1,1,1,1};
	string input;
	for(int i = 0;i<n;i++){
		cin>>input;
		for(int j =0;j<n;j++){
			a[i][j] =input[j];
			//cout<<a[i][j]<<" ";
		}
	}
	for(int i = 0;i<n;i++){
		cin>>input;
		for(int j =0;j<n;j++){
			b[i][j] =input[j];
			//cout<<b[i][j]<<" ";
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			//0,0 --> n-1,0 | 0,1 --> n-2,0
			if(a[i][j]!=b[j][n-1-i]){
				ans[0] = 0;
			}
			if(a[i][j]!=b[n-1-i][n-1-j]){
				ans[1] = 0;
			}
			if(a[i][j]!=b[n-1-j][i]){//0,1 --> 1,n-1
				ans[2] = 0;
			}
			if(a[i][j]!=b[i][n-1-j]){
				ans[3] = 0;
			}
			if(a[i][j]!=b[i][j]){
				ans[5] = 0;
			}//n-1-n+1-i
			if(a[i][j]!=b[n-1-j][n-1-i] and a[i][j]!=b[n-1-i][j] and a[i][j]!=b[j][i]){
				ans[4] =0;
			}
		}
	}
	for(int i = 0;i<7;i++){
		
		if(ans[i]){
			cout<<i+1;
			return 0;
		}
	}
}
