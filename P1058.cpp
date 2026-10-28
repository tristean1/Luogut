#include<bits/stdc++.h>
using namespace std;

void print_cube(vector<vector<char>> &p,int x,int y){
	p[x-3][y] = '+';
	p[x][y]='+';
	p[x][y+4]='+';
	p[x-5][y+2]='+';
	p[x-3][y+4]='+';
	p[x-5][y+6]='+';
	p[x-2][y+6]='+';
	p[x-1][y]=p[x-2][y]='|';
	p[x-1][y+4]=p[x-2][y+4]='|';
	p[x-3][y+6]=p[x-4][y+6]='|';
	p[x][y+1]=p[x][y+2]=p[x][y+3]='-';
	p[x-3][y+1]=p[x-3][y+2]=p[x-3][y+3]='-';
	p[x-5][y+3]=p[x-5][y+4]=p[x-5][y+5]='-';
	p[x-4][y+1]=p[x-4][y+5]=p[x-1][y+5]='/';
	p[x-1][y+1]=p[x-1][y+2]=p[x-1][y+3]=' ';
	p[x-2][y+1]=p[x-2][y+2]=p[x-2][y+3]=' ';
	p[x-4][y+2]=p[x-4][y+3]=p[x-4][y+4]=' ';
	p[x-3][y+5]=p[x-2][y+5]=' ';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m,n; cin >> m >> n;
	vector<vector<int>> mp(m,vector<int>(n));
	int mh = 0;
	int my = 0;
	for(int x=0;x<m;x++){
		for(int y=0;y<n;y++){
			cin >> mp[x][y];
			if(mp[x][y]>mh){
				mh = mp[x][y];
				my = y;
			}
		}
	}
	int length = 4*n+2*m+1;
	//cout<<length<<'\n';
	int height = 4+m*2+3*mh+2+2*my;
	vector<vector<char>> ans(height,vector<char>(length,'.'));
	//print_cube(ans,10,10);
	for(int h=0;h<mh;h++){
		for(int i =0;i<m;i++){
			for(int j = 0;j<n;j++){
				//cout<<i<<" "<<j<<" "<<'\n';
				if(mp[i][j]>h){
					
					print_cube(ans,5+i*2+3*(mh-1-h),2*(m-i-1)+4*j);
				}
			}
		}
	}
	for(int i = 0;i<height;i++){
		string _ans;
		bool p = 0;
		for(int j=0;j<length;j++){
			if(ans[i][j]!='.'){
				p =1;
			}
			_ans += ans[i][j];
		}
		if(p){
			cout<<_ans<<'\n';
		}
	}
}
