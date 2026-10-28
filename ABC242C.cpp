#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<int,long long> mp = {{1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1}};
	long long base =998244353;
	//cout << base;
	for(int i  = 1;i<n;i++){
		map<int,long long> cmp;
		cmp[1] = mp[2] + mp[1];
		cmp[1] %= base;
		for(int j  =2;j<=8;j++){
			cmp[j] = mp[j-1] + mp[j+1] + mp[j];
			cmp[j] %= base;
		}
		cmp[9] = mp[8] + mp[9];
		cmp[9] %= base;
		mp = cmp;
	}
	long long ans = 0;
	for(int i = 1;i<=9;i++){
		ans += mp[i];
		ans %= base;
	}
	cout << ans;
	
}
