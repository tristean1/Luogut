#include<bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> input(n);
	vector<int> ans(n);
	
	int in;
	int t_num = 0;
	for(int i = 0;i<n;i++){
		cin>>in;
		input[i] = in;
		
	}
	std::sort(input.begin(),input.end());
	for(int i = 0;i<n;i++){
		if(t_num==0){
			ans[0] = input[0];
			++t_num;
		}else if(input[i]!=ans[t_num-1]){
			ans[t_num] = input[i];
			++t_num;
		}
	}
	//cout.flush();
	cout<<t_num<<endl;
	for(int i =0;i<t_num;i++){
		cout<<ans[i]<<" ";
	}
	
	
}
