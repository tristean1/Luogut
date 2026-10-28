#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long c;
	int n;
	cin >> n >> c;
	map<int,int> mp;
	for(int i  =0;i < n;i++){
		long long in;
		cin >> in;
		mp[in]++;
	}
	long long ans = 0;
	for (auto &kv : mp) {                        // 遍历 map，不是遍历数值
		long long want = (long long)kv.first + c;
		if (want > INT_MAX) continue;
		auto it = mp.find((int)want);            // find，不要用 mp[want]
		if (it != mp.end()) ans += 1LL * kv.second * it->second;
	}
	cout << ans <<'\n';
	return 0;
}
