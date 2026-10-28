#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int target_d = 0;
	vector<int> delta(n+1);
	for(int i = 1;i<=n;i++){
		int a,b;
		cin >> a>> b;
		delta[i] = 2*(b- a); //调换顺序产生两倍差值
		target_d= target_d + a - b;
	}
	vector<int> rev(n+1); //达到最小值所需的旋转次数
	vector<int> dp(n+1);//前n项与s1-s2的最小差值
	int min_ans = INT_MAX;
	//int rev = 0;
	for(int i = 1;i <= n;i++){
		dp[i] = delta[i]; //新开
		rev[i] = 1;
		for(int j =1;j < i;j++){
			if(abs(dp[j] + delta[i] -target_d) < abs(dp[i])){
				dp[i] = delta[i] + dp[j];
				//if(rev[j] + 1 < rev[i] | rev[i] == 0)
				rev[i] = rev[j] + 1;
			}else if(abs(dp[j] + delta[i] -target_d) == abs(dp[i])){
				//相同大小保留旋转次数小的
				rev[i] = min(rev[i],1+rev[j]);
			}
		}
	}
	rev[0] = 0;
	dp[0] = -target_d;
#ifdef LOCAL
	for(int i  =0; i<= n;i++){
		cout<<rev[i]<<" ";
	}
	cout<<endl;
	for(int i  =0; i<= n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
#endif
	int min_dp = INT_MAX;
	
	for(int i =0; i<=n;i++){
		//cout<<target_d<<endl;
		//cout<<dp[i]<<" ";
		if(dp[i] < min_dp){
			min_dp = dp[i];
			min_ans = rev[i];
		}else if(dp[i] == min_dp){
			min_ans = min(min_ans,rev[i]);
			//cout<<min_ans<<rev[i]<<endl;
		}
		//cout<<min_ans<<" ";
		
	}
	cout<<min_ans;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	const int OFF = 5000;                 // 偏移量：Σ|d_i| ≤ 5n ≤ 5000
	const int SZ  = 10001;                // 差值范围 [-5000, 5000]
	const int INF = 1000000000;
	
	vector<int> dp(SZ, INF), ndp(SZ, INF);
	dp[OFF] = 0;                          // 0 张牌，差值 0，旋转 0 次
	
	for(int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		int d = a - b;                    // 不翻时这张牌对 (S1-S2) 的贡献
		
		fill(ndp.begin(), ndp.end(), INF);
		for(int j = 0; j < SZ; j++){
			if(dp[j] == INF) continue;
			// 不翻：贡献 +d，次数不变
			if(j + d >= 0 && j + d < SZ)
				ndp[j + d] = min(ndp[j + d], dp[j]);
			// 翻：贡献 -d，次数 +1
			if(j - d >= 0 && j - d < SZ)
				ndp[j - d] = min(ndp[j - d], dp[j] + 1);
		}
		dp.swap(ndp);
	}
	
	int bestDiff = INT_MAX, bestRot = INT_MAX;
	for(int j = 0; j < SZ; j++){
		if(dp[j] == INF) continue;
		int diff = abs(j - OFF);          // ★ 取绝对值
		if(diff < bestDiff || (diff == bestDiff && dp[j] < bestRot)){
			bestDiff = diff;
			bestRot  = dp[j];
		}
	}
	cout << bestRot << '\n';
}
