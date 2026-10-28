#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,t;
	cin >> t;
	for(int k = 0;k<t;k++){
	cin >> n >> m;
	vector<vector<int>> input(n,vector<int>(3));
	for(int i =0;i<n;i++){
		cin >> input[i][0] >> input[i][1] >> input[i][2];
	}
	vector<int> dp(m+1,0);
	for(int i =0;i<n;i++){
		if(input[i][2]==1){
			//只有一个
			for(int j = m;j >= input[i][0];j--){
				dp[j] = max(dp[j],dp[j-input[i][0]]+input[i][1]);
			}
		}else{
			for(int j = input[i][0];j <=m;j++){
				dp[j] = max(dp[j],dp[j-input[i][0]]+input[i][1]);
			}
		}
	}
	cout << dp[m] << '\n';
	}
}
