#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> abt = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};

int getSimiliar(char a,char b){
	int _a,_b;
	if(a=='A') _a = 1;
	else if(a == 'C') _a =2;
	else if(a == 'G') _a = 3;
	else if(a == 'T') _a = 4;
	else _a = 5;
	if(b=='A') _b = 1;
	else if(b == 'C') _b =2;
	else if(b == 'G') _b = 3;
	else if(b == 'T') _b = 4;
	else _b = 5;
	return abt[_a-1][_b-1];
}
int main(){
	int la,lb;
	string a,b;
	cin >>la >> a>>lb>>b;
	a = '0' + a;
	b = '0' + b;
	vector<vector<int>> dp(la+1,vector<int>(lb+1));
	dp[0][0] = 0;
	for(int i = 1; i <= la;i++){
		dp[i][0] = dp[i-1][0] + getSimiliar('-',a[i]);
	}
	for(int j =1; j <=lb;j++){
		dp[0][j] = dp[0][j-1] + getSimiliar('-',b[j]);
	}
	
	for(int i = 1;i <= la;i++){
		
		for(int j = 1; j <= lb;j++){
			dp[i][j] = max(dp[i-1][j-1] + getSimiliar(a[i],b[j]),dp[i-1][j] + getSimiliar(a[i],'-'));
			dp[i][j] = max(dp[i][j-1] + getSimiliar('-',b[j]),dp[i][j]);
			
			
		}
		
	}
#ifdef LOCAL
	cout<<getSimiliar('-','A')<<" "<<getSimiliar('A','-')<<" "<<getSimiliar('G','-')<<endl;
	for(int i = 0;i <= la;i++){
		for(int j = 0;j <= lb;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}
#endif
	cout<<dp[la][lb];
	
}
