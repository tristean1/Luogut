#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	//DP版本；
	vector<int> input(n+1);
	for(int i = 1;i <= n;i++){
		cin >> input[i];
	}
	vector<int> dp(n+1,0);
	dp[1] = input[1];
	for(int i = 2; i <= n;i++){
		dp[i] = max(dp[i-1] + input[i],input[i]);
	}
	long long mn = LLONG_MIN;
	for(int i = 1; i <= n; i++){
	//	cout<<dp[i]<<" ";
		if(dp[i] > mn){
			mn = dp[i];
		}
	}
	cout<<mn;
}
