#include<bits/stdc++.h>
using namespace std;

int main(){
//	ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> mp(n+1,vector<int>(n+1,0));
	while(1){
		int x,y,z; cin >> x >> y >> z;
		if(x==0&&y==0&&z==0){
	break;
		}
			mp[x][y] = z;
		
	}
#ifdef LOCAL
	for(int i = 0;i < n;i++){ for(int j = 0;j<n;j++) cout<<mp[i+1][j+1]<<" ";cout<<'\n';}
#endif
//	return 0;
    const int N = 10;
	int dp[N][N][N][N] = {0};
	//dp[1][2][2][1] = 0;
	//dp[1][1][1][1] = 0;
	for(int s = 2;s <= n;s++){
		for(int x1 = 1;x1 <=s;x1++){
			//相邻两块不能争抢同一块，而中间那块又必定被用到。
			for(int x2 = x1+1;x2 <= s;x2++){
				int y1 = s - x1 + 1;
				int y2 = s - x2 + 1;
				//int t1 = max(dp[x1-1][y1][x2][y2],dp[x1][y1-1][x2][y2]);
				//int t2 = max(dp[x1][y1][x2-1][y2],dp[x1][y1][x2][y2-1]);
				dp[x1][y1][x2][y2] = mp[x1][y1]+mp[x2][y2] + 
				max({dp[x1-1][y1][x2-1][y2],dp[x1][y1-1][x2-1][y2],dp[x1-1][y1][x2][y2-1],dp[x1][y1-1][x2][y2-1]});
			}
		}
	}

	for(int s = n+1;s < 2*n;s++){
		for(int x1 = s-n+1;x1 <=n;x1++){
			for(int x2 = x1+1;x2 <=n;x2++){
				int y1 = s - x1 + 1;
				int y2 = s - x2 + 1;
				dp[x1][y1][x2][y2] = mp[x1][y1]+mp[x2][y2] + 
				max({dp[x1-1][y1][x2-1][y2],dp[x1][y1-1][x2-1][y2],dp[x1-1][y1][x2][y2-1],dp[x1][y1-1][x2][y2-1]});
			}
		}
	}
	if(n==1){
		cout << mp[1][1]<<'\n';
	}else
	cout << dp[n-1][n][n][n-1]+mp[1][1]+mp[n][n]<<'\n';
	return 0;
	
}
