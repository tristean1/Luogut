#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	vector<int> s;
	for(int i = 1;i<=q;i++){
		int type;
		cin >> type;
		if(type == 1){
			int in;
			cin >> in;
			s.push_back(in);
			sort(s.begin(),s.end());
		}else if(type==2){
			int x,k;
			cin >> x >> k;
			auto it = lower_bound(s.begin(),s.end(),x);
			if(it == s.end() || it+k>=s.end()){
				cout << -1 << '\n';
				continue;
			}
			cout <<s[k-1] << '\n';
		}else {
			int x,k;
			k--;
			cin >> x >> k;
			auto it = upper_bound(s.begin(),s.end(),x);
			if(it == s.end()){
				cout << -1 <<'\n';
				continue;
			}
			cout <<*(it+k-1)<< '\n';
		}
	}
}
