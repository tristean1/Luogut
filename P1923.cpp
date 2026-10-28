#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
	int n,k;
	cin.tie(nullptr);
	cin>>n>>k;
	//cout<<"n"<<n<<" k "<<k<<endl;
	vector<long long> ans(n,0);
	for(int i =0;i<n;i++){
		cin>>ans[i];
	}
	
	nth_element(ans.begin(),ans.begin()+k,ans.end());
	cout<<ans[k];
	
}
