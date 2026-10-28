#include<iostream>
using namespace std;

int main(){
	int n = 1;
	cin>>n;
	int an[101];
	for(int i = 0;i<n;i++){
		cin>>an[i];
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		ans = 0;
		for(int j = 0;j<i;j++){
			if(an[j]<an[i]){
				ans++;
			}
		}
		
		cout<<ans<<" ";
	}
	return 0;
}
