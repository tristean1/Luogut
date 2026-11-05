#include<bits/stdc++.h>
using namespace std;
vector<int> lc;
vector<int> rc;
/*queue<pair<int,int>> q;
int main(){
	lc.push_back(0);
	rc.push_back(0);
	int n;cin >> n;
	for(int i = 1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		lc.push_back(l);
		rc.push_back(r);
	}
	
//	cout<<'\n';
	q.push({1,0});
	int mn = 0;
	while(!q.empty()){
		auto[x,s] = q.front();q.pop();
		s++;
		if(lc[x]!=0){
			q.push({lc[x],s} );
		}
		if(rc[x]!=0){
			q.push({rc[x],s});
		}
		if(lc[x]==0 && rc[x]==0){
			mn = max(mn,s);
		}
	}
	cout << mn<<'\n';return 0;
}
*/
queue<int> q;
int main(){
	lc.push_back(0);
	rc.push_back(0);
	int n;cin >> n;
	for(int i = 1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		lc.push_back(l);
		rc.push_back(r);
	}
	q.push(1);
	int mn = 0;
	while(!q.empty()){
		int sz = q.size();
		mn++;                        // 当前层的层号 = 深度
		while(sz--){
			int x = q.front(); q.pop();
			if(lc[x]) q.push(lc[x]);
			if(rc[x]) q.push(rc[x]);
		}
	}
	cout << mn << '\n';
}
