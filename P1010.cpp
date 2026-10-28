#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	const string s[] = {"2(0)","2","2(2)"};
	string ans;
	int i = 0;
	while(n > 0){
		if(n&1){
			ans = s[i] +"+"+ ans;
		}
		i++;
		n=n>>1;
	}
	cout<<ans;
}
