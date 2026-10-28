#include<bits/stdc++.h>
using namespace std;
void check_delta(vector<int> delta,int n){
	for(int i = 0;i < n;i++){
		cout<<delta[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,p;
	cin>>n>>p;
	vector<int> delta(n+1);
	vector<int> input(n);
	
	
	for(int i = 0; i < n;i++){
		cin>>input[i];
		
	}//差分
	delta[0] = input[0];
	for(int i = 1;i < n;i++){
		delta[i] = input[i] - input[i-1];
	}
	//check_delta(delta,n);
	int l,h,z;
	for(int i = 0; i <p;i++){
		cin>>l>>h>>z;
		delta[l-1] += z;
		
		delta[h] -= z;
	//check_delta(delta,n);
	}
	
	//cout<<endl;
	
	int sum = delta[0];
	int mi = sum;
	for(int i = 1;i<n;i++){
		sum += delta[i];
		if(sum < mi){
			mi = sum ;
		}
		
		//cout<<sum<<" ";
		
	
	
	}
	cout<<mi;
}
