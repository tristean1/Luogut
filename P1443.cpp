#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy;
int dis[405][405];
const int dx[] = {2,2,1,1,-1,-1,-2,-2};
const int dy[] = {1,-1,2,-2,2,-2,1,-1};


int main(){
	cin >> n >> m >> sx >> sy;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <=m;j++){
			dis[i][j] = -1;
		}//数组初始化
	}
	queue<pair<int,int>> q;
	dis[sx][sy] = 0;
	q.push({sx,sy});
	while(!q.empty()){
		auto [x,y] = q.front();
		q.pop();
		for(int d = 0;d < 8;d++){
			int nx = x + dx[d],ny = y + dy[d];
			if(nx < 1 || nx > n || ny < 1||ny > m) continue;
			if(dis[nx][ny] != -1) continue;
			dis[nx][ny] = dis[x][y] + 1;
			q.push({nx,ny});
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <=m;j++){
			cout << dis[i][j]<<" ";
		}
		cout << '\n';
	}
	return 0;
	
}
