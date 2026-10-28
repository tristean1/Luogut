#include<iostream>
using namespace std;

string repeat(string a,int times){
	string ans = "";
	for(int i = 0;i<a.length();i++){
		for(int j=0;j<times;j++){
			ans += a[i];
		}
	}
	return ans;
}

int main(){
	int r,c,zr,zc;
	string a,ans;
	cin>>r>>c>>zr>>zc;
	for(int i = 0;i<r;i++){
		a = "";
		cin>>a;
		a = repeat(a,zc);
		a += '\n';
		for(int j = 0;j <zr;j++){
			ans +=a;
		}
	}
	cout<<ans;
	return 0;
}
