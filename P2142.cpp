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

int main() {
    string a, b; cin >> a >> b;
    BigInt A(a), B(b);
    if (A < B) { cout << '-' << (B - A); }
    else       { cout << (A - B); }
    cout << '\n';
}