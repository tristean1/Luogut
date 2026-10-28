#include<iostream>
using namespace std;

int main(){
	int m,n;//n头 m脚
	cin>>n>>m;
	//a+b=n;2a+4b=m
	//2b = m-2n 2a=4n-m
	int a,b;
	if((4*n-m)%2!=0 or (m - 2*n)%2 !=0){
		cout<<"No Solution"<<endl;
		return 0;
	}
	a = (4*n-m)/2;
	b = (m - 2*n)/2;
	if( a<0 or b<0){
		cout<<"No Solution"<<endl;
		return 0;
	}
	cout<<a<<" "<<b;
	return 0;
}
