#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,t;
	cin >> t >> m;
	vector<int> cost(m+1);
	vector<int> val(m+1); //1-based
	for(int i = 1;i <= m;i ++){
		cin>>cost[i]>>val[i];
	}
	vector<long long> dp(t+2,0);//1-based +1哨兵
	//dp[t] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = cost[i]; j <= t; j++)              // ★ 正序，就这一处不同
			dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
	cout << dp[t] << '\n';
}
