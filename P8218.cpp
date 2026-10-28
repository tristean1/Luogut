#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> input(n+1);
	input[0] = 0;
	int in;
	for(int i =1;i<=n;i++){
		cin>>in;
		input[i] = input[i-1] + in;
	//	cout<<input[i]<<" ";
	}

	//cout<<endl;
	int m;
	cin>>m;
	//vector<int> ans(m,0);
	int lo,hi;
	int ans = 0;
	for(int i = 0;i<m;i++){
		ans = 0;
		cin>>lo>>hi;
		//cout<<i<<" "<<input[hi]<<" "<<input[lo-1];
		ans = input[hi] - input[lo -1];
		cout<<ans<<'\n';
	}
	
	
	
}
