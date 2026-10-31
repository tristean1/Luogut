#include<bits/stdc++.h>
using namespace std;
int n,m,x,y; 
const int dx[] = {2,2,1,1,-1,-1,-2,-2};
const int dy[] = {1,-1,2,-2,2,-2,1,-1};
void search(int step,int hx,int hy,vector<vector<int>> &ans,vector<vector<bool>> &vis){
	if(step > ans[hx][hy] && vis[hx][hy]) return;
	vis[hx][hy] = 1;
	if(ans[hx][hy]==-1) ans[hx][hy] = step;
	else ans[hx][hy] = min(ans[hx][hy],step);
	step++;
	for(int i = 0;i<8;i++){
		int ax = hx + dx[i];int ay =hy +  dy[i];
		if(1 <= ax && ax <= n && 1 <= ay && ay <= m){
			search(step,ax,ay,ans,vis);
		}
	}
	

}

int main(){
	cin >> n >> m >> x >> y;
	
	vector<vector<int>> ans(n+1,vector<int>(m+1,-1));
	vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));
	 search(0,x,y,ans,vis);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout << ans[i][j]<<" ";
		}
		cout << '\n';
	}
	
}
