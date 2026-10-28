#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int tmp;
	int ans;
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));//dp[i][j] 操作数i个，栈j个时的输出种类
	dp[n][0] = 1;
	for(int i = n-1;i >=0;i--){
		for(int j=n-i;j>=0;j--){
			if(0<=i+1&&i+1<=n&&0<=j-1&&j-1<=n) dp[i][j] += dp[i+1][j-1];
			if(0<=i&&i<=n&&0<=j+1&&j+1<=n) dp[i][j] += dp[i][j+1];
				
		//	dp[i][j] = dp[i+1][j-1] + dp[i][j+1];
		}
	}

	cout << dp[0][0] << '\n';
	return 0;
}
