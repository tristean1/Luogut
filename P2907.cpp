#include <iostream>
using namespace std;
int ans = 1;
void sep(int m,int k){
	//cout<<ans<<endl;
	
	//a + b = m
	//a + k = b 2a+k = m a=(m-k)/2 b = m=a
	//int a,b;
	if((m-k)%2!=0 or m<=k){
	//不能分
		return;
	}else{
		//继续分
		sep((m-k)/2,k) ; sep(m-(m-k)/2,k);
		ans++;
		
	}
	
}
int main(){
	int N,K;
	cin >> N>>K;
	sep(N,K);
	cout<<ans;
	return 0;
}

