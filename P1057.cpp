#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	long long ans = 0;
	vector<int> w(n,0);
	w[0] = 1;
	for(int i =0;i<m;i++){
		vector<int> ball(n,0);
		long long sum = 0;
		for(int i = 0;i < n;i++){
			if(i==0){
				ball[i] = w[n-1] + w[i+1];
			}else if(i==n-1){
				ball[i] = w[i-1] + w[0];
			}else{
				ball[i] = w[i-1] + w[i+1];
			}
			
		}
		w = ball;
//		for(int k  =0;k<n;k++) cout << ball[k] << " ";cout<<'\n';
	}
	cout << w[0];
}
