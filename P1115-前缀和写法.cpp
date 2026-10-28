#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	//前缀和版本
	long long s = 0, mn = 0, ans = LLONG_MIN;   // mn 就是 min(S[0..i-1])
	long long x;
	for(int i = 1; i <= n; i++){
		cin >> x;                    // 甚至不需要存数组了（流式处理）
		s += x;                      // s = S[i]
		ans = max(ans, s - mn);      // 以 i 结尾的最大子段和
		mn = min(mn, s);             // ★ 把 S[i] 纳入"最小值"，供下一轮用
	}
	cout << ans << '\n';
	
	
}
