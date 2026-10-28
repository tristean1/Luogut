#include<iostream>
using namespace std;

int main(){
	long long n;
	long long score = 0;
	cin>>n;
	while(n!=1){
		if(n%2==1){
			n = n * 3 +1;
		}else{
			n = n/2;
		}
		score ++;
	}
	cout<<score;
	return 0;
}
