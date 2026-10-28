#include<bits/stdc++.h>
using namespace std;

int main(){
	int bx,by,hx,hy;
	cin >> bx >> by >> hx >> hy;
	vector<vector<bool>> mp(bx+1,vector<bool>(by+1,1));
	mp[hx][hy]=0;
	if(0<=hx+2&&hx+2<=bx&&0<=hy+1&&hy+1<=by)	mp[hx+2][hy+1]=0;
	if(0<=hx+2&&hx+2<=bx&&0<=hy-1&&hy-1<=by)	mp[hx+2][hy-1]=0;
	if(0<=hx+1&&hx+1<=bx&&0<=hy+2&&hy+2<=by)	mp[hx+1][hy+2]=0;
	if(0<=hx+1&&hx+1<=bx&&0<=hy-2&&hy-2<=by)	mp[hx+1][hy-2]=0;
	if(0<=hx-2&&hx-2<=bx&&0<=hy+1&&hy+1<=by)	mp[hx-2][hy+1]=0;
	if(0<=hx-2&&hx-2<=bx&&0<=hy-1&&hy-1<=by)	mp[hx-2][hy-1]=0;
	if(0<=hx-1&&hx-1<=bx&&0<=hy+2&&hy+2<=by)	mp[hx-1][hy+2]=0;
	if(0<=hx-1&&hx-1<=bx&&0<=hy-2&&hy-2<=by)	mp[hx-1][hy-2]=0;
	vector<vector<long long>> dp(bx+1,vector<long long>(by+1,0));
	dp[0][0] = 1;
		
	for(int x=0;x<=bx;x++){
		for(int y=0;y<=by;y++){
			if(mp[x][y]){
				if(x>=1) dp[x][y] += dp[x-1][y];
				if(y>=1) dp[x][y] += dp[x][y-1];
			//	mp[x][y] = mp[x-1][y] + mp[x][y-1];
			
			}
		}			
	}

	cout << dp[bx][by] <<'\n';
}
