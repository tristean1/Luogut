#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t;
	cin >> n >>t ;
	int ans = 0;
	for(int i =0;i<n;i++){
		int in;
		cin >> in;
		if(in==t){
			ans += 2;
		}else if(abs(in-t)==1 || abs(in-t)==2){
			ans += 1;
		}else {
			
		}
	}
	cout << ans << '\n';
}
