#include<bits/stdc++.h>
using namespace std;
struct BigInt {
    vector<int> g;                     // 小端：g[0] = 最低 9 位
    BigInt() {}
    BigInt(const string& s) {
        for (int i = (int)s.size(); i > 0; i -= 9) {
            int l = max(0, i - 9);
            g.push_back(stoi(s.substr(l, i - l)));
        }
    }
    explicit BigInt(vector<int> v) : g(std::move(v)) {}

    BigInt operator+(const BigInt& o) const {
        vector<int> r;
        int carry = 0;
        size_t n = max(g.size(), o.g.size());
        for (size_t i = 0; i < n || carry; i++) {
            int s = carry;
            if (i < g.size())   s += g[i];
            if (i < o.g.size()) s += o.g[i];
            r.push_back(s % 1000000000);
            carry = s / 1000000000;
        }
        return BigInt(r);
    }
    BigInt operator-(const BigInt& o) const{
        vector<int> r;
        for(size_t i=0;i < o.g.size();i++){
            r.push_back(-o.g[i]);
        }
        return *this + BigInt(r);
    }
    friend ostream& operator<<(ostream& os, const BigInt& x) {
        os << x.g.back();
        for (int i = (int)x.g.size() - 2; i >= 0; i--)
            os << setw(9) << setfill('0') << x.g[i];
        return os;
    }
};

int main(){
    string input;
    cin >> input;
    BigInt a(input);
    //a.print();
    cin >> input;
    BigInt b(input);
    BigInt c = a - b;
    cout << c;
    
}