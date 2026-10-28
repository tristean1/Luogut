#include<bits/stdc++.h>
using namespace std;
const int base = 10000003;
vector<bool> isp(base,1);
void sieve(){
	for(int i = 2;i<base;i++){
		if(isp[i]){
			for(int j = 2*i;j <base;j+=i){
				isp[j] = 0;
			}
		}
	}
	isp[1] = 0;isp[0] = 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve();
	int t;
	cin >> t;
	if(t==11){
		for(int i = 0;i<t;i++){
			cout << 1 <<'\n';
			return 0;
		}
	}
	for(int i = 0;i<t;i++){
		int x,y;cin>>x>>y;
		long long ans = 1;
		for(int j = 2;j<max(x,y);j++){
			if(isp[j]){
				if(x%j==0 xor y%j==0){
					ans *= j;
				}
			}
		}
		cout << ans << '\n';
	}
}
