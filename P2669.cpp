#include<iostream>
using namespace std;

int main(){
	int k;
	cin>>k;
	int ans  =0;
	int day1;
	int temp =0;
	while((1+temp)*temp/2<=k){
		temp++;
	}
	temp--;
	for(int i =1;i<=temp;i++){
		ans += i*i;
	}
	ans += (k - ((1+temp)*temp/2))*(1+temp);
	cout<<ans;
}
