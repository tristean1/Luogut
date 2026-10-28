#include <iostream>
using namespace std;


int main(){
	unsigned long long * ans;
	int n ,turns;
	cin>>turns;
	ans = new unsigned long long[turns];		
	for (int i = n - 1; i > 1; i -= 2) {
		ans*= i;
	}
	
	for(int i =0;i<turns;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}

