#include<iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;      // 偶数（除 2 外）都不是质数
	
	for (int i = 3; i * i <= n; i += 2) {  // 只试奇数
		if (n % i == 0) return false;
	}
	return true;
}
int main(){
	int L;
	cin>>L;
	if(L<2){cout<<0;return 0;}
	int sn = 0;
	int trying = 2;
	int n  =0;
	do{
		if(isPrime(trying)){
			sn += trying;
			cout<<trying<<endl;
			n++;
			

		}
	trying++;
	}while(L>=sn+trying);
	cout<<n;
	
}
