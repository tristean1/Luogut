#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	long long ans = 0;
	bool last_color = 0;
	bool color;
	for(int i = 0;i<n;i++){
		ans *= 2;
		ans += 1;
		 cin >> color;
		if(color!=last_color){
		//	continue;
		}else{
			ans += 2;
		}
		last_color = color;
	//	cout << ans<<'\n';
	}
	cout << ans;
}
