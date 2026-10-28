#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans[39][39];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			ans[j][i] = 0;
		}
		cout<<endl;
	}
	
	int nx,ny;
	int now=1;//横行 纵列 
	ny = 0;
	nx = n/2;
	ans[nx][ny] = now;
	now ++;		
	while(now <= n*n){
		if(nx!=n-1 and ny==0){
			ny = n-1;
			nx ++;
		}else if(nx==n-1 and ny !=0){
			nx=0;
			ny--;
			
		}else if(ny ==0 and nx == n-1){
			ny++;
		}else if(ny>0 and nx < n-1){
			nx++;
			ny--;
			if(ans[nx][ny]!=0){
				nx--;
				ny+=2;
			}
		}
		ans[nx][ny] = now;
		now++;
	
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<ans[j][i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
