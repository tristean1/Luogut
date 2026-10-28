#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int r;
	cin >> r;
	vector<vector<int>> number(r+1,vector<int>(r+1,0));
	for(int i  = 1 ;i <= r;i++){
		for(int j = 1;j <= i;j++){
			int input;
			cin >> input;
			number[i][j] = input;
		}//1-based
	}
	vector<vector<int>> ans(r+1,vector<int>(r+1,0));
	ans[1][1] = number[1][1];
	
	for(int i = 1; i <= r;i++){
		for(int j = 1;j<=i;j++){
			ans[i][j] = max(ans[i-1][j],ans[i-1][j-1]) + number[i][j];
			#ifdef LOCAL
			for(int i = 0;i <= r;i++){
				for(int j = 0; j <= i;j++){
					cout<<ans[i][j]<<" ";
				}
				cout<<'\n';
			}
			#endif
		}
	}
	int max  = 0;
	for(int i = 0;i<=r;i++){
		if(ans[r][i] > max){
			max = ans[r][i];
		}
	}
	cout<<max;

}
