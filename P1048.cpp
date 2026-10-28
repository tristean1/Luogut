#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t,m;
	cin>>t>>m;
	vector<vector<int>> input(m+1,vector<int>(2,0));
	for(int i = 1;i <= m;i++){
		cin>>input[i][0];
		cin>>input[i][1];
	}
	//cout<<"io"<<endl;
	//vector<vector<int>> value(m+1,vector<int>(t+1,0));//前i株草药，时间不超过j的最大价值
//	value[0][0] = 0;
	vector<int> dp(t + 1, 0);
	for(int i = 1; i <= m; i++){
		for(int j = t; j >= input[i][0]; j--){        // ★ 倒序
			dp[j] = max(dp[j], dp[j - input[i][0]] + input[i][1]);
		}
	}
	cout << dp[t] << '\n';
}
