#include<bits/stdc++.h>
using namespace std;

string mid;
string front;

void dfs(int ml,int fl,int len){
	if(len ==0 ) return;
	//cout << ml << " "<<fl <<" "<<len<<'\n';
	char father = front[fl];
	
	int k =0;
	while(mid[ml+k] != father){
		++k;
	}
//	len = loc - ml;
	//left
	dfs(ml,fl+1,k);
	dfs(ml+k+1,fl+1+k,len-k-1);
	cout << father;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> mid >> front;
	dfs(0,0,mid.size());
	
}
