#include<iostream>
using namespace std;

int main(){
	int k;
	cin>>k;
	double sn = 1;
	int n = 2;
	while(sn <= k){
		sn += (double)1/n;
		n++;
	}
	cout<<n-1;
}
