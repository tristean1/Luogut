#include<bits/stdc++.h>
using namespace std;

void search(int i,int j,vector<vector<char>> &mp,vector<vector<bool>> &visited){
	if(visited[i][j] ) return ;
	
	if(mp[i][j]=='.') return;
//	cout << i << " "<< j<<'\n';
	visited[i][j] = 1;
	search(i+1,j+1,mp,visited);
	search(i-1,j-1,mp,visited);
	search(i+1,j-1,mp,visited);
	search(i-1,j+1,mp,visited);
	search(i,j+1,mp,visited);
	search(i,j-1,mp,visited);
	search(i+1,j,mp,visited);
	search(i-1,j,mp,visited);
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char>> mp(n+2,vector<char>(m+2,'.'));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> mp[i][j];
		}
	}
	int ans = 0;
	vector<vector<bool>> visited(n+2,vector<bool>(m+2,0));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(visited[i][j]) continue;
			else{
				if(mp[i][j] == 'W'){
					search(i,j,mp,visited);
					ans++;
				}
			}
		}
	}
	cout << ans <<'\n';
}
