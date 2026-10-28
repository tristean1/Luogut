#include <iostream>
using namespace std;

int main(){
	int ans[102][102];
	for(int i = 0;i<=101;i++){
		for(int j = 0;j<=101;j++){
			ans[i][j] = '0';
		}
		//cout<<endl;
	}
	int width,height;
	string input;
	cin>>height>>width;
	for(int i = 1;i<=height;i++){
		cin>>input;
		for(int j = 1;j<=width;j++){
			ans[i][j] = input[j-1];
		}
	}
	char now;
	for(int i = 1;i<=height;i++){
		for(int j = 1;j<=width;j++){
			now = ans[i][j];
			if(now =='*'){
				continue;
			}else{
				now = '0';
			
				if(ans[i-1][j-1]=='*'){now++;}
				if(ans[i-1][j]=='*'){now++;}
				if(ans[i-1][j+1]=='*'){now++;}
				if(ans[i][j-1]=='*'){now++;}
				if(ans[i][j+1]=='*'){now++;}
				if(ans[i+1][j-1]=='*'){now++;}
				if(ans[i+1][j]=='*'){now++;}
				if(ans[i+1][j+1]=='*'){now++;}
				
				ans[i][j] = now;
				
			}
			
		}
	}
	for(int i = 1;i<=height;i++){
		for(int j = 1;j<=width;j++){
			cout<<(char)ans[i][j];
		}
		cout<<endl;
	}
	
}
