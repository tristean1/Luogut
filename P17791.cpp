#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin >> n;
	for(int i = n;i>0;i--){
		for(int j = 0;j<i;j++){
			if(!((n-i)&1)){
				cout<<'+';
			}else{
				cout<<'-';
			}
		}
		cout<<'\n';
	}
}
