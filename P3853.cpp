#include<bits/stdc++.h>
using namespace std;
vector<int> dist;
int n,k,l;
bool check(int mid){
	int cnt = 0;
	for(int i  = 1;i < n;i++){
		cnt += (dist[i] - dist[i-1] -1) / mid;//向上取整
		if(cnt > k){return false;}
	}
	return true;
	
	
	//cout<<"check "<<mid<<(set_num <= k)<<endl;
	//return set_num <= k;
}//能达到这个空旷指数

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>l>>n>>k;
	dist.resize(n);
	for(int i = 0;i < n;i++){
		cin>>dist[i];
	}
	
	int lo =1;
	int hi = l;
	int ans = 1;
	int mid;
	while(lo <= hi){
		mid = (lo + hi)/2;
		if(check(mid)){
			ans = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1 ;
			
		}
		//cout<<"循环"<<lo<<" "<<mid<<" "<<hi<<endl;
	}
	cout<<ans;
}
