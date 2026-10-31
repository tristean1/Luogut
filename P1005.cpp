#include<bits/stdc++.h>
using namespace std;
static const int BASE = 1000000000;

struct BigInt {
	vector<int> g;                      // 小端：g[0] = 最低 9 位
	BigInt() {}
	BigInt(const string& s) {
		for (int i = (int)s.size(); i > 0; i -= 9) {
			int l = max(0, i - 9);
			g.push_back(stoi(s.substr(l, i - l)));
		}
		trim();
	}
	BigInt(int x){
		g.push_back(x % BASE);
	
	}
	
	explicit BigInt(vector<int> v) : g(std::move(v)) { trim(); }
	void trim() { while (g.size() > 1 && g.back() == 0) g.pop_back(); }
	
	bool operator<(const BigInt& o) const {
		if (g.size() != o.g.size()) return g.size() < o.g.size();
		for (int i = (int)g.size() - 1; i >= 0; i--)
			if (g[i] != o.g[i]) return g[i] < o.g[i];
		return false;
	}
	BigInt operator+(const BigInt& o) const {
		vector<int> r; int carry = 0;
		size_t n = max(g.size(), o.g.size());
		for (size_t i = 0; i < n || carry; i++) {          // 加法：要 || carry
			int s = carry;
			if (i < g.size())   s += g[i];
			if (i < o.g.size()) s += o.g[i];
			r.push_back(s % BASE);
			carry = s / BASE;
		}
		return BigInt(r);
	}
	BigInt operator*(const BigInt& o) const {
		vector<long long> t(g.size() + o.g.size(), 0);     // 先留好空间
		for (size_t i = 0; i < g.size(); i++) {
			long long carry = 0;
			for (size_t j = 0; j < o.g.size(); j++) {
				long long cur = t[i + j] + (long long)g[i] * o.g[j] + carry;
				t[i + j] = cur % BASE;                      // 立即取模
				carry    = cur / BASE;                      // 立即进位
			}
			t[i + o.g.size()] += carry;
		}
		vector<int> r(t.begin(), t.end());
		return BigInt(r);                                   // trim 会去掉前导零组
	}
	BigInt operator-(const BigInt& o) const {              // 要求 *this >= o
		vector<int> r; int borrow = 0;
		for (size_t i = 0; i < g.size(); i++) {            // 减法：不要 || borrow
			int s = -borrow + g[i];
			if (i < o.g.size()) s -= o.g[i];
			if (s < 0) { s += BASE; borrow = 1; }
			else       { borrow = 0; }
			r.push_back(s);
		}
		return BigInt(r);
	}
	friend ostream& operator<<(ostream& os, const BigInt& x) {
		os << x.g.back();
		for (int i = (int)x.g.size() - 2; i >= 0; i--)
			os << setw(9) << setfill('0') << x.g[i];
		return os;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m; cin >> n >> m;
    BigInt ans(0);
	vector<vector<int>> mp(n+1,vector<int>(m+1));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j<=m;j++){
			cin >> mp[i][j];
		}
	}
	for(int line = 1;line <= n;line++){
		//每行区间dp
		vector<vector<BigInt>> dp(m+1,vector<BigInt>(m+1,BigInt(0)));
		for(int i = 1;i<=m;i++){
			dp[i][0] = BigInt(mp[line][i]) * BigInt("2");
		}
		//dp[i][j] = i到i+j的最大值
		for(int d = 1;d <m;d++){
			for(int i = 1;i <= m-d;i++){
				int j = i+d;
				dp[i][d] = max(BigInt(2*mp[line][i])+BigInt("2")*dp[i+1][d-1],
							   BigInt(2*mp[line][j])+BigInt("2")*dp[i][d-1]);
				
			}
		}
#ifdef LOCAL
		for(int k=0;k<=m;k++){
			for(int p=0;p<=m;p++){
				cout << dp[k][p]<<" ";
			}
			cout << '\n';
		}
#endif
		ans = ans + dp[1][m-1];
		
	}
	cout << ans;
}
