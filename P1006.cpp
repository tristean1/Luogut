#include<bits/stdc++.h>
using namespace std;

int main(){
//	ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int m,n;
	cin >>m>> n;
	vector<vector<int>> mp(m+1,vector<int>(n+1,0));
	for(int i = 1;i<=m;i++){
		for(int j =1;j<=n;j++){
			cin >> mp[i][j];
		}
	}
#ifdef LOCAL
	for(int i = 0;i < n;i++){ for(int j = 0;j<n;j++) cout<<mp[i+1][j+1]<<" ";cout<<'\n';}
#endif
//	return 0;
	//const int N = 10;
	//int dp[N][N][N][N] = {0};
	vector<vector<vector<vector<int>>>> dp(m+1,vector<vector<vector<int>>>(n+1,vector<vector<int>>(m+1,vector<int>(n+1,0))));
	//dp[1][2][2][1] = 0;
	//dp[1][1][1][1] = 0;
//	for (int i=1;i<=m;++i) for (int j=1;j<=n;++j) scanf("%d",&mp[i][j]);
	dp[1][1][1][1] = mp[1][1];
	for (int s=3; s<=m+n; ++s) {                 // s = x+y，完整范围
		int lo = max(1, s-n), hi = min(m, s-1);  // 这里 n 是列数，管 y≤n
		for (int x1=lo; x1<=hi; ++x1)
			for (int x2=x1; x2<=hi; ++x2) {
				int y1 = s-x1, y2 = s-x2;
				int best = max({dp[x1-1][y1][x2-1][y2], dp[x1-1][y1][x2][y2-1],
					dp[x1][y1-1][x2-1][y2], dp[x1][y1-1][x2][y2-1]});
				dp[x1][y1][x2][y2] = best + mp[x1][y1] + (x1==x2 ? 0 : mp[x2][y2]);
			}
	}
	
		cout << dp[m-1][n][m][n-1]<<'\n';
	return 0;
	
}
