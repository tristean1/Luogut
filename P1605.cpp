#include<bits/stdc++.h>
using namespace std;
	int n,m,t; 
	int sx,sy,fx,fy;
int search(int sx,int sy,int fx,int fy,
		   vector<vector<bool>> &mp,
		   vector<vector<bool>> &visited){
	if(visited[sx][sy]) return 0;
	if(!mp[sx][sy]) return 0;
	if(sx==fx && sy == fy) return 1;
	visited[sx][sy] = 1;
	int ans = 0;
	if(sx<n)	ans += search(sx+1,sy,fx,fy,mp,visited);
	if(sx>=2)	ans += search(sx-1,sy,fx,fy,mp,visited);
	if(sy<m)	ans += search(sx,sy+1,fx,fy,mp,visited);
	if(sy>=2)	ans += search(sx,sy-1,fx,fy,mp,visited);
	visited[sx][sy] = 0;
	return ans;
}

int main(){
cin >> n >> m >> t;

	cin >> sx >> sy >> fx >> fy;
	vector<vector<bool>> mp(n+1,vector<bool>(m+1,1));
	vector<vector<bool>> visited(n+1,vector<bool>(m+1,0));
	for(int i =0;i<t;i++){
		int x,y; cin >>x >> y;
		mp[x][y] = 0;
	}
	int ans = 0;
	ans = search(sx,sy,fx,fy,mp,visited);
	cout << ans;
	return 0;
}
