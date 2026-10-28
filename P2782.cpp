#include<bits/stdc++.h>
using namespace std;

struct req{
	int begin;
	int end;
	bool operator<(const req &another){
		return begin < another.begin;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<req> requests(n+1);
	for(int i = 1;i <= n;i++){
		cin>>requests[i].begin>>requests[i].end;
	}
	sort(requests.begin()+1,requests.end());
	//dp找requests【end】的最长增子序列
	vector<int> tails;
	for(int i = 1;i <= n;i++){
		int y = requests[i].end;
		auto it = lower_bound(tails.begin(),tails.end(),y);
		if(it==tails.end()) tails.push_back(y);
		else *it = y;
	}
	cout<<tails.size()<<'\n';
}
