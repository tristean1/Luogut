#include<bits/stdc++.h>
using namespace std;

int main(){
	int l;
	cin >> l;
	int n;
	cin >> n;
	vector<int> bridge(l+2,0);
	for(int i =1;i<=n;i++){
		int in;cin>>in;
		bridge[in]++;
	}
	int maxt=0;
	int mint=0;
	for(int d=1;d<=(l+1)/2;d++){
		if(bridge[d]>0 || bridge[l+1-d]>0){
			int man = max(bridge[d],bridge[l+1-d]);
			int dis = l+1-d;
			maxt = max(man-1,0) + dis;
			break;
		}
	}
	for(int d = (l+1)/2;d>0;d--){
		if(bridge[d]>0 || bridge[l+1-d]>0){
			int man = max(bridge[d],bridge[l+1-d]);
			int dis = d;
			mint = max(man-1,0) + dis;
			break;
		}
	}
	cout << mint << " " << maxt<<'\n';
	return 0;
}
