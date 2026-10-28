#include<bits/stdc++.h>
using namespace std;

bool ist(int x){
	bool ans = 1;
	bool i = 1;
	int len = 0;
	int _x = x;
	while(_x>0){ _x/=10;len++;}
	i = len%2;
//	cout << i <<'\n';
	while(x>0){
		if(x%2==i){
			i = !i;
		//	cout<<i<<" ";
			x/=10;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	int x,y;cin>>x>>y;
	bool ex = 0;
	for(int i=x;i<=y;i++){
		if(ist(i)) {cout<<i<<" ";
		ex = 1;}
	}
	if(!ex) cout << -1<<'\n';
	return 0;

}
