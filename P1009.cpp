#include<iostream>
using namespace std;
//v


uint64_t calc(int n ){
	uint64_t ans = 1;
	while(n>1){
		ans *=n;
		n--;
	}
	return ans;
}
int main(){
	int n ;
	uint64_t ans = 0;
	cin>>n;
	for(int i =1;i<=n;i++){
		ans += calc(i);
	}
	cout<< ans;
	return 0;
}
