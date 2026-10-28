#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,x;
	cin>>n>>x;
	vector<int> input(n);
	for(int i =0;i < n;i++){
		cin >> input[i];
	}
	long long eat = 0;
	int d = 0;
	for(int i  =1;i < n;i++){
		if(input[i] + input[i-1] > x){
			d = input[i] + input[i-1] -x;
			if(input[i] < d){
				
				input[i-1] -= d - input[i];
				input[i] = 0;
			}else{
				input[i] -= d;
			}
			eat += d;
		}
	}
	cout<<eat;
}
