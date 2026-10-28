#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio((false));
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> stones(n+1);
	for(int i = 1;i <= n;i++){
		cin >> stones[i];
	}
	stones[0] = 0;
	sort(stones.begin(),stones.end());
	int lo = 0;
	int hi = n;
	bool higher = 1;
	long long consume = 0;
	while(lo <= hi){
		
		consume += (stones[hi]-stones[lo])*(stones[hi]-stones[lo]);
		if(higher){
			lo++;
		}else{
			hi--;
		}	
		higher =!higher;
	}
	cout<<consume;
}
