#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	int mini = INT_MAX;
	cin >> n >> m;
	for(int i =0;i<n;i++){
		int maxn = 0;
		for(int j =0;j<m;j++){
			int in;
			cin >> in;
			maxn = max(maxn,in);
		}
		mini = min(mini,maxn);
	}
	cout << mini <<'\n';
	return 0;
}
