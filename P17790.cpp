#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;cin >> a >> b;
	int day;
	double ans;
	if(a<=b){
		day=1;
		ans = a;
	}
	else if(0.9*a<=b){ 
		day = 3;
		ans = 0.9*a;
	}
	else if(0.8*a<=b){ 
		day = 4;
		ans = 0.8*a;
	}
	
	else if(0.7*a<=b){ 
		day = 5;
		ans = 0.7*a;
	}
	
	else if(0.6*a<=b){ 
		day = 6;
		ans = 0.6*a;
	}else{
		cout<<-1<<'\n';
		return 0;
	}
	
	cout << day<<" ";
	cout << fixed<<setprecision(2)<<ans<<'\n';

	return 0;
}
