#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m; cin >> n >> m;
	vector<int> man(n+1);
	vector<int> melon(m+1);
	for(int i = 1;i<=n;i++) cin >> man[i];
	for(int i=1;i<=m;i++) cin >> melon[i];
	bitset<305> carried; 
	
	vector<int> used(n+1,0);
	bool c = 1;
	while(c){
		c = 0;
		for(int i =1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				if(!carried[j] && melon[j]<=man[i]){
					carried[j] = 1;
					used[i] += melon[j];
					c = 1;
					break;
				}
			}
		}
	}
	for(int i = 1;i<=n;i++) cout<<used[i]<<" ";
	cout<<'\n';
	return 0;
	
}
