#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> input(m,0);
	for(int i = 0;i<m;i++){
		cin >> input[i];
	}
	std::sort(input.begin(),input.end());
	for(int i = 0;i<m;i++){
		cout<<input[i]<<" ";
	}
	
	
	
}


