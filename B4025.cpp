#include<iostream>
using namespace std;;
long long gcd(long long a,long long b){//9 12 12 9 9 3 3 0
	if(a%b==0){return b;}
	else{
		
	}return gcd(b,a%b);
	
}
int main(){
	long long a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
