#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> delta;
vector<int> classroom;
vector<array<int,3>> demand;
bool check(int x){
	//在第x天是否出现教室不够
	//生成delta
	delta[0] = classroom[0];
	for(int i = 1;i < n;i++){
		delta[i] = classroom[i] - classroom[i-1];
	}
	for(int j=0;j<x;j++){
		delta[demand[j][1]-1] -= demand[j][0];
		delta[demand[j][2]] += demand[j][0];
	}
	long long sum  = 0 ;
	for(int i = 0;i < n;i++){
		sum += delta[i];
		if(sum < 0){//教室不够
			return false;
		}
	}//教室足够
	return true;
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int n,m;
	cin>>n>>m;
	classroom.resize(n);
	demand.resize(m);
	delta.resize(n+1);
	for(int i = 0;i < n;i++){
		cin >> classroom[i];
	}
	for(int i = 0;i < m;i++){
		cin>>demand[i][0];
		cin>>demand[i][1];
		cin>>demand[i][2];
	}
	int lo = 0;
	int hi = m-1;
	int ans = m-1;
	int mid;
//	for(int i = 0;i < m;i++){
//			cout<<check(i)<<" ";
//	}
	//cout<<endl;
	while(lo <= hi){
		mid = (lo + hi) /2;
		if(check(mid)){
			ans = mid;//试试更大的
			lo = mid + 1;
			
		}else{
			hi = mid - 1;
			
		}
	}
//	cout<<ans<<endl;
	if(ans==m-1){cout<<0;}else{cout<<-1<<"\n"<<ans+1;}
}
