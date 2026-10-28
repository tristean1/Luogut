#include <iostream>
using namespace std;

int main(){
	int n,x;
	int ans = 0;
	cin>>n>>x;
	int ty = 10;
	int k;
	for(int i = 1;i<=n;i++){
		k = i;
		while(k != 0){
			if(k % ty == x){
				ans++;
			}
			k = k/10;
		}
		
	}
	cout<<ans;
	return 0;
}
