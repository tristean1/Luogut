#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> f(n+1);
	vector<int> g(n+1);
	vector<int> a(n+1);
	for(int i = 1;i <=n;i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n;i++){
		f[i] = 1;
		for(int j =1;j <i;j++){
			if(a[j] < a[i]){
				f[i] = max(f[i],f[j] + 1);
			}
		}
	}
	for(int i = n;i>0;i--){
		g[i] = 1;
		for(int j = n;j>i;j--){
			if(a[j] < a[i] && j > 1){
				g[i] = max(g[i],g[j] + 1);
			}
		}
	}
	int mn = INT_MIN;
	for(int i = 1; i <= n;i++){
		int mp = f[i] + g[i] -1;
		if(mp > mn){
			mn =mp;
		}
	}
	cout<<n-mn;
}
