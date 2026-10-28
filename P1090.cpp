#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int x;
	priority_queue<long long,vector<long long>,greater<long long>> pq;
	for(int i = 0;i < n;i++){
		cin>>x;
		pq.push(x);
	}
	long long ans = 0;
	while(pq.size() > 1){
		long long a =pq.top();pq.pop();
		long long b = pq.top(); pq.pop();
		ans += a+ b;
		pq.push(a+b);
	}
	cout<<ans<<endl;
	
	
	
}
