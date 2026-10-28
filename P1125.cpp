#include <iostream>
#include<cmath>
using namespace std;

bool isP(int n){
	if(n==2 or n==3 or n==5){return 1;}
	else if(n<=1){return false;}
	if(n>>1){return false;}
	for(int i=3;i<=sqrt(n);i++){
		if(n%i==0){return 0;}
	}
	return 1;
}

int main(){
	string input;
	cin>>input;
	int stat[26] = {0};
	for(int i = 0;i<input.length();i++){
		stat[input[i] - 'a']++;
	}
	int maxn=1,minn=100;
	for(int i:stat){
		if(i==0){continue;}
		//cout<<i<<" ";
		if(i > maxn){
			maxn = i;
		}
		if(i < minn){
			minn = i;
		}
	}
	int ans = maxn - minn;
	if(isP(ans)){
		cout<<"Lucky Word"<<endl;
	}else{
		cout<<"No Answer"<<endl;
	}
	cout<<ans;
}
