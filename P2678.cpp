#include<bits/stdc++.h>
using namespace std;

vector<int> delta_distance;
vector<int> trying;
int m;
bool check(int min_distance){
	int can_move = 0;
	int size = delta_distance.size();
	trying = delta_distance;
	for(int i = 0;i<size;i++){
		//cout<<trying[i]<<" ";
		if(trying[i]<min_distance){
			can_move++;
			if(i<size-1){trying[i+1]+=trying[i];}
		}
		//if(can_move > m){return false;}
	}
	//cout<<"check "<<min_distance<<" "<<can_move<<" "<<m<<endl;
	return can_move <= m;
}

int main(){
	int l,n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>l>>n>>m;
	if(n==0){cout<<l;return 0;}
	int input =0;
	vector<int> distance(n);
	delta_distance.resize(n+1);
	trying.resize(n+1);
	cin>>distance[0];
	for(int i =1;i<n;i++){
		cin>>distance[i];
	
		
	}
	delta_distance[0] = distance[0];
	for(int i = 1;i < n;i++){
		delta_distance[i] = distance[i] -distance[i-1];
		//cout<<delta_distance[i]<<" ";
	}
	delta_distance[n] = l - distance[n-1];
	//sort(delta_distance.begin(),delta_distance.end());
	
	//二分查找合适的min_distance 下界为1 上界为max(delta_distance)
	int lo = 1;
	int hi = l;
	int mid,ans;
	ans = 1;
	while(lo<=hi){
		
		mid = (lo + hi) /2 ;
		//cout<<lo<<" "<<mid<<" "<<hi<<endl;
		if(check(mid)){
			ans = mid;
			lo = mid +1 ;
		}else{
			hi = mid -1;
		}
	}
	cout<<ans;
	
	
}
